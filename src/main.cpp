#include <Arduino.h>
#include <Servo.h>

// An object for the servo
Servo servo;

// constant variables for pins
const int potPin = A8;
const int servoPin = 7;

// variables for values to store
int potVal = 0; // Stores the value collected by potentiometer
int servoVal = 0; // Copy and modify the potentiometer value

void setup(){
  // Set up the servo from the servo library
  servo.attach(servoPin); // Set it to the servo pin
}

void loop(){
  potVal = analogRead(potPin); // Read what value the potentiometer has

  servoVal = potVal; // Make a copy of the potentiometer value so we can safely modify it
  servoVal = map(servoVal, 0, 1023, 180, 0); // Remap the copied values so they make sense for what the servo can do. (from 0 def to 180 deg)

  servo.write(servoVal); // Finally write our modified values to the servo

  delay(15); // Short delay because why run as fast as possible?
}