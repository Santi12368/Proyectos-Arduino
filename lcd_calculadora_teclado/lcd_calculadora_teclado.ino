#include <LiquidCrystal.h>
int rs=7;
int en=8;
int d4=9;
int d5=10;
int d6=11;
int d7=12;

float firstNum;
float secNum;
float answer;
String op;


LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(16, 2);
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Escriba su");
  lcd.setCursor(0, 1);
  lcd.print("primer numero:");
  while (Serial.available()==0) {

  }
  firstNum=Serial.parseFloat();
  Serial.print("primer numero= ");
  Serial.println(firstNum);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Escriba su");
  lcd.setCursor(0, 1);
  lcd.print("segundo numero:");
  while (Serial.available()==0) {

  }
  secNum=Serial.parseFloat();
  Serial.print("segundo numero= ");
  Serial.println(secNum);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Suma o resta?");
  while (Serial.available()==0) {

  }
  op=Serial.readString();
  Serial.print("operacion= ");
  Serial.println(op);

  if (op=="suma") {
    answer=firstNum+secNum;
  }
  if (op=="resta") {
    answer=firstNum-secNum;
  }
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Resultado:");
  lcd.setCursor(0, 1);
  lcd.print(answer);
  Serial.print("resultado= ");
  Serial.println(answer);
  delay(10000);
}
