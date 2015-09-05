/*
 * spi.h
 *
 *  Created on: Sep 4, 2015
 *      Author: jim
 */

#ifndef SPI_H_
#define SPI_H_

#include <avr/io.h>

//function prototypes
void OpenSPI(void);
void CloseSPI(void);
uint8_t XferSPI (uint8_t data);


#endif /* SPI_H_ */
