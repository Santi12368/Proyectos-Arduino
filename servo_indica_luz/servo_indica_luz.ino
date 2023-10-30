#include <Servo.h>
int lightVal;
int lightPin=A0;
int dt=250;
int angle;
int servoPin=9;
Servo myServo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(lightPin, INPUT);
  pinMode(servoPin, INPUT);
  myServo.attach(servoPin);
}

void loop() {
  // put your main code here, to run repeatedly:
  lightVal=analogRead(lightPin);
  Serial.println(lightVal);
  delay(dt);
  angle=(58./93.)*lightVal+58.*850./93.; // La formula depende de los niveles de luz del ambiente
  myServo.write(angle);
}
