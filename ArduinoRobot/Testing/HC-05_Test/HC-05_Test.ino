#include <SoftwareSerial.h>

SoftwareSerial BTSerial(0, 1);

int reading = 0;

void setup() {
  pinMode(9, OUTPUT);
  digitalWrite(9, HIGH);

  Serial.begin(38400); // Defualt baud rate of the HC-05.
  Serial.println("Enter AT Commands:");
  BTSerial.begin(38400); // HC-05 defualt speed in AT command mode
}

void loop() {
  // Allows commands and messages to be sent from computer
  if(Serial.available())
    BTSerial.write(Serial.read());

  // Allows commands and messages to be sent from HC-05
  if(BTSerial.available())
    Serial.write(BTSerial.read());
}
