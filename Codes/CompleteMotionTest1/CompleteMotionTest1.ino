#include <DynamixelShield.h>
#include <Servo.h>

#if defined(ARDUINO_AVR_UNO) || defined(ARDUINO_AVR_MEGA2560)
  #include <SoftwareSerial.h>
  SoftwareSerial soft_serial(7, 8); // DYNAMIXELShield UART RX/TX
  #define DEBUG_SERIAL soft_serial
#elif defined(ARDUINO_SAM_DUE) || defined(ARDUINO_SAM_ZERO)
  #define DEBUG_SERIAL SerialUSB    
#else
  #define DEBUG_SERIAL Serial
#endif

const uint8_t DXL_ID = 1;
const float DXL_PROTOCOL_VERSION = 2.0;

DynamixelShield dxl;

//This namespace is required to use Control table item names
using namespace ControlTableItem;

Servo ElbowServo;
Servo ShoulderServo;

int cycles = 0;
int test_cycles = 100;

void setup() {
  // put your setup code here, to run once:
  
  // For Uno, Nano, Mini, and Mega, use UART port of DYNAMIXEL Shield to debug.
  DEBUG_SERIAL.begin(115200);

  // Set Port baudrate to 57600bps. This has to match with DYNAMIXEL baudrate.
  dxl.begin(57600);
  // Set Port Protocol Version. This has to match with DYNAMIXEL protocol version.
  dxl.setPortProtocolVersion(DXL_PROTOCOL_VERSION);
  // Get DYNAMIXEL information
  dxl.ping(DXL_ID);

  // Turn off torque when configuring items in EEPROM area
  dxl.torqueOff(DXL_ID);
  dxl.setOperatingMode(DXL_ID, OP_POSITION);
  dxl.torqueOn(DXL_ID);

  // Set up shoulder and elbow KST servos
  ElbowServo.attach(8);
  ShoulderServo.attach(7);

  // Initial position
  dxl.setGoalPosition(DXL_ID, 90, UNIT_DEGREE);
  ShoulderServo.write(55);
  ElbowServo.write(110);

  delay(5000);
}

void loop() {
  // put your main code here, to run repeatedly:

  if (cycles < test_cycles)
  {
    dxl.setGoalPosition(DXL_ID, 135, UNIT_DEGREE);
    ShoulderServo.write(55);
    ElbowServo.write(120);
    delay(100);

    dxl.setGoalPosition(DXL_ID, 45, UNIT_DEGREE);
    ShoulderServo.write(70);
    ElbowServo.write(70);
    delay(100);

    cycles++;
  }
  else
  {
    dxl.setGoalPosition(DXL_ID, 90, UNIT_DEGREE);

    // ShoulderServo.write(55);
    // ElbowServo.write(160);

    ShoulderServo.write(70);
    ElbowServo.write(110);

    delay(5000);
  }
}