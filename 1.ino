#include "deneyap.h"
#include <ESP32Servo.h>

const int trigPin = D8;
const int echoPin = D9;


long duration;
int distance;
Servo myServo;


void setup() {

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(115200);
  myServo.attach(D12);

}


void loop() {



  for (int i = 15; i <= 165; i++) {
    myServo.write(i);
    delay(30);
    distance = calculateDistance();

    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");
  }



  for (int i = 165; i > 15; i--) {
    myServo.write(i);
    delay(30);
    distance = calculateDistance();
    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");
  }
}



int calculateDistance() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  return distance;

}
