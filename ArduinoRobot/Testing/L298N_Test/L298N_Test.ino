#include <L298N_Motor.h>
#include <Photo_Interrupter.h>
#include <Clock.h>

Motor motor1 = Motor(4, 5, 6);
PhotoInterrupter encoder1 = PhotoInterrupter(2);

Motor motor2 = Motor(7, 8, 9);
PhotoInterrupter encoder2 = PhotoInterrupter(3);

Clock driveClock = Clock(false);

short motorSpeed = 100;
short motorDir = 1;

void setup() {
  // put your setup code here, to run once:
  attachInterrupt(digitalPinToInterrupt(2), Encoder1, RISING);
  attachInterrupt(digitalPinToInterrupt(3), Encoder2, RISING);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(driveClock.Time() >= 1000) {
    driveClock.Reset();

    motorSpeed *= -1;
    motorDir *= -1;

    motor1.Run(motorSpeed);
    encoder1.SetDir(motorDir);

    motor2.Run(motorSpeed);
    encoder2.SetDir(motorDir);
  }

  Serial.println(encoder1.GetData(2));
}

void Encoder1() {
  encoder1.OnPhotoInterrupt();
}

void Encoder2() {
  encoder2.OnPhotoInterrupt();
}
