#include <LiquidCrystal.h>
int rs=7;
int en=8;
int d4=9;
int d5=10;
int d6=11;
int d7=12;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int lcdPos;
#include <IRremote.h>
int IRpin=6;
IRrecv IR(IRpin);
decode_results cmd;

void(* resetFunc) (void) = 0;
int myCom;
String operation;
int firstNumber;
int secondNumber;
int total;


void setup() {
  Serial.begin(9600);
  IR.enableIRIn();
  lcd.begin(16, 2);
  lcd.clear();
}

void loop() {
  while(IR.decode(&cmd)==0) {

  }
  lcd.setCursor(lcdPos, 0);
  lcdPos=lcdPos+1;
  Serial.println(cmd.value, HEX);
  delay(500);
  IR.resume();
  if (cmd.value==0xFF30CF) {
    myCom=1;
    Serial.println(myCom);
    lcd.print(myCom);
  }
  if (cmd.value==0xFF18E7) {
    myCom=2;
    Serial.println(myCom);
    lcd.print(myCom);
  }
  if (cmd.value==0xFF7A85) {
    myCom=3;
    Serial.println(myCom);
    lcd.print(myCom);
  }
  if (cmd.value==0xFF10EF) {
    myCom=4;
    Serial.println(myCom);
    lcd.print(myCom);
  }
  if (cmd.value==0xFF38C7) {
    myCom=5;
    Serial.println(myCom);
    lcd.print(myCom);
  }
  if (cmd.value==0xFF5AA5) {
    myCom=6;
    Serial.println(myCom);
    lcd.print(myCom);
  }
  if (cmd.value==0xFF42BD) {
    myCom=7;
    Serial.println(myCom);
    lcd.print(myCom);
  }
  if (cmd.value==0xFF4AB5) {
    myCom=8;
    Serial.println(myCom);
    lcd.print(myCom);
  }
  if (cmd.value==0xFF52AD) {
    myCom=9;
    Serial.println(myCom);
    lcd.print(myCom);
  }
  if (cmd.value==0xFF6897) {
    myCom=0;
    Serial.println(myCom);
    lcd.print(myCom);
  }

  firstNumber=myCom;
  if (cmd.value==0xFF906F) {
    operation="+";
    Serial.println(operation);
    lcd.print(operation);
  }
  if (cmd.value==0xFFA857) {
    operation="-";
    Serial.println(operation);
    lcd.print(operation);
  }
  if (cmd.value==0xFF22DD) {

    Serial.println(total);
    lcd.print(total);
  }
  if (cmd.value==0xFFA25D) {
  resetFunc();
  }
  
}