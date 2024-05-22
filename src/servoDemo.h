#ifndef SERVO_DEMO_H // C header guards is required for not including the project multible times. Very much required
#define SERVO_DEMO_H

#include <Arduino.h>
#include <Servo.h>

namespace ServoDemo{
  // An object for the servo
  Servo servo;

  // variables for pins
  int potPin = 0;
  int servoPin = 0;

  // variables for values to store
  int potVal = 0; // Stores the value collected by potentiometer
  int servoVal = 0; // Copy and modify the potentiometer value

  void Initialize(const int& _potentiometerPin, const int& _servoPin){
    // Set the pins for servo and potentiometer
    potPin = _potentiometerPin;
    servoPin = _servoPin;
    
    // Set up the servo from the servo library
    servo.attach(servoPin); // Set it to the servo pin
  }

  void Update(){
    potVal = analogRead(potPin); // Read what value the potentiometer has

    Serial.println(potVal);

    if(potVal < 50){ // debuffer to the potentiometer as when it gets too low it fluctuates between 0 and 50
      potVal = 50;
    }
    else{
      servoVal = potVal; // Make a copy of the potentiometer value so we can safely modify it
      servoVal = map(servoVal, 0, 1023, 180, 0); // Remap the copied values so they make sense for what the servo can do. (from 0 def to 180 deg)
      // What the map does is make 0 = 180 and 1023 = 0 and then the values between should be placed correctly by arduino

      servo.write(servoVal); // Finally write our modified values to the servo
    }

    delay(15); // Short delay because why run as fast as possible?
  }
}

#endif