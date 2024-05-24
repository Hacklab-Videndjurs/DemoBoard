#ifndef DISTANCE_DEMO_H
#define DISTANCE_DEMO_H

#include "Arduino.h"
#include "LiquidCrystal_I2C.h"

/*
    ----------------------------------------

    This example will include both an ultra sonic range finder and an lcd display to convay the distance information

    ----------------------------------------
*/

namespace distanceDemo{
    LiquidCrystal_I2C lcd(0x27, 16, 2); // 0x27 = lcd address | 16 = horizontal chars | 2 = lines

    int uTriggerPin = 0; // This is the pin for the ultrasonic trigger pin
    int uEchoPin = 0; // This is the pin for the ultrasonic echo pin

    static long duration, cm;

    void Initialize(const int& _ultraTriggerPin, const int& _ultraEchoPin){
        uTriggerPin = _ultraTriggerPin;
        uEchoPin = _ultraEchoPin;

        pinMode(uTriggerPin, OUTPUT);
        pinMode(uEchoPin, INPUT);

        lcd.init();
        lcd.backlight();
    }

    void DisplayUpdate(){
        lcd.clear();
        lcd.print(cm);
        lcd.print(" cm");
    }

    void UltrasonicUpdate(){
        // Clear the trigger ping
        digitalWrite(uTriggerPin, LOW);
        delayMicroseconds(2);

        // Set trigger pin to HIGH for 10 micro seconds
        digitalWrite(uTriggerPin, HIGH);
        delayMicroseconds(10);
        digitalWrite(uTriggerPin, LOW);

        // Read the echo pin. It returns the time in ms from last pulse
        duration = pulseIn(uEchoPin, HIGH);

        // Calculate the recorded distance
        cm = duration * 0.034f / 2;

        Serial.print("cm dist: ");
        Serial.println(cm);
    }

    void Update(){
        UltrasonicUpdate();
        DisplayUpdate();
    }
}

#endif