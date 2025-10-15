#include <Photo_Interrupter.h>

/*class PhotoInterrupter {
  int pin;
  bool direction; // True is clockwise
  int clicks;
  double degreesPerSecond;
  unsigned long lastClick;

  public:
    PhotoInterrupter(int pinNum) {
      // Initialize pin num
      pin = pinNum;

      // Setup interrupt
      pinMode(pin, INPUT_PULLUP);
    }

    void OnPhotoInterrupt() {
      clicks++;
      double clickTime = millis() - lastClick;
      degreesPerSecond = (1000/(clickTime * 20)) * 360;
      lastClick = millis();
    }

    int GetData(int dataType) {
      switch(dataType) {
        case 1:
          return clicks;
        case 2:
          return (int)degreesPerSecond;
      }
    }
};*/

PhotoInterrupter left = PhotoInterrupter(2);
//PhotoInterrupter right = PhotoInterrupter(3);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(2), LeftInterrupt, RISING);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(left.GetData(2));
}

void LeftInterrupt() {
  left.OnPhotoInterrupt();
}


