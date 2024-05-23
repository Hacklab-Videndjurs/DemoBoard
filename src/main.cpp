#include "servoDemo.h"
#include "distanceDemo.h"

void setup(){
  Serial.begin(9600); // To debug to serial port

  ServoDemo::Initialize(A8, 7); // potentiometer pin & servo pin
  distanceDemo::Initialize(3, 4); // ultrasonic trigger pin & ultrasonic echo pin
}

void loop(){
  ServoDemo::Update();
  distanceDemo::Update();
}