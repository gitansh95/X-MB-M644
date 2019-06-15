#define F_CPU 18432000UL

#include <avr/io.h>
#include <util/delay.h>

#include <stdint.h>

//Port x

// DDRx = Data Direction Register
// 0   = Input
// 1   = Output

// PINx = Port IN (Read Input)
// Pin being read should be configured as input
// Else PINx will return the output value

// Input pins can be tri-stated (high impedance floating)
// or internally pulled up by setting the PORTx register
// when the pin is configured as an input.
// 0 = Tri-state
// 1 = Activate internal pullup

// We will configure input pins to tri-state mode as all our
// intended inputs have external pullup/pulldown resistors.

int main (void)
{
	uint16_t delay;

	DDRB  |= 0b00001000; //Set Port B pin 3 as output
	PORTB |= 0b00001000; //Initially switch off the led


	while (1)
	{
		if (PINB & 0b00010000)
		{
			// If Port B pin 4 is one (switch not pressed)
			// set delay to 1000 ms
			delay = 1000;
		}
		else
		{
			// If Port B pin 4 is zero (switch pressed)
			// set delay to 200 ms
			delay = 200;
		}

		PORTB &= ~0b00001000; //Switch on the led
		_delay_ms(delay);
		PORTB |= 0b00001000; //Switch off the led
		_delay_ms(delay);
	}
}