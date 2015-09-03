/*
 * buttonState.h
 *
 *  Created on: Sep 2, 2015
 *      Author: jim
 *
 *      Checks for 0 to 1 transition, with debouncing
 */

#ifndef BUTTONSTATE_H_
#define BUTTONSTATE_H_

#include <stdint.h> // uint8_t
#include <stdbool.h>
uint8_t const debounceTimeMS = 100;
bool buttonState = false;

#endif /* BUTTONSTATE_H_ */
