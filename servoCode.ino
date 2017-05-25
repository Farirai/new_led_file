//A = rotation in x-axis, B rotation in Z axis, degree of rotation between 0 and 180 
// eg: type "A180" for 180degrees rotation in x-axis 


#include <Servo.h>
Servo myservo1;
Servo myservo2;
int pos_x = 0; 
int pos_z = 0; 

void setup() {
 Serial.begin(9600);
 myservo1.attach(9);
 myservo2.attach(10);


 while (! Serial);
       Serial.println ("input"); 

}

void loop() {
     if (Serial.available()) {
        String in = Serial.readString();
        char dir = (char) in.charAt(0);
        String newPoss = in.substring(1);
        int newPos = newPoss.toInt();
       
        if (dir == 'A') {
        servo_x(newPos);
        
        }
        
        
        if (dir == 'B') {
        servo_z(newPos);
        }
        
     }
}

void servo_x(int fpos) {
     if (pos_x < fpos) {
        for (int i = pos_x; i < fpos; i ++) {   
            Serial.println (i);                              
            myservo1.write(i);             
            delay(15);                       
        }
     }
    else if (pos_x > fpos) {
        for (int i = pos_x; i > fpos; i -= 1) { 
            Serial.println (i);                                    
            myservo1.write(i);             
            delay(15);                       
          }
    }
       
    pos_x = fpos;   
} 


void servo_z(int fpos) {
    if  (pos_z < fpos) {
        for (int i = pos_z; i < fpos; i += 1) {                                  
            myservo2.write(i);             
            delay(15);                     
        }
    }
    if  (pos_z > fpos) {
        for (int i = pos_z; i > fpos; i -= 1) {                                  
            myservo2.write(i);             
            delay(15);                       
        }
    }
    pos_z = fpos;
}

