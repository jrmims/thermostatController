/*
 * buttonState.c
 *
 *  Created on: Sep 2, 2015
 *      Author: jim
 *
 *      Checks for 0 to 1 transition, with debouncing
 */

#include "../inc/buttonPressed.h"
#include <util/delay.h>

bool buttonPressed(int mask, volatile uint8_t *port)
{
	buttonState = (bool)(mask & ~*port);
	if (buttonState == false) // currently 0
	{
		_delay_ms(debounceTimeMS); // wait 100ms
		buttonState = (bool)(mask & ~*port);
		if (buttonState == true)
		{
			return true;
		}
	}
	return false; // no 0 to 1 transition
}
