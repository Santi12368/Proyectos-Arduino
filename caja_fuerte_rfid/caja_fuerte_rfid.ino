#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

int redPin=2;
int bluePin=3;
int buttonPin=6;
int buttonVal;

int servoPin=5;
Servo myServo;

#define RST_PIN 9
#define SS_PIN  10
MFRC522 mfrc522(SS_PIN, RST_PIN);

byte LecturaUID[4];
byte Usuario1[4]= {0xA3, 0xDE, 0xEB, 0xFA}; // ID tag RFID 1
byte Usuario2[4]= {0xE3, 0xCE, 0x1A, 0xF5}; // ID tag RFID 2


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while (!Serial);
  SPI.begin();
  mfrc522.PCD_Init();
  mfrc522.PCD_DumpVersionToSerial();
  Serial.println(F("Scan PICC to see UID, SAK, type, and data blocks..."));
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(buttonPin, INPUT);
  myServo.attach(servoPin);
  myServo.write(0);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonVal=digitalRead(buttonPin);
  if (!mfrc522.PICC_IsNewCardPresent()) {
    return;
  }

  if (!mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  Serial.print("UID:");
  for (byte i=0; i <mfrc522.uid.size; i++) {
    if (mfrc522.uid.uidByte[i] < 0x10) {
      Serial.print(" 0");
    }
    else{
      Serial.print(" ");
    }
    Serial.print(mfrc522.uid.uidByte[i], HEX);
    LecturaUID[i]=mfrc522.uid.uidByte[i];
  }
  Serial.println("/t");

  if(comparaUID(LecturaUID, Usuario1)) {
    digitalWrite(bluePin, HIGH);
    digitalWrite(redPin, LOW);
    myServo.write(90);
    delay(2000);
    digitalWrite(bluePin, LOW);
    digitalWrite(redPin, LOW);
    myServo.write(0);
  }
  else{
    digitalWrite(redPin, HIGH);
    digitalWrite(bluePin, LOW);
    delay(2000);
    digitalWrite(bluePin, LOW);
    digitalWrite(redPin, LOW);
  }
  mfrc522.PICC_HaltA();
}

boolean comparaUID(byte lectura[], byte usuario[]) {
  for (byte i=0; i < mfrc522.uid.size; i++) {
    if(lectura[i] != usuario[i]) {
      return(false);
    }
  }
  return(true);
}