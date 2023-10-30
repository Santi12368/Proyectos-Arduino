#include <Servo.h>

Servo myServo;

int potPin = A0; // Potenciometro
int val;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myServo.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(potPin);
  Serial.print(val);
  Serial.print(" ");
  val = map(val, 0, 1023, 0, 180); // Convierte el valor analogico del potenciometro en los grados del servo
  myServo.write(val);
  Serial.print(val);
  Serial.println();
  delay(50);
}