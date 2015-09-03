/*
 * main.c
 *
 *  Created on: Sep 2, 2015
 *      Author: jim
 */



#include <avr/io.h>
#include <stdbool.h>
#include <stdint.h>
#include "../inc/main.h"



// function prototypes
bool buttonPressed(int, volatile uint8_t *);



void setup(void) {
	// initialize the digital pin as an output.
	DDRD &= ~sw1Mask; // set pin7, portD as input
	DDRB |=  ledMask; // set pin5, portB as output;
}

// the loop routine runs over and over again forever:
int main() {

	setup();

	bool currentLedState = false; // current stored state

	while(1)
	{
		if( buttonPressed(sw1Mask, &PIND) ) // if button is hit
		{
			if( currentLedState == false ) // if LED is off
			{
				PORTB = LEDON; // turn LED on
				currentLedState = true;
			}
			else if( currentLedState == true ) // LED is on
			{
				PORTB = LEDOFF; // turn LED off
				currentLedState = false;
			}
		}
	}
	return 0;

}
