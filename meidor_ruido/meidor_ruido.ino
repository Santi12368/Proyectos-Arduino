int  ruidoPinA=A0;
int  ruidoPinD=3;
int  ruidoValD;
int  ledPin=2;
bool ledEstado;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ruidoPinA, INPUT);
  pinMode(ruidoPinD, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  ruidoValD=digitalRead(ruidoPinD);
  if(ruidoValD == HIGH){
    ledEstado = digitalRead(ledPin);
    digitalWrite(ledPin, !ledEstado);
    delay(1000);
  }
}
