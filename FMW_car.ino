#include <SoftwareSerial.h>
#include <Wire.h>
#include <Adafruit_TCS34725.h>

// Define pin numbers for motor control
const int leftMotorForward = 4;
const int leftMotorReverse = 5;
const int rightMotorForward = 6;
const int rightMotorReverse = 7;
const int IRSensorPin = 43;

SoftwareSerial hc06(2, 3);  // Set up the HC-06 Bluetooth module on pins 2 and 3
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);

void setup() {
  pinMode(leftMotorForward, OUTPUT);
  pinMode(leftMotorReverse, OUTPUT);
  pinMode(rightMotorForward, OUTPUT);
  pinMode(rightMotorReverse, OUTPUT);
  
  pinMode(IRSensorPin, INPUT);
  
  Serial.begin(9600);  // Start serial communication at 9600 bps
  hc06.begin(9600);    // Start software serial communication for Bluetooth
  if (tcs.begin()) {
    Serial.println("Found color sensor");
  } else {
    Serial.println("No color sensor found");
    while (1);  // Stop everything if no color sensor
  }

  Serial.println("Setup complete, waiting for connection...");
}
  Serial.println("Setup complete, waiting for connection...");
}

void loop() {
  followLine();

  if (hc06.available()) {  // Check if there is incoming data from Bluetooth
    uint16_t clear, red, green, blue;
    tcs.getRawData(&red, &green, &blue, &clear);

    if (green > red && green > blue) {  // Adjust condition based on detected color
      stopCar();
      hc06.println("CaptureImage");  // Send the command to capture image via Bluetooth
      Serial.println("Command sent: CaptureImage");
      delay(12000);  // Wait for 12 seconds before resuming
      followLine();  // Continue following the line after the action
    }
  }
}

void followLine() {
  int sensorValue = digitalRead(IRSensorPin);
  if (sensorValue == HIGH) {  // Assuming HIGH means line is detected
    moveForward();
  } else {
    stopCar();
  }
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
