#include <LiquidCrystal.h>

// LCM 1602C LCD screen
#ifndef LCM_1602C
# define LCM_1602C

# define RS_PIN 7
# define EN_PIN 8
# define DB4_PIN 9
# define DB5_PIN 10
# define DB6_PIN 11
# define DB7_PIN 12

#endif // !LCM_1602C

// initialize the library
LiquidCrystal lcd(RS_PIN, EN_PIN, DB4_PIN, DB5_PIN, DB6_PIN, DB7_PIN);

void setupLCM1602C()
{
  // set up the LCD's number of columns and rows
  lcd.begin(16, 2);
}

// HC-SR04 Ultrasonic Distance
#ifndef HC_SR04
# define HC_SR04

# define SOUND_SPEED 0.0344 // cm*ms^-1
# define TRIGGER_PIN 5
# define ECHO_PIN 6

#endif // !HC_SR04

#ifndef COUNTING_PASSAGES
# define COUNTING_PASSAGES

# define CALIBRATION_TIME 50000 // in ms

#endif // !COUNTING_PASSAGES

void setupHC_SR04()
{
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

float getDistanceInCM()
{
  digitalWrite(TRIGGER_PIN, HIGH);
  delay(5);
  digitalWrite(TRIGGER_PIN, LOW);

  int duration = pulseIn(ECHO_PIN, HIGH);
  delay(5);
  return ((duration / 2) * SOUND_SPEED);
}

unsigned long startTime = 0;
void setup() {
  /*
   * DEBUG
  Serial.begin(9600);
  */
  setupHC_SR04();
  setupLCM1602C();
  startTime = millis();
  calibrate();
}

float maxDist = -10000.F;
float minDist = 10000.F;
float delta = 0.F;
int nb_people = 0;
boolean state = HIGH;

void calibrate()
{
  lcd.setCursor(0, 0);
  lcd.print("Calibration");
  lcd.setCursor(0, 1);
  lcd.print("Please wait.");

  while ((millis() - startTime) < CALIBRATION_TIME)
  {
    float distance = getDistanceInCM();
    if (minDist > distance) minDist = distance;
    if (maxDist < distance) maxDist = distance;
  }
  delta = maxDist - minDist;
/*
 * DEBUG
  Serial.print("maxDist: ");
  Serial.print(maxDist);
  Serial.println();
  Serial.print("minDist: ");
  Serial.print(minDist);
  Serial.println();
  Serial.print("delta: ");
  Serial.print(delta);
  Serial.println();
*/
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Passages");
}

void loop() {
  float distance = getDistanceInCM();
  /*
   * DEBUG
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println();
  */
  if (distance >= 0.F)
  {
    if ((distance < (minDist - delta * 10)) && (state == HIGH))
    {
      state = LOW;
    }
    else if ((distance >= minDist) && (state == LOW))
    {
      state = HIGH;
      nb_people += 1;
    }
    lcd.setCursor(0, 1);
    lcd.print(nb_people);
  }
  delay(300);
}
