#define F_CPU 18432000UL

#include <avr/io.h>
#include <util/delay.h>

// DDR = Data Direction Register
// 1   = Output
// 0   = Input

int main (void)
{

    DDRB  |= 0b00001000; //Set Port B pin 3 as output
    PORTB |= 0b00001000; //Initially switch off the led


    while (1)
    {
        PORTB &= ~0b00001000; //Switch on the led
        _delay_ms(1000);
        PORTB |= 0b00001000; //Switch off the led
        _delay_ms(1000);
    }
}