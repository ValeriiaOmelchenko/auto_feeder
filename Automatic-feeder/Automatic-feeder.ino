#include <Servo.h>
#include <EEPROM.h>
#include <SoftwareSerial.h>


#define LED
#define FILLING

byte dailyPortion = 0;
byte singlePortion = 0;
byte feedingCount = 0;
byte feedingDelay = 0;
byte servoAngle = 0;
int currentTime = 0;
int lastFeedingTime = 0;
int servoDelay = 0;
int data = 0;

Servo servo;
SoftwareSerial BT(10, 11);  // RX, TX


void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  servo.attach();
  servo.write(servoAngle);
  Serial.begin(57600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (BT.available()) {
    data = BT.read();
    if (data > 10) {
      dailyPortion = data;
    } else {
      feedingCount = data;
    }
  }
}
