// Include the necessary libraries
#include <Arduino.h>

// Define the GPIO pin where the PIR sensor is connected
#define PIR_PIN 2 // You can use any GPIO pin

// Variable to store the PIR sensor state
volatile bool motionDetected = false;

// ISR (Interrupt Service Routine) for handling motion detection
void IRAM_ATTR handleMotion() {
  motionDetected = true;
}

void setup() {
  Serial.begin(9600); // Initialize serial communication for debugging
  pinMode(PIR_PIN, INPUT_PULLUP); // Set the PIR pin as input
  attachInterrupt(digitalPinToInterrupt(PIR_PIN), handleMotion, RISING); // Attach the interrupt
}

void loop() {
  if (motionDetected) {
    Serial.println("Motion detected!");
    // Do some
  }

