/*
** Counting variations of
** distances to count people
** passing in range of ultra sonic captor
** and prompting them on a segment prompt
*/

// HC-SR04 Ultrasonic Distance
#ifndef HC_SR04
# define HC_SR04

# define SOUND_SPEED 0.0344 // cm*ms^-1
# define TRIGGER_PIN 11
# define ECHO_PIN 12

#endif // !HC_SR04

// SN74HC595
// SER    : serial input and serial output for cascading
// SRCLK  : shift register clock
// OE     : Output enable (if high, outputs are in high-impedance state = disabled)
// RCLK   : storage register clock
// SRCLR  : direct overriding clear (if low)
// VCC    : Power pin
// GND    : ground

#ifndef SN74HC595
# define SN74HC595
// pin assignation on arduino uno
# define SER_PIN 8
# define RCLK_PIN 9
# define SRCLK_PIN 10

# define QA 0
# define QB 1
# define QC 2
# define QD 3
# define QE 4
# define QF 5
# define QG 6
# define QH 7

# define NB_SN74HC595 1
# define NB_REGISTERS (8*NB_SN74HC595)

#endif // !SN74HC595

boolean registers[NB_REGISTERS];

#ifndef COUNTING_PEOPLE
# define COUNTING_PEOPLE

# define BAUDRATE 9600
# define CALIBRATION_TIME 50000 // in ms

#endif // !COUTING_PEOPLE

void setupSN74HC595()
{
  pinMode(SER_PIN, OUTPUT);
  pinMode(RCLK_PIN, OUTPUT);
  pinMode(SRCLK_PIN, OUTPUT);
}

void writeRegisters()
{
  // set register low
  digitalWrite(RCLK_PIN, LOW);
  for (int i = NB_REGISTERS - 1; i >= 0; i--)
  {
    // prepare clock
    digitalWrite(SRCLK_PIN, LOW);
    // set bit state
    digitalWrite(SER_PIN, registers[i]);
    // clock tick
    digitalWrite(SRCLK_PIN, HIGH);
  }
  // register bit state
  digitalWrite(RCLK_PIN, HIGH);
}

void setRegisterPin(int index, int value)
{
  registers[index] = value;
}

void printValue(int qa, int v_qa,
                int qb, int v_qb,
                int qc, int v_qc,
                int qd, int v_qd,
                int qe, int v_qe,
                int qf, int v_qf,
                int qg, int v_qg,
                int qh, int v_qh)
{
  setRegisterPin(qa, v_qa);
  setRegisterPin(qb, v_qb);
  setRegisterPin(qc, v_qc);
  setRegisterPin(qd, v_qd);
  setRegisterPin(qe, v_qe);
  setRegisterPin(qf, v_qf);
  setRegisterPin(qg, v_qg);
  setRegisterPin(qh, v_qh);
  writeRegisters();
}

void print0()
{
  printValue(QA, HIGH,
             QB, HIGH,
             QC, HIGH,
             QD, HIGH,
             QE, HIGH,
             QF, HIGH,
             QG, LOW,
             QH, LOW);
}

void print1()
{
  printValue(QA, LOW,
             QB, HIGH,
             QC, HIGH,
             QD, LOW,
             QE, LOW,
             QF, LOW,
             QG, LOW,
             QH, LOW);
}

void print2()
{
  printValue(QA, HIGH,
             QB, HIGH,
             QC, LOW,
             QD, HIGH,
             QE, HIGH,
             QF, LOW,
             QG, HIGH,
             QH, LOW);
}

void print3()
{
  printValue(QA, HIGH,
             QB, HIGH,
             QC, HIGH,
             QD, HIGH,
             QE, LOW,
             QF, LOW,
             QG, HIGH,
             QH, LOW);
}

void print4()
{
  printValue(QA, LOW,
             QB, HIGH,
             QC, HIGH,
             QD, LOW,
             QE, LOW,
             QF, HIGH,
             QG, HIGH,
             QH, LOW);
}

void print5()
{
  printValue(QA, HIGH,
             QB, LOW,
             QC, HIGH,
             QD, HIGH,
             QE, LOW,
             QF, HIGH,
             QG, HIGH,
             QH, LOW);
}

void print6()
{
  printValue(QA, HIGH,
             QB, LOW,
             QC, HIGH,
             QD, HIGH,
             QE, HIGH,
             QF, HIGH,
             QG, HIGH,
             QH, LOW);
}

void print7()
{
  printValue(QA, HIGH,
             QB, HIGH,
             QC, HIGH,
             QD, LOW,
             QE, LOW,
             QF, LOW,
             QG, LOW,
             QH, LOW);
}

void print8()
{
  printValue(QA, HIGH,
             QB, HIGH,
             QC, HIGH,
             QD, HIGH,
             QE, HIGH,
             QF, HIGH,
             QG, HIGH,
             QH, LOW);
}

void print9()
{
  printValue(QA, HIGH,
             QB, HIGH,
             QC, HIGH,
             QD, HIGH,
             QE, LOW,
             QF, HIGH,
             QG, HIGH,
             QH, LOW);
}

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
  delay(10);
  return ((duration / 2) * SOUND_SPEED);
}

unsigned long startTime = 0;
void setup()
{
  Serial.begin(BAUDRATE);

  setupHC_SR04();
  setupSN74HC595();
  startTime = millis();
}

float minDist = 10000.F;
int nb_people = 0;

void loop()
{
  float distance = getDistanceInCM();
  if ((millis() - startTime) < CALIBRATION_TIME)
  {
    if (minDist > distance && distance > 0.F)
    {
      Serial.println();
      Serial.print("old min dist: ");
      Serial.print(minDist);
      Serial.println(" cm");
      Serial.print("new min: ");
      Serial.print(distance);
      Serial.println(" cm");
      Serial.println();
      minDist = distance;
    }
    Serial.print(".");
  }
  else
  {
    if (distance < minDist)
    {
      nb_people += 1;
    }
    Serial.print(nb_people);
    Serial.println(" people");
    Serial.println();
    if (nb_people == 0)
    {
      print0();
    } else if (nb_people == 1)
    {
      print1();
    } else if (nb_people == 2)
    {
      print2();
    } else if (nb_people == 3)
    {
      print3();
    } else if (nb_people == 4)
    {
      print4();
    } else if (nb_people == 5)
    {
      print5();
    } else if (nb_people == 6)
    {
      print6();
    }else if (nb_people == 7)
    {
      print7();
    } else if (nb_people == 8)
    {
      print8();
    } else if (nb_people == 9)
    {
      print9();
    }
  }
  /*
    Serial.print(distance);
    Serial.println(" cm");
    Serial.println();
  */
  delay(500);
}
