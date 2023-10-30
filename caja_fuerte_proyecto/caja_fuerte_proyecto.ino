#include <Servo.h>
#include <LiquidCrystal.h>
#include <IRremote.h>
#define NUM_CHECKS 5

void(* resetFunc) (void) = 0; // Funcion para reiniciar el loop por software

int servoPin=4;
Servo myServo;

// Pines pantalla LCD
int rs=8;
int en=13;
int d4=9;
int d5=10;
int d6=11;
int d7=12;

int buzzerPin=7;
int IRpin=6;

int myCom;
int lcdPos;
bool check[NUM_CHECKS]={false};
bool allChecksPassed() {
  for (int i = 0; i < NUM_CHECKS; i++) {
    if (!check[i]) {
      return false;
    }
  }
  return true;
}

// Inputs que recibe la cerradura, solo se activa si se cumplen todos (no hay orden)
unsigned long IR_CODES[NUM_CHECKS] = {
  0xFF30CF,
  0xFF18E7,
  0xFF7A85,
  0xFF10EF,
  0xFF22DD,
};

IRrecv IR(IRpin);
decode_results cmd;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.clear();
  myServo.attach(servoPin);
  myServo.write(0);
  IR.enableIRIn();
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(IR.decode(&cmd)==0) {

  }
  lcd.setCursor(lcdPos, 0);
  lcdPos=lcdPos+1;
  delay(500);
  IR.resume();

  // Se definen los valores del control IR
  switch (cmd.value) {
  case 0xFF30CF:
    myCom=1;
  break;
  case 0xFF18E7:
    myCom=2;
  break;
  case 0xFF7A85:
    myCom=3;
  break;
  case 0xFF10EF:
    myCom=4;
  break;
  case 0xFF38C7:
    myCom=5;
  break;
  case 0xFF5AA5:
    myCom=6;
  break;
  case 0xFF42BD:
    myCom=7;
  break;
  case 0xFF4AB5:
    myCom=8;
  break;
  case 0xFF52AD:
    myCom=9;
  break;
  case 0xFF6897:
    myCom=0;
  break;
  case 0xFF22DD:
  break;
  default:
  resetFunc();
  break;
}
  Serial.println(myCom);
  lcd.print(myCom);
  digitalWrite(buzzerPin, HIGH);
  delay(50);
  digitalWrite(buzzerPin, LOW);
  for (int i = 0; i < NUM_CHECKS; i++) {
    if (cmd.value == IR_CODES[i]) {
      check[i] = true;
    }
  }

  if (cmd.value==0xFF22DD) {
    if (allChecksPassed()) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Abriendo...");
      myServo.write(90);
      delay(50);
      digitalWrite(buzzerPin, HIGH);
      delay(50);
      digitalWrite(buzzerPin, LOW);

    }
    else {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Clave incorrecta");
      delay(50);
      digitalWrite(buzzerPin, HIGH);
      delay(200);
      digitalWrite(buzzerPin, LOW);
      delay(2000);
      for (int i = 0; i < NUM_CHECKS; i++) {
        check[i] = false;
      }
      resetFunc();
    }
  }
}