#include <Arduino_LSM9DS1.h>
#include "grove_two_rgb_led_matrix.h"
GroveTwoRGBLedMatrixClass matrix;
float x1,y, z;
volatile float x;
int temp;
void waitForMatrixReady() {
  delay(1000);
}
void acce() {
  Serial.println(x);
  // IMU.readAcceleration(x, y, z);
  matrix.displayColorBlock(0xff0000, 0, true);
}
void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  Serial.begin(9600);
  uint16_t VID = 0;
  VID = matrix.getDeviceVID();
  if (VID != 0x2886) {
    Serial.println("Can not detect led matrix!!!");
    while (1);
  }
  Serial.println("Matrix init success!!!");

  matrix.displayColorBlock(0xff0000, 0, true);
  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");
    while (1);
  }
  //void setOneShotMode();
  if (IMU.accelerationAvailable()) {
    IMU.readAcceleration(x1, y, z);
    x=x1;
    Serial.println(x);
  }
  attachInterrupt((int)x, acce, CHANGE);
}
void loop() {
  // put your main code here, to run repeatedly:
  matrix.displayColorBlock(0x00ff00, 0, true);
 if (IMU.accelerationAvailable()) {
   // IMU.readAcceleration(x, y, z);
    // Serial.println(x);
    // Serial.print('\t');
 // }
  delay(4);
}
