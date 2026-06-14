#include <NewPing.h>

#define ULTRASONIC_SENSOR_TRIG 11
#define ULTRASONIC_SENSOR_ECHO 12

#define MAX_FORWARD_MOTOR_SPEED 150
#define MIN_DISTANCE 10
#define MAX_DISTANCE 20
#define STOP_DISTANCE 9  // STOP if object is closer than this

#define IR_SENSOR_RIGHT 6
#define IR_SENSOR_LEFT 7

// Right motor
int enableRightMotor = 8;
int rightMotorPin1 = 2;
int rightMotorPin2 = 3;

// Left motor
int enableLeftMotor = 9;
int leftMotorPin1 = 4;
int leftMotorPin2 = 5;

NewPing mySensor(ULTRASONIC_SENSOR_TRIG, ULTRASONIC_SENSOR_ECHO, 400);

void setup() {
  pinMode(enableRightMotor, OUTPUT);
  pinMode(rightMotorPin1, OUTPUT);
  pinMode(rightMotorPin2, OUTPUT);

  pinMode(enableLeftMotor, OUTPUT);
  pinMode(leftMotorPin1, OUTPUT);
  pinMode(leftMotorPin2, OUTPUT);

  pinMode(IR_SENSOR_RIGHT, INPUT);
  pinMode(IR_SENSOR_LEFT, INPUT);

  Serial.begin(9600);  // For debugging

  rotateMotor(0, 0);
}

void loop() {
  int distance = mySensor.ping_cm();
  int rightIRSensorValue = digitalRead(IR_SENSOR_RIGHT);
  int leftIRSensorValue = digitalRead(IR_SENSOR_LEFT);

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm | Right IR: ");
  Serial.print(rightIRSensorValue);
  Serial.print(" | Left IR: ");
  Serial.println(leftIRSensorValue);

  if (distance > 0 && distance <= STOP_DISTANCE) {
    // Object too close - stop immediately
    rotateMotor(0, 0);
  }
  // ✅ Both IR sensors detect → move forward
  else if (rightIRSensorValue == LOW && leftIRSensorValue == LOW) {
    rotateMotor(MAX_FORWARD_MOTOR_SPEED, MAX_FORWARD_MOTOR_SPEED);
  }
  // Turn Right: Right IR detects hand
  else if (rightIRSensorValue == LOW && leftIRSensorValue == HIGH) {
    rotateMotor(0, MAX_FORWARD_MOTOR_SPEED);  // Left motor on, right off
  }
  // Turn Left: Left IR detects hand
  else if (rightIRSensorValue == HIGH && leftIRSensorValue == LOW) {
    rotateMotor(MAX_FORWARD_MOTOR_SPEED, 0);  // Right motor on, left off
  }
  // Move forward if distance is acceptable
  else if (distance >= MIN_DISTANCE && distance <= MAX_DISTANCE) {
    rotateMotor(MAX_FORWARD_MOTOR_SPEED, MAX_FORWARD_MOTOR_SPEED);
  }
  // Stop if nothing detected
  else {
    rotateMotor(0, 0);
  }

  delay(50); // Small delay for stability
}

void rotateMotor(int rightMotorSpeed, int leftMotorSpeed) {
  // Right motor direction
  if (rightMotorSpeed > 0) {
    digitalWrite(rightMotorPin1, HIGH);
    digitalWrite(rightMotorPin2, LOW);
  } else if (rightMotorSpeed < 0) {
    digitalWrite(rightMotorPin1, LOW);
    digitalWrite(rightMotorPin2, HIGH);
  } else {
    digitalWrite(rightMotorPin1, LOW);
    digitalWrite(rightMotorPin2, LOW);
  }

  // Left motor direction (REVERSED to correct rotation)
  if (leftMotorSpeed > 0) {
    digitalWrite(leftMotorPin1, LOW);  // Reversed
    digitalWrite(leftMotorPin2, HIGH); // Reversed
  } else if (leftMotorSpeed < 0) {
    digitalWrite(leftMotorPin1, HIGH); // Reversed
    digitalWrite(leftMotorPin2, LOW);  // Reversed
  } else {
    digitalWrite(leftMotorPin1, LOW);
    digitalWrite(leftMotorPin2, LOW);
  }

  analogWrite(enableRightMotor, abs(rightMotorSpeed));
  analogWrite(enableLeftMotor, abs(leftMotorSpeed));
}