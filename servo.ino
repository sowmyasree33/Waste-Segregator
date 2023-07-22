#include<Servo.h>
int servoPin=3;
const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
const int analogOutPin = 9; 
int sensorValue = 0;        // value read from the pot
int outputValue = 0; // Analog output pin that the LED is attached to
int pos=0;
Servo Servo1;
void setup(){
  Servo1.attach(servoPin);
    Serial.begin(9600);
}
void loop()
{
  sensorValue = analogRead(analogInPin);
  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\t output = ");
  Serial.println(outputValue);

  Servo1.write(0);
  delay(1000);
  if(sensorValue<300){
    Serial.println("DRY WASTE DETECTED");
  for (pos = 0; pos <= 180; pos += 1)         // goes from 0 degrees to 180 degrees


                                                                                // in steps of 1 degree

{                                                                             

    Servo1.write(pos);                                 // tell servo to go to position in variable 'pos'

 //delay(15);                                                   // waits 15ms for the servo to reach the position

  }
 }
 else{
 
Serial.println("WET WASTE DETECTED");
  for (pos = 180; pos >= 0; pos -= 1)           // goes from 180 degrees to 0 degrees

 {            

    Servo1.write(pos);                                  // tell servo to go to position in variable 'pos'

    delay(15);                                         // waits 15ms for the servo to reach the position

  }
 }
  /*if(sensorValue<950){
  Servo1.write(270);
  delay(1000);
  }
  else{
  Servo1.write(90);
  delay(1000);
  }*/
}
