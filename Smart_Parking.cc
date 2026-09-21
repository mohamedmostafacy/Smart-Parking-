#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo gateServo;

const int irEnter = 2;
const int irExit = 3;
const int servoPin = 9;

int totalSlots = 4;
int availableSlots = 4;

void setup() {
  pinMode(irEnter, INPUT);
  pinMode(irExit, INPUT);

  gateServo.attach(servoPin);
  gateServo.write(90);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print(" Smart Parking ");
  delay(2000);
  lcd.clear();
}

void loop() {
  updateLCD();

  if (digitalRead(irEnter) == LOW && availableSlots > 0) {
    openGate();
    availableSlots--;
    updateLCD();

    while (digitalRead(irEnter) == LOW);
    delay(1000);
    closeGate();
  }
  else if (digitalRead(irEnter) == LOW && availableSlots == 0) {
    lcd.setCursor(0, 1);
    lcd.print(" Parking is FULL ");
    delay(2000);
    lcd.clear();
  }

  if (digitalRead(irExit) == LOW && availableSlots < totalSlots) {
    openGate();
    availableSlots++;
    updateLCD();

    while (digitalRead(irExit) == LOW);
    delay(1000);
    closeGate();
  }
}

void openGate() {
  gateServo.write(0);
  delay(1000);
}

void closeGate() {
  gateServo.write(90);
  delay(500);
}

void updateLCD() {
  lcd.setCursor(0, 0);
  lcd.print("Slots Left: ");
  lcd.print(availableSlots);
  lcd.print("    ");

  if (availableSlots == 0) {
    lcd.setCursor(0, 1);
    lcd.print("     FULL!      ");
  } else {
    lcd.setCursor(0, 1);
    lcd.print("    Welcome     ");
  }
}