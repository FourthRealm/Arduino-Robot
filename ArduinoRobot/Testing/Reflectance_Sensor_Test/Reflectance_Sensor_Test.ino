const int sensorOnePin = A0;
const int sensorTwoPin = A1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorOneValue = analogRead(A0);
  //int sensorTwoValue = analogRead(A1);

  Serial.print("Sensor 1: ");
  Serial.println(sensorOneValue);
  //Serial.print(" Sensor 2: ");
  //Serial.println(sensorTwoValue);

  delay(250);
}
