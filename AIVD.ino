//included libraries
#include <Servo.h>

//motors
Servo driveMotor;
Servo steerServo;

//sensors
int frontLeftTrig = A1;
int frontLeftEcho = A2;

int frontRightTrig = A3;
int frontRightEcho = A4;

int backLeftTrig = A5;
int backLeftEcho = A6;

int backRightTrig = A7;
int backRightEcho = A8;

int rightFrontTrig = A9;
int rightFrontEcho = A10;

int rightBackTrig = A11;
int rightBackEcho = A12;

//variables
  int potPin = A0;
  int potVal;
  int servoPos;
  double del;

void setup() {
  Serial.begin(9600);
  steerServo.attach(5);
  driveMotor.attach(6);
  pinMode(potPin, INPUT);

  forward(24, 0);
}

void loop() {

}

void forward(int distance, int steer){
  del = ((1/23.2) * distance) * 1000;
  servoPos = map(steer, -15, 15, 47, 77);
  steerServo.write(servoPos);
  delay(1000);
  driveMotor.write(100);
  delay(1000);
  driveMotor.write(110);
  delay(del);
  driveMotor.write(90);
}