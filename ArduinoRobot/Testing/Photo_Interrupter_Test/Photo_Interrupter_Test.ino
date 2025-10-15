#include <L298N_Motor.h>

class L298N_Encoded_Motor {
  public:
    // Defualt values for the motor
    Motor motor = Motor(2, 3, 4);

    double pulseCount = 0;
    double motorAngle = 0;

    L298N_Encoded_Motor(Motor driveMotor) {
      motor = driveMotor;
    }

    void IncrementPulses() {
      pulseCount++;
      motorAngle = pulseCount / 20 * 360;
    }
};

#define leftWheelEncoder 2
// 20 Pulses in a revolution.
volatile double leftWheelPulseCount = 0;

// Only accurate to within 18 degrees.
volatile double leftWheelMotorAngle;

Motor motor = Motor(7,8,9);
L298N_Encoded_Motor encodedMotor = L298N_Encoded_Motor(motor);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(leftWheelEncoder, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(leftWheelEncoder), leftMotorPulse, RISING);
}

void loop() {
  Serial.println(leftWheelPulseCount);
  encodedMotor.motor.Run(192);
  delay(2000);
  encodedMotor.motor.StopMotor();
  delay(2000);
}

void leftMotorPulse() {
  encodedMotor.IncrementPulses();
}

void rightMotorPulse() {
  leftWheelPulseCount++;
  leftWheelMotorAngle = leftWheelPulseCount / 20 * 360;
}


