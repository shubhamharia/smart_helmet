
#include <Arduino_LSM9DS1.h>
#include "grove_two_rgb_led_matrix.h"
GroveTwoRGBLedMatrixClass matrix;
float x, y, z;
int degreesY = 0;
void waitForMatrixReady() {
  delay(1000);
}
void setup() {
  Wire.begin();
  Serial.begin(9600);
  while (!Serial);
  Serial.println("Started");
  uint16_t VID = 0;
  VID = matrix.getDeviceVID();
  if (VID != 0x2886) {
    Serial.println("Can not detect led matrix!!!");
    while (1);
  }
  Serial.println("Matrix init success!!!");

  matrix.displayColorBlock(0x000000, 0, true);
  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");
    while (1);
  }

  Serial.print("Accelerometer sample rate = ");
  Serial.print(IMU.accelerationSampleRate());
  Serial.println("Hz");
}

void loop() {

  if (IMU.accelerationAvailable()) {
    IMU.readAcceleration(x, y, z);

  }

  if (x > 0.1) {
 matrix.displayColorBlock(0x00ff00, 0, true);
  }
  if (x < -0.1) {
 matrix.displayColorBlock(0xff0000, 0, true);
  }
  if (y > 0.1) {
    y = 100 * y;
    degreesY = map(y, 0, 97, 0, 90);
    if (degreesY>30){
       matrix.displayColorBlock(0xff00ff, 0, true);}   
  }
  if (y < -0.1) {
    y = 100 * y;
    degreesY = map(y, 0, -100, 0, 90);
 if (degreesY>30){
       matrix.displayColorBlock(0xffff00, 0, true);;
  }}
  delay(100);
}
