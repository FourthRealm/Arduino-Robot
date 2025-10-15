#include <Wire.h>
#include "Adafruit_TCS34725.h"

Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);

// Colour index guide. 1 = red. 2 = green. 3 = blue.
/*int coloursRed[3] = {1, 1, 200};
int coloursGreen[3] = {1, 1, 250};
int coloursBlue[3] = {1, 1, 200};*/

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Colour view test");
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned int clear, red, green, blue; 

  tcs.setInterrupt(false); // Turn on LED
  delay(60); // Takes 50ms to read
  tcs.getRawData(&red, &green, &blue, &clear); // Read the sensor
  tcs.setInterrupt(true); // Turn off LED

  Serial.print("Red: "); Serial.print(red);
  Serial.print(" Green: "); Serial.print(green);
  Serial.print(" Blue: "); Serial.print(blue);
  Serial.print(" Clear: "); Serial.print(clear);
  Serial.println();

  /*if(isDistance(red, 200, 50) && isDistance(green, 250, 50) && isDistance(blue, 200, 50)) {
    Serial.println("Blue");
  }
  else {
    Serial.println("Unknown");
  }*/
}

bool isDistance(int value, int valueSame, int distance) {
  if(value >= valueSame - distance && valueSame <= value + distance) {
    return true;
  }
  else {
    return false;
  }
}
