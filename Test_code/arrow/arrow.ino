
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  for (byte i = 2; i <= 13; i++)
  {
    pinMode(i, OUTPUT);
  }
  pinMode(A0, INPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  Serial.begin(9600);
  Serial.println("enter '1'to turn right");
  Serial.println("enter '2'to turn left");
  Serial.println("enter '3'to turn stop");
  Serial.println("enter '0'to turn run");
}
int t;
byte value, temp;
void loop() {

  if (Serial.available() > 0) {
    value = Serial.read();
  }
  switch (value) {
    case 49: right();
      break;
    case 50: left();
      break;
    case 51: wait();
      break;
    case 10: value = temp;
      break;
    default:
      t = map(analogRead(A0), 0, 1028, 0, 2);
      if (t == 0) {
        smile();
      } else {
        sad();
      } break;
  } temp = value;
}
void right()
{
  digitalWrite(2, 0); digitalWrite(3, 1); digitalWrite(4, 0); digitalWrite(5, 1);
  digitalWrite(6, 1); digitalWrite(7, 0); digitalWrite(8, 1); digitalWrite(9, 1);
  digitalWrite(10, 0); digitalWrite(11, 1); digitalWrite(12, 0); digitalWrite(13, 0);
  digitalWrite(A1, 1); digitalWrite(A2, 1); digitalWrite(A3, 0);
  delay(2);
  digitalWrite(2, 1); digitalWrite(3, 0); digitalWrite(12, 1); digitalWrite(A3, 1);
  delay(2);
  digitalWrite(3, 1); digitalWrite(7, 1); digitalWrite(13, 1); digitalWrite(A1, 0);
  delay(2);
  digitalWrite(4, 1); digitalWrite(10, 1); digitalWrite(11, 0); digitalWrite(A1, 1);
  delay(2);
  digitalWrite(4, 0); digitalWrite(5, 0); digitalWrite(7, 0); digitalWrite(8, 0);
  digitalWrite(9, 0); digitalWrite(10, 0); digitalWrite(11, 1); digitalWrite(13, 0);
  digitalWrite(A2, 0);
  delay(2);
}
void left()
{
  digitalWrite(2, 1); digitalWrite(3, 1); digitalWrite(4, 0); digitalWrite(5, 0);
  digitalWrite(6, 1); digitalWrite(7, 0); digitalWrite(8, 1); digitalWrite(9, 1);
  digitalWrite(10, 0); digitalWrite(11, 1); digitalWrite(12, 0); digitalWrite(13, 0);
  digitalWrite(A1, 1); digitalWrite(A2, 1); digitalWrite(A3, 0);
  delay(2);
  digitalWrite(5, 1); digitalWrite(8, 0); digitalWrite(12, 1); digitalWrite(A3, 1);
  delay(2);
  digitalWrite(8, 1); digitalWrite(9, 0); digitalWrite(7, 1); digitalWrite(13, 1);
  delay(2);
  digitalWrite(9, 1); digitalWrite(A2, 0); digitalWrite(4, 1); digitalWrite(10, 1);
  delay(2);
  digitalWrite(11, 0); digitalWrite(A1, 0); digitalWrite(3, 0); digitalWrite(2, 0);
  digitalWrite(A2, 1); digitalWrite(4, 0); digitalWrite(7, 0); digitalWrite(10, 0);
  digitalWrite(13, 0);
  delay(2);
}
void wait() {
  digitalWrite(2, LOW); digitalWrite(3, LOW); digitalWrite(4, HIGH); digitalWrite(5, LOW);
  digitalWrite(6, HIGH); digitalWrite(7, HIGH); digitalWrite(8, LOW); digitalWrite(9, LOW);
  digitalWrite(10, HIGH); digitalWrite(11, LOW); digitalWrite(12, HIGH); digitalWrite(13, HIGH);
  digitalWrite(A1, LOW); digitalWrite(A2, LOW); digitalWrite(A3, HIGH);
  delay(1000);
}
void smile() {
  digitalWrite(2, 0); digitalWrite(3, 1); digitalWrite(4, 1); digitalWrite(5, 0);
  digitalWrite(6, 1); digitalWrite(7, 1); digitalWrite(8, 1); digitalWrite(9, 1);
  digitalWrite(10, 1); digitalWrite(11, 1); digitalWrite(12, 1); digitalWrite(13, 1);
  digitalWrite(A1, 1); digitalWrite(A2, 1); digitalWrite(A3, 1);
  delay(2);
  digitalWrite(2, 1); digitalWrite(5, 1); digitalWrite(3, 0); digitalWrite(8, 0);
  digitalWrite(6, 0); digitalWrite(7, 0); digitalWrite(12, 0); digitalWrite(13, 0);
  digitalWrite(A3, 0);
  delay(2);
  digitalWrite(3, 1); digitalWrite(8, 1); digitalWrite(9, 0); digitalWrite(A1, 0);
  digitalWrite(A3, 1); digitalWrite(12, 1);
  delay(2);
  digitalWrite(9, 1); digitalWrite(A1, 1); digitalWrite(A2, 0); digitalWrite(11, 0);
  digitalWrite(7, 1); digitalWrite(A3, 0); digitalWrite(12, 0);
  delay(2);
}
void sad() {
  digitalWrite(2, 0); digitalWrite(3, 1); digitalWrite(4, 1); digitalWrite(5, 0);
  digitalWrite(6, 1); digitalWrite(7, 1); digitalWrite(8, 1); digitalWrite(9, 1);
  digitalWrite(10, 1); digitalWrite(11, 1); digitalWrite(12, 1); digitalWrite(13, 1);
  digitalWrite(A1, 1); digitalWrite(A2, 1); digitalWrite(A3, 1);
  delay(2);
  digitalWrite(2, 1); digitalWrite(5, 1); digitalWrite(3, 0); digitalWrite(8, 0);
  digitalWrite(6, 0); digitalWrite(7, 0); digitalWrite(12, 0); digitalWrite(13, 0);
  digitalWrite(A3, 0);
  delay(2);
  digitalWrite(3, 1); digitalWrite(8, 1); digitalWrite(9, 0);
  digitalWrite(A3, 1); digitalWrite(7, 1);
  delay(2);
  digitalWrite(9, 1); digitalWrite(A1, 0); digitalWrite(7, 0);
  delay(2);
  digitalWrite(A1, 1); digitalWrite(A2, 0); digitalWrite(A3, 0); digitalWrite(7, 0);
  digitalWrite(12, 1);
  delay(2);
  digitalWrite(11, 0); digitalWrite(A2, 1); digitalWrite(7, 1);
  delay(2);
}
