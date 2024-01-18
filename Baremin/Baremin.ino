#include <CapacitiveSensor.h>

/*
 * CapitiveSense Library Demo Sketch
 * Paul Badger 2008
 * Uses a high value resistor e.g. 10M between send pin and receive pin
 * Resistor effects sensitivity, experiment with values, 50K - 50M. Larger resistor values yield larger sensor values.
 * Receive pin is the sensor pin - try different amounts of foil/metal on this pin
 */

 /*check out for important install info 
  *https://playground.arduino.cc/Main/CapacitiveSensor/
  */


CapacitiveSensor   cs_4_2 = CapacitiveSensor(4,2);        // 10M resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil if desired

void setup()                    
{
   cs_4_2.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
   Serial.begin(9600);
}

void loop()                    
{
    long start = millis();
    long total1 =  cs_4_2.capacitiveSensor(30);
 //Serial.print("hello"); 
  //  Serial.println(millis() - start);        // check on performance in milliseconds
 int sensorReading = total1;
    //Serial.println(total1);                  // print sensor output 1
     int thisPitch = map(sensorReading, 0, 1000, 0, 1500);
                                        // print sensor output 3
  // play the pitch:
  tone(9, thisPitch, 10);
  delay(1);        // delay in between reads for stability
   // delay(10);                             // arbitrary delay to limit data to serial port 
}
