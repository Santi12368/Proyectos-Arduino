int tiltPin=2;
int tiltVal;
int redPin=8;
int bluePin=9;
int dt=50;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(tiltPin, INPUT);
  digitalWrite(tiltPin, HIGH);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  tiltVal=digitalRead(tiltPin);
  Serial.println(tiltVal);
  delay(dt);
  if (tiltVal==1) {
    digitalWrite(bluePin, HIGH);
    digitalWrite(redPin, LOW);
  }
  else {
    digitalWrite(bluePin, LOW);
    digitalWrite(redPin, HIGH);
  }
}
