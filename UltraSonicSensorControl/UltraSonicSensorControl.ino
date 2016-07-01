/*
   This module aims to control an arduino uno
   to control an ultrasonic sensor
*/
// module parameters
const int baudrate = 9600;

// pins assignation
const int triggerPin = 8;
const int echoPin = 7;

void setup()
{
  // configure baudrate
  Serial.begin(baudrate);

  // configure Pins
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop()
{
  float distance = getDistance();

  Serial.print(distance);
  Serial.println(" cm");
  Serial.println();
  
  delay(500); // delay for stability (in ms)
}
