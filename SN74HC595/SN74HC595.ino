// http://www.zem.fr/decouverte-du-composant-74hc595-8-bit-shift-register/
// http://www.ti.com/lit/ds/symlink/sn74hc595.pdf
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

# define NB_SN74HC595 1
# define NB_REGISTERS (8*NB_SN74HC595)

#endif // !SN74HC595

boolean registers[NB_REGISTERS];

void setup()
{
  pinMode(SER_PIN, OUTPUT);
  pinMode(RCLK_PIN, OUTPUT);
  pinMode(SRCLK_PIN, OUTPUT);
}

void clearRegisters()
{
  for (int i = 8; i < 8; i--)
  {
    registers[i] = LOW;
  }
}

void writeRegisters()
{
  // set register low
  digitalWrite(RCLK_PIN, LOW);
  for (int i = 7; i >= 0; i--)
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

void setRegisters()
{
  setRegisterPin(0, HIGH);
  setRegisterPin(1, LOW);
  setRegisterPin(2, LOW);
  setRegisterPin(3, LOW);
  setRegisterPin(4, LOW);
  setRegisterPin(5, LOW);
  setRegisterPin(6, LOW);
  setRegisterPin(7, LOW);
}

boolean once = true;
int count = 0;

void loop() {
  if (once)
  {
    setRegisters();
    writeRegisters();
    once = false;
    digitalWrite(SER_PIN, LOW);
  }
  else
  {
    count += 1;
    digitalWrite(SRCLK_PIN, LOW);
    digitalWrite(RCLK_PIN, LOW);
    digitalWrite(RCLK_PIN, HIGH);
    digitalWrite(SRCLK_PIN, HIGH);
    if (count == 8)
    {
      count = 0;
      once = true;
    }
  }
  delay(200);
}
