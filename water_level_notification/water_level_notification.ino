#define pinSensor A0
int sensorValue = 0;
float tinggiAir = 0;
float sensorVoltage = 0;

int nilaiMax = 1023;
float panjangSensor = 4.0;

void setup() {
  Serial.begin(9600);
  Serial.println("pembaca ketinggian air");
  delay(500);
}

void loop() {
  sensorValue = analogRead(pinSensor);
  tinggiAir = sensorValue*panjangSensor/nilaiMax;
  sensorVoltage = sensorValue*5.0/1023;

  Serial.print("sensor value = ");
  Serial.println(sensorValue);
  Serial.print("sensor voltage = ");
  Serial.println(sensorVoltage);
  Serial.print("tinggiAir = ");
  Serial.println(tinggiAir);
  Serial.println();
  delay(1000);
  }
