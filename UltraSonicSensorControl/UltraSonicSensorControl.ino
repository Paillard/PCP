/*
   This module aims to control an arduino uno
   to control an ultrasonic sensor
*/
// module parameters
const int baudrate = 9600;

// pins assignation
const int triggerPin = 7;
const int echoPin = 8;

void setup()
{
  // configure baudrate
  Serial.begin(baudrate);

  // configure Pins
  pinMode(triggerPin, OUTPUT); //defining pin modes
  pinMode(echoPin, INPUT);
}

void loop()
{
  float distance = getDistance();

  Serial.print(distance); // send the current value stored in distance to the serial monitor
  Serial.println("cm");
  Serial.println();
  delay(500); // delay for stability (in ms)
}
