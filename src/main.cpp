#include "servoDemo.h"

void setup(){
  Serial.begin(9600); // To debug to serial port

  ServoDemo::Initialize(A8, 7);
}

void loop(){
  ServoDemo::Update();
}