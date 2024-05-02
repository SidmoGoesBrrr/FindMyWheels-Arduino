# FindMyWheels Arduino Module
## Overview
![image](https://github.com/SidmoGoesBrrr/FindMyWheels-Arduino/assets/60550481/9a2cc794-afa2-43cb-bb02-0206ae6cc248)

The FindMyWheels Arduino module controls a mini robotic car designed to navigate parking lots and trigger a camera app via Bluetooth for car recognition. This README details the operation and setup of the Arduino-controlled car which is integral to the FindMyWheels system.

## Features

- **Predefined Movement Commands**: The car has programmed commands to move forward, backward, left, right, and to stop.
- **Bluetooth Connectivity*: Uses Bluetooth to communicate with an Android app, sending commands to capture images of cars.
- **IR Sensor Detection**: An IR sensor detects specific markers (such as black color on the ground) to stop the car and initiate the image capture process.
- **Automatic Navigation**: Upon activation, the car starts moving forward and navigates based on predefined paths and commands.
  
## How It Works
- **Startup: Upon powering up**, the car begins moving forward automatically.
- **Detection and Capture**: When the IR sensor detects a black marker, indicating a parking spot, the car stops. It then sends a "CaptureImage" signal to the connected phone via Bluetooth.
- **Photo Capture**: The phone app, linked to the car via Bluetooth, captures an image of the parked car.
- **Resume Movement**: After a five-second pause post-capture, the car resumes its forward movement until the next stop signal.

## Built With
- **Arduino IDE**: Programmed using the Arduino Integrated Development Environment.
- **Arduino Mega 2560**: Utilizes the Arduino Mega 2560 board for managing inputs/outputs with ample memory and processing power for real-time operations.
- **Software and Libraries:**
 - SoftwareSerial.h for Bluetooth communications.
![PXL_20240502_071511564 MP](https://github.com/SidmoGoesBrrr/FindMyWheels-Arduino/assets/60550481/daad8612-6cd8-4a21-80af-64b8d3615d89)
