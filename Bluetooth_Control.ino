// Arduino Bluetooth Control - Professional Code
// Connections: HC-05 TX -> Arduino RX (Pin 0), HC-05 RX -> Arduino TX (Pin 1)

int ledPin = 13; // Onboard LED pin
char incomingData = 0; 

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600); // Bluetooth communication speed
  Serial.println("System Ready. Send '1' to ON and '0' to OFF.");
}

void loop() {
  if(Serial.available() > 0) {
    incomingData = Serial.read(); // Reading data from Bluetooth
    
    if(incomingData == '1') {
      digitalWrite(ledPin, HIGH); 
      Serial.println("LED turned ON");
    }
    else if(incomingData == '0') {
      digitalWrite(ledPin, LOW);
      Serial.println("LED turned OFF");
    }
  }
}
