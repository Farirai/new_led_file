/**
 *  *
 * 	http://www.gnu.org/licenses/lgpl-3.0.txt
 */
package org.sintef.jarduino.examples.basic;

import org.sintef.jarduino.DigitalPin;
import org.sintef.jarduino.JArduino;
import org.sintef.jarduino.InvalidPinTypeException;
import org.sintef.jarduino.comm.Serial4JArduino;
import java.util.Arrays;
/*


This example code is in the public domain.
 */

public class Controlling_LEDs extends JArduino {
//public static final int numPins = 8;
public static int[] intArray = new int[8];

 DigitalPin[] pins = {DigitalPin.PIN_2, DigitalPin.PIN_3, DigitalPin.PIN_4, DigitalPin.PIN_5,
                      DigitalPin.PIN_6, DigitalPin.PIN_7, DigitalPin.PIN_8, DigitalPin.PIN_9};

 //the pins connected to the LEDs
 
 
    public Controlling_LEDs(String port) {
        super(port);
    }

    @Override
    protected void setup() throws InvalidPinTypeException {
    System.out.println("actually reached the right loop");    
  for (int ii = 0; ii <= 7; ii++) {
     pinMode(pins[ii],OUTPUT);
     digitalWrite(pins[ii],LOW);
   }
    }

   
    @Override
    protected void loop() throws InvalidPinTypeException {
     
        
for (int ii = 0; ii <= 7; ii++) {
     //pinMode(pin5, OUTPUT);
     pinMode(pins[ii],OUTPUT);
   }  

//done setting up
    for (int ii = 0; ii <= 7; ii++) {
      if (intArray[ii] == 1 ) {
       digitalWrite(pins[ii],HIGH);
      }
   } 
    }
        
        
        
        
        
    
 
    public static void main(String[] args) {
        
        String serialPort;
        serialPort = Serial4JArduino.selectSerialPort();
        
        //for when passed in as a string of bytes
        
        
        
        //for when passed in as an int
        int inputin = Integer.parseInt( args [0] );
        
        System.out.println(inputin);
        
       //convert to respective string
       //String inpuut = Integer.toBinaryString( inputin);
       String inpuut = String.format("%8s", Integer.toBinaryString(inputin)).replace(" ", "0");
       
       System.out.println(inpuut);
       
       //convert to array
       int strLength = inpuut.length();
       if(strLength != 8) {
       System.out.println("Not a valid length");
       } else {
       for(int i = 0 ;i < 8; i++) {
       if (!Character.isDigit(inpuut.charAt(i))) {
       System.out.println("Contains an invalid digit");
       break;
       }
      intArray[i] = Integer.parseInt(String.valueOf(inpuut.charAt(i)));
      System.out.println(Arrays.toString(intArray));
        }
      }
      
  
        JArduino arduino = new Controlling_LEDs(serialPort);
        
        
       arduino.runArduinoProcess();
        
    }
   
}
