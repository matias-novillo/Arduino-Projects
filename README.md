# Arduino-Projects
A collection of Arduino projects focused on developing embedded systems, C++ programming, and hardware integration skills. Projects include sensors, motors, displays, and control systems built through hands-on experimentation. 

## About This Repository
This repository contains Arduino projects built using an Arduino Uno and various electronic components. Each project focuses on developing practical skills in:

- Embedded C/C++ programming
- Digital and analog input/output
- Sensor integration
- Motor control
- LCD displays and user interfaces
- State-based logic
- Hardware troubleshooting and circuit design

Projects are organized into separate folders, each containing:
- Arduino source code
- Project documentation
- Demonstrations (when available)

---

# Hardware Used
Main components used throughout these projects:
- Arduino Uno R3
- Breadboard and jumper wires
- LEDs
- Push buttons
- Potentiometers
- Servo motors
- HC-SR04 ultrasonic distance sensor
- LCD1602 display
- Buzzers
- Thermistor
- Resistors

---

# Projects
## Ultrasonic Radar Scanner
A radar-style scanning system using an HC-SR04 ultrasonic sensor mounted on a servo motor.

### Features:
- Servo continuously scans an area
- Measures object distance using ultrasonic waves
- Displays distance measurements on an LCD1602 display
- Activates LED and buzzer warnings when objects are detected within a set range
- Stops scanning when an object remains within detection range
- Resumes scanning when the object moves out of range

### Concepts Learned:
- Ultrasonic distance measurement
- Sensor data processing
- Servo motor control
- LCD interfacing
- Real-time monitoring
- Conditional logic
- State-based control

---

## Thermistor Temperature Monitor
An Arduino-based temperature monitoring system that uses a thermistor to measure ambient temperature and displays the current temperature and adjustable set temperature on an LCD1602.

### Features
- Measures temperature using a thermistor voltage divider
- Converts analog readings into temperature using the thermistor Beta equation
- Averages multiple sensor readings to reduce measurement noise
- Displays current temperature and set temperature on an LCD1602
- Allows the user to adjust the set temperature using push buttons
- Limits the set temperature between 15°C and 35°C
- Uses red and green LEDs to indicate temperature relative to the setpoint
- Uses hysteresis to prevent rapid switching near the set temperature

### Concepts Learned
- Analog-to-digital conversion
- Voltage divider circuits
- Thermistor resistance-temperature relationships
- Mathematical sensor conversion
- Sensor data filtering
- Button edge detection
- Hysteresis
- LCD interfacing
- Embedded C++ control logic

---

## Future Projects
More Arduino projects will be added as new components and embedded systems concepts are explored.
