int lightPin=A0;
int lightVal;
int dv=250;
int redLED=8;
int blueLED=9;

void setup() {
  // put your setup code here, to run once:
  pinMode(lightPin, INPUT);
  Serial.begin(9600);
  pinMode(redLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  lightVal=analogRead(lightPin);
  Serial.println(lightVal);
  delay(dv);

  while(lightVal<=300) {
    digitalWrite(redLED, HIGH);
    digitalWrite(blueLED, LOW);
    lightVal=analogRead(lightPin);
    Serial.println(lightVal);
    delay(dv);
  }

  while(lightVal>=300) {
    digitalWrite(redLED, LOW);
    digitalWrite(blueLED, HIGH);
    lightVal=analogRead(lightPin);
    Serial.println(lightVal);
    delay(dv);
  }
  }
