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

#ifndef SEGMENTS
# define SEGMENTS

# define SEGMENT_A 

#endif

void setup()
{
  pinMode(SER_PIN, OUTPUT);
  pinMode(RCLK_PIN, OUTPUT);
  pinMode(SRCLK_PIN, OUTPUT);
}

void writeRegisters()
{
  // set register low
  digitalWrite(RCLK_PIN, LOW);
  for (int i = NB_REGISTERS-1; i >= 0; i--)
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

void print0()
{
  setRegisterPin(QA, HIGH);
  setRegisterPin(QB, HIGH);
  setRegisterPin(QC, HIGH);
  setRegisterPin(QD, HIGH);
  setRegisterPin(QE, HIGH);
  setRegisterPin(QF, HIGH);
  setRegisterPin(QG, LOW);
  setRegisterPin(QH, LOW);
  writeRegisters();
}

void print1()
{
  setRegisterPin(QA, LOW);
  setRegisterPin(QB, HIGH);
  setRegisterPin(QC, HIGH);
  setRegisterPin(QD, LOW);
  setRegisterPin(QE, LOW);
  setRegisterPin(QF, LOW);
  setRegisterPin(QG, LOW);
  setRegisterPin(QH, LOW);
  writeRegisters();
}

void print2()
{
  setRegisterPin(QA, HIGH);
  setRegisterPin(QB, HIGH);
  setRegisterPin(QC, LOW);
  setRegisterPin(QD, HIGH);
  setRegisterPin(QE, HIGH);
  setRegisterPin(QF, LOW);
  setRegisterPin(QG, HIGH);
  setRegisterPin(QH, LOW);
  writeRegisters();
}

void print3()
{
  setRegisterPin(QA, HIGH);
  setRegisterPin(QB, HIGH);
  setRegisterPin(QC, HIGH);
  setRegisterPin(QD, HIGH);
  setRegisterPin(QE, LOW);
  setRegisterPin(QF, LOW);
  setRegisterPin(QG, HIGH);
  setRegisterPin(QH, LOW);
  writeRegisters();
}

void print4()
{
  setRegisterPin(QA, LOW);
  setRegisterPin(QB, HIGH);
  setRegisterPin(QC, HIGH);
  setRegisterPin(QD, LOW);
  setRegisterPin(QE, LOW);
  setRegisterPin(QF, HIGH);
  setRegisterPin(QG, HIGH);
  setRegisterPin(QH, LOW);
  writeRegisters();
}

void print5()
{
  setRegisterPin(QA, HIGH);
  setRegisterPin(QB, LOW);
  setRegisterPin(QC, HIGH);
  setRegisterPin(QD, HIGH);
  setRegisterPin(QE, LOW);
  setRegisterPin(QF, HIGH);
  setRegisterPin(QG, HIGH);
  setRegisterPin(QH, LOW);
  writeRegisters();
}

void print6()
{
  setRegisterPin(QA, HIGH);
  setRegisterPin(QB, LOW);
  setRegisterPin(QC, HIGH);
  setRegisterPin(QD, HIGH);
  setRegisterPin(QE, HIGH);
  setRegisterPin(QF, HIGH);
  setRegisterPin(QG, HIGH);
  setRegisterPin(QH, LOW);
  writeRegisters();
}

void print7()
{
  setRegisterPin(QA, HIGH);
  setRegisterPin(QB, HIGH);
  setRegisterPin(QC, HIGH);
  setRegisterPin(QD, LOW);
  setRegisterPin(QE, LOW);
  setRegisterPin(QF, LOW);
  setRegisterPin(QG, LOW);
  setRegisterPin(QH, LOW);
  writeRegisters();
}

void print8()
{
  setRegisterPin(QA, HIGH);
  setRegisterPin(QB, HIGH);
  setRegisterPin(QC, HIGH);
  setRegisterPin(QD, HIGH);
  setRegisterPin(QE, HIGH);
  setRegisterPin(QF, HIGH);
  setRegisterPin(QG, HIGH);
  setRegisterPin(QH, LOW);
  writeRegisters();
}

void print9()
{
  setRegisterPin(QA, HIGH);
  setRegisterPin(QB, HIGH);
  setRegisterPin(QC, HIGH);
  setRegisterPin(QD, HIGH);
  setRegisterPin(QE, LOW);
  setRegisterPin(QF, HIGH);
  setRegisterPin(QG, HIGH);
  setRegisterPin(QH, LOW);
  writeRegisters();
}

void loop() {
  print0();
  delay(1000);
  print1();
  delay(1000);
  print2();
  delay(1000);
  print3();
  delay(1000);
  print4();
  delay(1000);
  print5();
  delay(1000);
  print6();
  delay(1000);
  print7();
  delay(1000);
  print8();
  delay(1000);
  print9();
  delay(1000);
}
