#include <Wire.h>
#include "Adafruit_TCS34725.h"

class ColourSensor {
  Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);

  int amountColours = 5; // Amount of colours that will be recognised.
  int redValues[5] = {60, 400, 500, 200, 1000}; // Approximate red values for each colour.
  int greenValues[5] = {35, 90, 600, 280, 750}; // Approximate green values for each colour.
  int blueValues[5] = {24, 70, 250, 220, 500}; // Approximate blue values for each colour.

  int distanceSame = 100; /* Readings vary. This ensures that colours that are close to the value for a colour
  are considered the same */

  unsigned int red = 0;
  unsigned int green = 0;
  unsigned int blue = 0;
  unsigned int clear = 0;

  public:
    int getColour() {
      readSensor();

      for(int i = 0; i < amountColours; i++) {
        if(isDistance(red, redValues[i], distanceSame) && isDistance(green, greenValues[i], distanceSame) && isDistance(blue, blueValues[i], distanceSame)) {
          return i;
        }
      }
      return -1;
    }
    bool isDistance(int value, int valueSame, int distance) {
      if(value >= (valueSame - distance) && value <= (valueSame + distance)) {
        return true;
      }
      else {
        return false;
      }
    }
    void readSensor() {
      tcs.setInterrupt(false); // Turn on LED
      delay(60);
      tcs.getRawData(red, green, blue, clear); // Read the sensor
      tcs.setInterrupt(true); // Turn off LED
    }
    void printReadings() {
      Serial.print("Red: "); Serial.print(red);
      Serial.print("Green: "); Serial.print(green);
      Serial.print("Blue: "); Serial.print(blue);
      Serial.print("Clear: "); Serial.println(clear);
    }
}; 

int amountColours = 5; // Amount of colours that will be recognised.
int redValues[5] = {60, 400, 500, 200, 1000}; // Approximate red values for each colour.
int greenValues[5] = {35, 90, 600, 280, 750}; // Approximate green values for each colour.
int blueValues[5] = {24, 70, 250, 220, 500}; // Approximate blue values for each colour.

int distanceSame = 200;

unsigned int red = 0;
unsigned int green = 0;
unsigned int blue = 0;
unsigned int clear = 0;

Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Colour view test");
}

void loop() {
  // put your main code here, to run repeatedly:
  //int colour = colourSensor.getColour();
  //Serial.println(colour);
  readSensor();

  if(isDistance(red, ))

  delay(500);
}

#pragma region

int getColour() {
  readSensor();

  for(int i = 0; i < amountColours; i++) {
    if(isDistance(red, redValues[i], distanceSame) && isDistance(green, greenValues[i], distanceSame) && isDistance(blue, blueValues[i], distanceSame)) {
      return i;
    }
  }
  return -1;
}

bool isDistance(int value, int valueSame, int distance) {
  if(value >= valueSame - distance && valueSame <= value + distance) {
    return true;
  }
  else {
    return false;
  }
}
void readSensor() {
  tcs.setInterrupt(false); // Turn on LED
  delay(60);
  tcs.getRawData(&red, &green, &blue, &clear); // Read the sensor
  tcs.setInterrupt(true); // Turn off LED
}

void printReadings() {
  Serial.print("Red: "); Serial.print(red);
  Serial.print("Green: "); Serial.print(green);
  Serial.print("Blue: "); Serial.print(blue);
  Serial.print("Clear: "); Serial.println(clear);
}

#pragma endregion

