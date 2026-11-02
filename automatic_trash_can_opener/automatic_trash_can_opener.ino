#include <Servo.h>;

const int led = 11;
const int trig = 9;
const int echo = 8;

Servo myservo;

void setup() {
  myservo.attach(10);
  pinMode(led, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  long duration, distance;
  duration = pulseIn(echo, HIGH);
  distance = (duration / 2) / 29.1;

  Serial.print("jarak :");
  Serial.print(distance);
  Serial.println(" cm");
  delay(500);

  if (distance < 40) {
    digitalWrite(led, HIGH);
    myservo.write(180);
    //delay(1500);
  } else {
    digitalWrite(led, LOW);
    myservo.write(0);
    //delay(2500);
  }
  //delay();
}
//delay();
