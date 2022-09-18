/*
  Arduino LSM9DS1 - Simple Gyroscope

  This example reads the gyroscope values from the LSM9DS1
  sensor and continuously prints them to the Serial Monitor
  or Serial Plotter.

  The circuit:
  - Arduino Nano 33 BLE Sense

  created 10 Jul 2019
  by Riccardo Rizzo

  This example code is in the public domain.
*/

#include <Arduino_LSM9DS1.h>

void setup() {
  Serial.begin(9600);
  while (!Serial);
  Serial.println("Started");

  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");
    while (1);
  }
  Serial.println("x1\tx2");
}

void loop() {
  float x1, y1, z1, x2, y2, z2;

  if (IMU.gyroscopeAvailable()) {
    IMU.readGyroscope(x1, y1, z1);
   // Serial.print("gyro =");
     Serial.print(x1);}
if (IMU.accelerationAvailable()) {
    IMU.readAcceleration(x2, y2, z2);
    //Serial.print("acce =");
    Serial.print('\t');
    Serial.println(x2);
  }
  }
