#define BLYNK_TEMPLATE_ID "YOUR ID BLYNK"
#define BLYNK_DEVICE_NAME ""
#define BLYNK_AUTH_TOKEN " YOUR TOKEN BLYNK"
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "YOUR AUTH";
char ssid[] = "KHUSUS ROBO";
char pass[] = "YOUR PASSWORD";

int ENA = D3;
int IN1 = D4;
int IN2 = D5;

int ENB = D8;
int IN3 = D6;
int IN4 = D7;

int MAX_PWM_VOLTAGE = 50;

void setup() {
  Serial.begin(9600); 
  Blynk.begin(auth, ssid, pass); 
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop(){
     Blynk.run();
}

void left_forward(){
    digitalWrite(ENA, HIGH);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
}

void left_backward(){
    digitalWrite(ENA, HIGH);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
}

void left_stop(){
    digitalWrite(ENA, LOW);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
}

void right_forward(){
    digitalWrite(ENB, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
}

void right_backward(){
    digitalWrite(ENB, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
}

void right_stop(){
    digitalWrite(ENB, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
}

// Handling Joystick data 
BLYNK_WRITE(V7) {
     int x = param[0].asInt(); 
     int y = param[1].asInt();
     
     Serial.print("X = ");
     Serial.print(x);
     Serial.print("; Y = ");
     Serial.println(y);

     if(x<128 && y<128 && y>0){
          Serial.println("BL");
          left_stop();
          right_backward();
     } else if(x>128 && y>128 && y<255){     
          Serial.println("FR");
          left_forward();
          right_stop();
     } else if(y==0){
          Serial.println("B");
          left_backward();
          right_backward();
     } else if(x==128 && y==128){        
      Serial.println("S");
          left_stop();
          right_stop();
     } else if(y==255){
          Serial.println("F");
          left_forward();
          right_forward();
     } else if(x>128 && y<128 && y>0){                  
      Serial.println("BR");
          left_backward();
          right_stop();
     } else if(x<128 && y>128 && y<255) { 
          Serial.println("FL");
          left_stop();
          right_forward();
     } 
}

void testTwo() {
  // turn on motors
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);  
  //max speed
  for (int i = 0; i < 256; i++) {
      analogWrite(ENA, i);
      analogWrite(ENB, i);
      delay(50);
  }
 // kembali ke 0
  for (int i = 255; i >= 0; --i) {
        analogWrite(ENA, i);
        analogWrite(ENB, i);
        delay(50);
  }
  // now turn off motors
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
