#include <Arduino.h>

// put function declarations here:
uint8_t value;

void setup() {
  // PD7 - PD4 as inputs
  DDRD &= 0x0F;
  // enable pull-up resistors
  PORTD |= 0xF0;
  // PD3 - PD0 as outputs
  DDRB &= 0x0F;

  Serial.begin(9600);
}

void loop() {
  // Read PortD
  value = PIND;

  //set PD7-PD4
  value &= 0xF0;

  //Shift by 4 bits
  value >>=4;

  // Invert value to correct pullup logic
  value = ~value;

  // add mask and keep only 4 bits
  value &= 0x0F;

  //Display on LED
  PORTB = value;

  Serial.print ("Binary:");
  Serial.println(value, BIN);
  Serial.print("Decimal:");
  Serial.println(value);
  delay(500);
}

