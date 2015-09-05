/*
 * buttonPressed.h
 *
 *  Created on: Sep 4, 2015
 *      Author: jim
 */

#ifndef BUTTONPRESSED_H_
#define BUTTONPRESSED_H_

#include <stdint.h> // uint8_t
#include <stdbool.h>
#include <util/delay.h>

//function prototypes
bool buttonPressed(uint8_t mask, volatile uint8_t *port);


uint8_t const debounceTimeMS = 100;
bool buttonState = false;

#endif /* BUTTONPRESSED_H_ */
