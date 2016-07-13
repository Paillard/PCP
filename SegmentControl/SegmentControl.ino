/*
   This module aims to control an arduino uno
   to control a 7 segment promt

   Segment prompt used:
   http://wiki.electrolab.fr/File:7_segments_dot.jpg

   transistors driven
*/
// module parameters
const int baudrate = 9600;

// pins assignation
const int segAPin = 6;
const int segBPin = 3;
const int segCPin = 7;
const int segDPin = 9;
const int segEPin = 8;
const int segFPin = 5;
const int segGPin = 4;

void setup()
{
  // configure baudrate for debug use
  Serial.begin(baudrate);

  // configure Pins
  pinMode(segAPin, OUTPUT);
  pinMode(segBPin, OUTPUT);
  pinMode(segCPin, OUTPUT);
  pinMode(segDPin, OUTPUT);
  pinMode(segEPin, OUTPUT);
  pinMode(segFPin, OUTPUT);
  pinMode(segGPin, OUTPUT);
}

void blinkSegment(int pin)
{
  digitalWrite(pin, HIGH);
  digitalWrite(pin, LOW);
}

void loop()
{
  draw0();
  draw1();
  draw2();
  draw3();
  draw4();
  draw5();
  draw6();
  draw7();
  draw8();
  draw9();
  drawA();
  drawB();
  drawC();
  drawD();
  drawE();
  drawF();
  drawH();
  drawI();
  drawJ();
  drawL();
  drawN();
  drawO();
  drawP();
  drawT();
  drawU();
  drawY();
}
