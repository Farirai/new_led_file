#include <AFMotor.h>

AF_DCMotor motor(1); //using M1


//pins connected to wall switch
int switchPin1 = 2;
int switchPin2 = 3;

//ints keeping track of position
int button1State = 0;  
int button2State = 0;  

void setup() {
  // turn on motor
  Serial.begin(9600);

  //set switches as outputs
  pinMode(switchPin1, INPUT);
  pinMode(switchPin2, INPUT);

  //request serial input
  while (! Serial);
        Serial.println ("direction 1 = forward, 0 backwards "); 
  }


void loop() {
  //get serial input
  if (Serial.available()) {
     int speed = Serial.parseInt();
     Serial.println(speed);
     dc(speed);
  }

}


//update position of motor
void dc(int speed) {
     if (speed == 1 ) {
        motor.run(FORWARD);
        button1State = digitalRead(switchPin1);
        
        while (button1State != 1) {
           motor.setSpeed(40);  
           delay(10);
           Serial.println(40);
           button1State = digitalRead(switchPin1);    
        } 
        motor.run(RELEASE);
        delay(100);
    }


 
   if ( speed == 0) { 
      int i = 0;
      motor.run(BACKWARD);
      button2State = digitalRead(switchPin2);
      while (button2State != 1) {
            motor.setSpeed(40); 
            Serial.println(40);
            delay(10);
            button2State = digitalRead(switchPin2);
          
      } 
      motor.run(RELEASE);
      delay(100);
   }
    
}






