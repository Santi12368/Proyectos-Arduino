#include <LiquidCrystal.h>
int rs=5;
int en=6;
int d4=9;
int d5=10;
int d6=11;
int d7=12;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int trigPin=8;
int echoPin=4;
int pingTravelTime;
float distance;
int buttonPin=7;
int buttonVal;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(16, 2); 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buttonPin, INPUT);
  digitalWrite(buttonPin, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(0, 0);
  lcd.print("Presione el");
  lcd.setCursor(0, 1);
  lcd.print("boton para medir:");
  buttonVal=digitalRead(buttonPin);
  Serial.println(buttonVal);
  while(buttonVal==1) {
    buttonVal=digitalRead(buttonPin);
  }

  if(buttonVal==0) {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(10);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    pingTravelTime=pulseIn(echoPin, HIGH);
     delay(25);
     distance=(pingTravelTime*0.034029)/2; // Velocidad del sonido, se divide entre 2 porque solo se quiere la distancia de ida
     Serial.print(distance);
     lcd.clear();
     lcd.setCursor(0, 0);
     lcd.print("Distancia:");
     lcd.setCursor(0, 1);
     lcd.print(distance);
     lcd.print(" cm.");
     delay(5000);
     lcd.clear();
  }
}