#define BLYNK_TEMPLATE_ID "" // this is only optional if you want to add id in blynk
#define BLYNK_DEVICE_NAME "" // your defice name in blyk
#define BLYNK_AUTH_TOKEN "" // your token in blyk
#define BLYNK_PRINT Serial

#include <WiFi.h>
#include<BlynkSimpleEsp32.h>

//pinmode
#define ENA 34
#define IN1 14
#define IN2 5
#define IN3 27
#define IN4 18
#define ENB 26

//variable
int y =50;
int x =50;
int Speed;

//pass or connect
char auth[]=""; // your auth in blyk
char ssid[]="TMDARKVG"; //your wifi name
char pass[]="TMDARKVG"; //your password if there is a password on the wifi

void setup() {
  Serial.begin(9600);
  pinMode(ENA,OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(ENB,OUTPUT);

  Blynk.begin(auth,pass,ssid,"blynk.cloud",80);
}
BLYNK_WRITE(V0){
  x=param[0].asInt();}
BLYNK_WRITE(V1){
  y=param[0].asInt();}
  BLYNK_WRITE(V2){
  Speed=param.asInt();}
  
//this is your setting in blynk for sensitivity
void smartcar(){
  if(y > 70){
    carForward();
    Serial.println("carForward");}
    else if(y < 30){
      carBackward();
      Serial.println("carBackward");}
    else if(x<30){
      carLeft();
      Serial.println("carLeft");}
    else if(x>70){
      carRight();
      Serial.println("carRight");}
    else if(x<70 && x >30 && y<70 && y>30){
      carStop();
      Serial.println("carStop");}
}
// run with blyk.app
void loop() {
  Blynk.run();
  smartcar();
}
//if move forward
void carForward(){
  analogWrite(ENA,Speed);
  analogWrite(ENB,Speed);
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);}
//if move to back
void carBackward(){
  analogWrite(ENA,Speed);
  analogWrite(ENB,Speed);
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);}
//move to left
void carLeft(){
  analogWrite(ENA,Speed);
  analogWrite(ENB,Speed);
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);}
//move to right
void carRight(){
  analogWrite(ENA,Speed);
  analogWrite(ENB,Speed);
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);}
//and stop car
void carStop(){
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);}
