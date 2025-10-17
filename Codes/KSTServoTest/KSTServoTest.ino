#include <Servo.h>

Servo ShoulderServo;
Servo ElbowServo;

Servo Tensioner;

int cycles = 0;
int test_cycles = 100;

void setup() {

  Serial.begin(9600);

  ShoulderServo.attach(7);
  ElbowServo.attach(8);
  Tensioner.attach(9);

  ShoulderServo.write(55);
  ElbowServo.write(70);
  Tensioner.write(180);

}

void loop() {

  // Serial.println(analogRead(A0));

  // Tensioner.write((int)((180.0/1023.0)*analogRead(A0)));

  if (cycles < test_cycles)
  {
    ShoulderServo.write(55);
    ElbowServo.write(120);
    delay(100);

    ShoulderServo.write(70);
    ElbowServo.write(70);
    delay(100);

    cycles++;
  }
  else
  {
    // ShoulderServo.write(55);
    // ElbowServo.write(120);

    ShoulderServo.write(55);
    ElbowServo.write(120);
  }
  
}
