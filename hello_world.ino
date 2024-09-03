// Project: Basic LED Blinking with Serial Communication
// Description: This code blinks an LED and sends "Hello, World!" over serial communication.
// Author: Ameed Othman
// Date: 03.09.2024

// Define constants
#define LED_PIN 8        
const int BLINK_DELAY = 500;  
const int SERIAL_DELAY = 1000; 

void setup() {
  // Initialize serial communication at 9600 baud
  Serial.begin(9600);          
  pinMode(LED_PIN, OUTPUT);    
}

void loop() {
  // Blink the LED
  digitalWrite(LED_PIN, HIGH);  
  delay(BLINK_DELAY);           
  digitalWrite(LED_PIN, LOW);   

  // Send a message over serial
  Serial.println("Hello, World!");
  delay(SERIAL_DELAY);
}
