int redLED=8;
int buttonPin=12;
int buttonRead;
int dv=50;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(redLED, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonRead=digitalRead(buttonPin);
  Serial.println(buttonRead);
  delay(dv);
  if(buttonRead==1) {
    digitalWrite(redLED, LOW);
  }
  if(buttonRead==0) {
    digitalWrite(redLED, HIGH);
  }

}
