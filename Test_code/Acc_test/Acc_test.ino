#include <Arduino_LSM9DS1.h>
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while (!Serial);
  Serial.println("Started");
  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");
    while (1);
  }
  Serial.print("Accelerometer sample rate = ");
  Serial.print(IMU.accelerationSampleRate());
  Serial.println(" Hz");
  Serial.println();
  Serial.println("Acceleration in g's");
  Serial.println("X\tY\tZ");
}
void loop() {
  // put your main code here, to run repeatedly:
  float x, y, z,degreesY;

  if (IMU.accelerationAvailable()) {
    IMU.readAcceleration(x, y, z);
    if (x > 0.1) {
      x = 100 * x;
      Serial.println("running");
    }
    if (x < -0.1) {
      Serial.println("Stop");
    }
    if (y > 0.1) {
      y = 100 * y;
      degreesY = map(y, 0, 97, 0, 90);
      if (degreesY > 30) {
        Serial.println("turn left");
      }
    }
    if (y < -0.1) {
      y = 100 * y;
      degreesY = map(y, 0, -100, 0, 90);
      if (degreesY > 30) {
        Serial.println("turn right");
      }
    }
  }delay(100);
}
