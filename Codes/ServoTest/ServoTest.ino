#include <Servo.h>

Servo FlapServo;
Servo ElbowServo;
Servo ShoulderServo;

Servo Tensioner;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  ElbowServo.attach(7);
  Tensioner.attach(8);

  ElbowServo.write(100);
  Tensioner.write(180);
}

void loop() {
  // put your main code here, to run repeatedly:
  // Serial.println(analogRead(A0));

    // Tensioner.write((int)((180.0/1023.0)*analogRead(A0)));
    ElbowServo.write(160);
    delay(80);
    ElbowServo.write(100);
    delay(80);
}
