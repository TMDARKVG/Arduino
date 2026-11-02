#include <Servo.h>
#include <IRremote.h>

const uint32_t ONE_CODE;
const uint32_t TWO_CODE;
const uint32_t THREE_CODE;
const uint32_t FORWARD_CODE;
const uint32_t BACK_CODE;
const uint32_t LEFT_CODE;
const uint32_t RIGHT_CODE;
const uint32_t GRIP_CODE;

const uint8_t ENA_R = 2;
const uint8_t IN1_R = 3;
const uint8_t IN2_R = 4;
const uint8_t IN3_R = 5;
const uint8_t IN4_R = 6;
const uint8_t ENB_R = 7;
const uint8_t ENA_L = 8;
const uint8_t IN1_L = 9;
const uint8_t IN2_L = 10;
const uint8_t IN3_L = 11;
const uint8_t IN4_L = 12;
const uint8_t ENB_L = 13;
const uint8_t SERVO = A0;
const uint8_t IR_REMOTE = A1;
const uint8_t IR_L = A2;
const uint8_t IR_R = A3;

bool one = false;
bool two = false;
bool three = false;
bool forward = false;
bool back = false;
bool left = false;
bool right = false;
bool grip = false;

const int speed = 200;

Servo myservo;
IRremote remote(IR_REMOTE);

void setup() {
  Serial.begin(9600);

  myservo.attach(SERVO);
  remote.enableIRIn();

  myservo.write(0);

  pinMode(ENA_R, OUTPUT);
  pinMode(IN1_R, OUTPUT);
  pinMode(IN2_R, OUTPUT);
  pinMode(IN3_R, OUTPUT);
  pinMode(IN4_R, OUTPUT);
  pinMode(ENB_R, OUTPUT);
  pinMode(ENA_L, OUTPUT);
  pinMode(IN1_L, OUTPUT);
  pinMode(IN2_L, OUTPUT);
  pinMode(IN3_L, OUTPUT);
  pinMode(IN4_L, OUTPUT);
  pinMode(ENB_L, OUTPUT);
  pinMode(IR_L, INPUT);
  pinMode(IR_R, INPUT);
}

void loop() {
  run_right(speed, speed);
  run_left(-speed, -speed);
  delay(150);
  stop();
  delay(150);
  run_right(-speed, -speed);
  run_left(speed, speed);
  delay(150);
  stop();
}

void stop() {
  digitalWrite(ENA_R, LOW);
  digitalWrite(ENB_R, LOW);
  digitalWrite(ENA_L, LOW);
  digitalWrite(ENB_L, LOW);
}

void run_right(int speed1, int speed2) {
  if (speed1 > 0) {
    digitalWrite(IN1_R, HIGH);
    digitalWrite(IN2_R, LOW);
  }
  if (speed2 > 0) {
    digitalWrite(IN3_R, HIGH);
    digitalWrite(IN4_R, LOW);
  }
  if (speed1 < 0) {
    digitalWrite(IN1_R, LOW);
    digitalWrite(IN2_R, HIGH);
  }
  if (speed2 < 0) {
    digitalWrite(IN3_R, LOW);
    digitalWrite(IN4_R, HIGH);
  }

  digitalWrite(ENA_R, HIGH);
  digitalWrite(ENB_R, HIGH);
  delayMicroseconds(speed);
  digitalWrite(ENA_R, LOW);
  digitalWrite(ENB_R, LOW);
}

void run_left(int f_speed, int b_speed) {
  if (speed1 > 0) {
    digitalWrite(IN1_L, HIGH);
    digitalWrite(IN2_L, LOW);
  }
  if (speed2 > 0) {
    digitalWrite(IN3_L, HIGH);
    digitalWrite(IN4_L, LOW);
  }
  if (speed1 < 0) {
    digitalWrite(IN1_L, LOW);
    digitalWrite(IN2_L, HIGH);
  }
  if (speed2 < 0) {
    digitalWrite(IN3_L, LOW);
    digitalWrite(IN4_L, HIGH);
  }

  digitalWrite(ENA_L, HIGH);
  digitalWrite(ENB_L, HIGH);
  delayMicroseconds(speed);
  digitalWrite(ENA_L, LOW);
  digitalWrite(ENB_L, LOW);
