// https://youtu.be/KfP_LfUiwdc

// Select Arduino nano / ATmega328P

#include <Servo.h>

Servo armServo;


void setup() {
  armServo.attach(12);
  armServo.write(90);
  Serial.begin(9600);
  pinMode(2, INPUT); //IR sensor
  pinMode(13, OUTPUT);
  pinMode(13, OUTPUT);
  //  pinMode(0, OUTPUT);
  //  pinMode(1, OUTPUT);
}

int sensorValue;
int prevSensorValue = 1;

void loop() {
  sensorValue = digitalRead(2);
  Serial.println(sensorValue);
  if (prevSensorValue)
    if (!sensorValue )
      action();
  prevSensorValue = sensorValue;
  delay(50);
}
void action() {
  led(true);
  //eating
  delay(100);
 // armServo.attach(9);
  armServo.write(10);
  delay(300);
  armServo.write(70);
  delay(500);

  //after ate
  delay(100);
  armServo.write(50);
  delay(250);
  armServo.write(70);
  delay(250);
  armServo.write(50);
  delay(250);
  armServo.write(70);
  delay(250);
  armServo.write(50);
  delay(250);
  armServo.write(70);
  delay(250);
  armServo.write(50);
  delay(250);
  armServo.write(90);
  delay(250);
  

  //release arm's torque
 // armServo.detach();
  led(false);
}

void led(bool onOff) {
  if (onOff) {
    digitalWrite(11, HIGH);
    digitalWrite(10, HIGH);
    //    digitalWrite(0, LOW);
    //    digitalWrite(1, LOW);
  } else {
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);      
    //   digitalWrite(1, HIGH);
  }
}

