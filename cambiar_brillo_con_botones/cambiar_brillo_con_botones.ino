int buttonPin1=8;
int buttonPin2=9;
int LEDPin=10;
int buzzer=11;
int buttonVal1;
int buttonVal2;
int LEDbrightness=0;
int dt=100;
int buzzerDelay=50;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(LEDPin, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonVal1=digitalRead(buttonPin1);
  buttonVal2=digitalRead(buttonPin2);
  Serial.print("Button 1= ");
  Serial.print(buttonVal1);
  Serial.print(", ");
  Serial.print("Button 2= ");
  Serial.println(buttonVal2);
  delay(dt);
  
  if (buttonVal1==0) {
    LEDbrightness=LEDbrightness-51;
    analogWrite(buzzer, 128);
    delay(buzzerDelay);
    digitalWrite(buzzer, LOW);
  }
  if (buttonVal2==0) {
    LEDbrightness=LEDbrightness+51;
    analogWrite(buzzer, 128);
    delay(buzzerDelay);
    digitalWrite(buzzer, LOW);
  }
  if (LEDbrightness>255) {
    LEDbrightness=255;
  }
  if (LEDbrightness<0) {
    LEDbrightness=0;
  }
  analogWrite(LEDPin, LEDbrightness);
}
