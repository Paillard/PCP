// HC-SR04 Ultrasonic Distance
const int soundSpeed = 344; //(m/s), value found on google, not real but practical

float getDistance()
{
  digitalWrite(triggerPin, HIGH); // start sending sound wave(s)
  delay(5); // milliseconds
  digitalWrite(triggerPin, LOW); // module stops sending wave(s)

  // determine how long the ECHO pin was high for the last complete wave
  int duration = pulseIn(echoPin, HIGH); // in ms

  delay(10); //required, can be adjusted - carefully

  return (duration / 2) * (soundSpeed / 1000); // calculating distance with right scale
}
