const byte numPins = 8;


//the pins connected to the LEDs
byte pins[] = {3, 5, 6, 7, 8, 9, 10, 11};
              
//later updated to be the bit of the letter from the serial monitor
byte onPins;


void setup() {
    Serial.begin(9600);
  
    //set all pin as output
    for (int ii = 0; ii <= 7; ii++) {
    
       pinMode(pins[ii],OUTPUT);
       digitalWrite(pins[ii],LOW);
    }
}

void loop() {

    //read the letter from serial monitor, update onPins
    while(!Serial.available()); 
    byte num = Serial.read(); 
    /
    Serial.print(num);
    
    //turn on the corresponding pins for the bits represented by 1 
    //else keep the rest off
   for (int ii = 0; ii <= 7; ii++) {
       onPins = bitRead(num, ii);
       Serial.print(onPins);
       if (onPins & B1) {
          digitalWrite(pins[ii],HIGH);
       }
       else {
           digitalWrite(pins[ii],LOW);
       }
   }
  
}

