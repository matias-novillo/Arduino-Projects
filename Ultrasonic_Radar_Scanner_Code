/*
Ultrasonic Radar Scanner

Uses an HC-SR04 ultrasonic sensor mounted on a servo motor
to continuously scan an area. When an object is detected
within the safety distance, the scanner stops and activates
a warning buzzer as well as an LED.

Hardware:
- Arduino Uno
- HC-SR04 ultrasonic sensor
- Servo motor
- LCD1602 display
- LEDs
- Buzzer
*/

#include <Servo.h>
#include <LiquidCrystal.h>

// Hardware pin assignments
const int servoPin = 6;
const int trigPin = 11;
const int echoPin = 10;
const int buzzerPin = 5;
const int greenLedPin = A0;
const int redLedPin = A1;

// Servo movement settings
const int servoMaxAngle = 100;
const int servoMinAngle = 0;
const int servoStep = 3;
int servoPosition = 0;
int servoDirection = 1; // 1= increasing angle, -1 = decreasing angle

const int safeDistance = 15; // Minimum safe distance before triggering (cm)
float duration;
float distanceCM;
float distanceIN;

Servo servo;
// LCD pins: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 13, 4, 3, 2, A2);



void setup() {
  // put your setup code here, to run once:
  servo.attach(servoPin);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  lcd.begin(16, 2);
}

// Measures distance, updates LCD, and returns whether the area is safe or there is an object
bool checkDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Send a 10 microsecond trigger pulse to start the ultrasonic measurement
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure how long the returning echo pulse stays HIGH
  duration = pulseIn(echoPin, HIGH);
  // Convert travel time into distance using speed of sound
  distanceCM = (duration * 0.0343)/2;
  distanceIN = distanceCM/2.54;
  delay(30);
  lcd.setCursor(0, 0);
  lcd.print("Distance: ");
  lcd.setCursor(0, 1);
  lcd.print(distanceCM, 0);
  lcd. print(" cm ");
  lcd.print(distanceIN, 1);
  lcd.print(" in   ");

  if(distanceCM >= safeDistance) {
    return true;
  }

  else {
    return false;
  }
}

void loop() {
  bool safe = checkDistance();

  if(safe == false) {
    digitalWrite(greenLedPin, LOW);
    digitalWrite(redLedPin, HIGH);
    // Beeps the buzzer
    analogWrite(buzzerPin, 25);
    delay(75);
    analogWrite(buzzerPin, 0);
  }

  else {
    digitalWrite(redLedPin, LOW);
    digitalWrite(greenLedPin, HIGH);
    if(servoDirection > 0) {
      servo.write(servoPosition);
      // Move servo a few degrees each loop to create a scanning motion
      servoPosition += servoStep;
      if(servoPosition > servoMaxAngle) {
        servoPosition = servoMaxAngle;
        servoDirection = -1;
      }
      delay(20);
      safe = checkDistance();
    }

    else {
      servo.write(servoPosition);
      servoPosition -= servoStep;
      if(servoPosition < servoMinAngle) {
        servoPosition = servoMinAngle;
        servoDirection = 1;
      }
      delay(20);
      safe = checkDistance();
    }
  }
}
