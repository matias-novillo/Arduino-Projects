#include <Servo.h>
#include <LiquidCrystal.h>

int servoPin = 6;
int trigPin = 11;
int echoPin = 10;
float duration, distance;
Servo servo;
int servoPosition = 0;
int servoDirection = 1;
int buzzerPin = 5;
LiquidCrystal lcd(12, 13, 4, 3, 2, A2);



void setup() {
  // put your setup code here, to run once:
  servo.attach(servoPin);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(A1, OUTPUT);
  pinMode(A0, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  lcd.begin(16, 2);

}

bool getSafety() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  float distanceCM = (duration * 0.0343)/2;
  float distanceIN = distanceCM/2.54;
  delay(30);
  lcd.setCursor(0, 0);
  lcd.print("Distance: ");
  lcd.setCursor(0, 1);
  lcd.print(distanceCM, 0);
  lcd. print(" cm ");
  lcd.print(distanceIN, 1);
  lcd.print(" in   ");

  if(distanceCM >= 15) {
    return true;
  }

  else {
    return false;
  }
}

void loop() {
  bool safe = getSafety();

  if(safe == false) {
    digitalWrite(A0, LOW);
    digitalWrite(A1, HIGH);
    analogWrite(buzzerPin, 25);
    delay(75);
    analogWrite(buzzerPin, 0);
  }

  else {
    digitalWrite(A1, LOW);
    digitalWrite(A0, HIGH);
    if(servoDirection == 1) {
      servo.write(servoPosition);
      servoPosition += 3;
      if(servoPosition > 100) {
        servoPosition = 100;
        servoDirection = -1;
      }
      delay(20);
      safe = getDistance();
    }

    else if(servoDirection == -1) {
      servo.write(servoPosition);
      servoPosition -= 3;
      if(servoPosition < 0) {
        servoPosition = 0;
        servoDirection = 1;
      }
      delay(20);
      safe = getDistance();
    }
  }
}
