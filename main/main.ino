#include <Arduino_LSM9DS1.h>
#include "grove_two_rgb_led_matrix.h"
GroveTwoRGBLedMatrixClass matrix;
float x, y, z;
int temp;
void waitForMatrixReady() {
  delay(1000);
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

  } if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");
    while (1);
  }
  void setOneShotMode();
}
void loop() {
  // put your main code here, to run repeatedly:
acce();
}
void acce(){
    IMU.readAcceleration(x, y, z);
    if (x<temp){
      matrix.displayColorBlock(0xff0000, 0, true);}
    }
