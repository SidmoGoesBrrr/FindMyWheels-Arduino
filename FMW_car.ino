#include <SoftwareSerial.h>

// Define pin numbers for motor control
const int leftMotorForward = 4;
const int leftMotorReverse = 5;
const int rightMotorForward = 6;
const int rightMotorReverse = 7;
const int IRSensorPin = 43;

SoftwareSerial hc06(2, 3);  // Set up the HC-06 Bluetooth module on pins 2 and 3

void setup() {
  pinMode(leftMotorForward, OUTPUT);
  pinMode(leftMotorReverse, OUTPUT);
  pinMode(rightMotorForward, OUTPUT);
  pinMode(rightMotorReverse, OUTPUT);
  
  pinMode(IRSensorPin, INPUT);
  
  Serial.begin(9600);  // Start serial communication at 9600 bps
  hc06.begin(9600);    // Start software serial communication for Bluetooth
  Serial.println("Setup complete, waiting for connection...");
}

void loop() {
  moveForward();
  if (hc06.available()) {  // Check if there is incoming data from Bluetooth
    int sensorValue = digitalRead(IRSensorPin);
    Serial.print("IR Sensor Value: ");
    Serial.println(sensorValue);
    if (sensorValue == LOW) {  // Check if black tape is detected
      stopCar();
      hc06.println("CaptureImage");  // Send the command to capture image via Bluetooth
      Serial.println("Command sent: CaptureImage");
      delay(12000);  // Wait for 12 seconds
    }
  }
  delay(10);  // Short delay to allow for serial data processing
}

void moveForward() {
  digitalWrite(leftMotorForward, HIGH);
  digitalWrite(leftMotorReverse, LOW);
  digitalWrite(rightMotorForward, HIGH);
  digitalWrite(rightMotorReverse, LOW);
}

void moveBackward() {
  digitalWrite(leftMotorForward, LOW);
  digitalWrite(leftMotorReverse, HIGH);
  digitalWrite(rightMotorForward, LOW);
  digitalWrite(rightMotorReverse, HIGH);
}

void stopCar() {
  digitalWrite(leftMotorForward, LOW);
  digitalWrite(leftMotorReverse, LOW);
  digitalWrite(rightMotorForward, LOW);
  digitalWrite(rightMotorReverse, LOW);
}
