#include <Arduino.h>
#define TRIG_PIN 3  // Pin for TRIG
#define ECHO_PIN 2  // Pin for ECHO

void setup() {
  Serial.begin(115200); // Initialize serial communication
  pinMode(TRIG_PIN, OUTPUT); // Set TRIG as output
  pinMode(ECHO_PIN, INPUT);  // Set ECHO as input
}

void loop() {
  long duration;  // Time for ultrasonic wave to return
  float distance; // Calculated distance in cm

  // Clear the TRIG pin
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  // Trigger the sensor by sending a HIGH pulse of 10 microseconds
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Read the ECHO pin and measure the duration of the pulse
  duration = pulseIn(ECHO_PIN, HIGH);

  // Calculate the distance in cm
  // Sound speed in LPG liquid is approximately 200 m/s (20,000 cm/s)
  distance = (duration / 2.0) * 0.02; // Convert to cm (0.02 factor for LPG)

  // Print the distance
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(1000); // Wait for 1 second before next reading
}