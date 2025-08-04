#include <NewPing.h>
#include <Servo.h>

const int LeftMotorForward = 2;
const int LeftMotorBackward = 3;
const int RightMotorForward = 4;
const int RightMotorBackward = 5;

#define trig_pin A1
#define echo_pin A2
#define maximum_distance 200

boolean goesForward = false;
int distance = 100;

NewPing sonar(trig_pin, echo_pin, maximum_distance);
Servo servo_motor;

void setup() {
  pinMode(RightMotorForward, OUTPUT);
  pinMode(LeftMotorForward, OUTPUT);
  pinMode(LeftMotorBackward, OUTPUT);
  pinMode(RightMotorBackward, OUTPUT);

  servo_motor.attach(8);
  servo_motor.write(115);

  delay(2000);
  distance = readPing(); delay(500);
  distance = readPing(); delay(500);
  distance = readPing(); delay(500);
  distance = readPing(); delay(500);
}

void loop() {
  int distanceRight = 0;
  int distanceLeft = 0;

  delay(50);

  if (distance <= 50) {
    moveStop(); delay(500);
    moveBackward(); delay(500);
    moveStop(); delay(500);

    distanceRight = lookRight(); delay(500);
    distanceLeft = lookLeft(); delay(500);

    if (distanceRight >= distanceLeft) {
      turnRight(); moveStop();
    } else {
      turnLeft(); moveStop();
    }
  } else {
    moveForward();
  }

  distance = readPing();
}

int lookRight() {
  servo_motor.write(50); delay(500);
  int distance = readPing(); delay(100);
  servo_motor.write(115);
  return distance;
  delay(100);
}

int lookLeft() {
  servo_motor.write(170); delay(500);
  int distance = readPing(); delay(100);
  servo_motor.write(115);
  return distance;
  delay(100);
}

int readPing() {
  delay(70);
  int cm = sonar.ping_cm();
  if (cm == 0) cm = 250;
  return cm;
}

void moveStop() {
  digitalWrite(RightMotorForward, LOW);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);
  digitalWrite(LeftMotorBackward, LOW);
}

void moveForward() {
  if (!goesForward) {
    goesForward = true;
    digitalWrite(LeftMotorForward, HIGH);
    digitalWrite(RightMotorForward, HIGH);
    digitalWrite(LeftMotorBackward, LOW);
    digitalWrite(RightMotorBackward, LOW);
  }
}

void moveBackward() {
  goesForward = false;
  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorBackward, HIGH);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorForward, LOW);
}

void turnRight() {
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorBackward, HIGH);
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorForward, LOW);
  delay(500);
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorBackward, LOW);
}

void turnLeft() {
  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);
  delay(500);
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorBackward, LOW);
}