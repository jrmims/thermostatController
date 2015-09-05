/*
 * spi.c
 *
 *  Created on: Sep 4, 2015
 *      Author: jim
 *      library for spi functions
 *
 *      SPCR: SPI Control Register
 *      7: SPIE : enable SPI interrupt
 *      6: SPE : enable SPI
 *      5: DORD : data direction, 0 means most significant first sent/receive
 *      4: MSTR : Master (1), Slave (0)
 *      2: CPHA : Clock phase
 *      3: CPOL : Clock polarity
 *      1: SPR1 : SPI rate select
 *      0: SPR0 : SPI rate select
 *
 *      SPDR: SPI Data Register
 *      SPSR: SPI Status Register
 *      7: SPIF: SPI Interrupt Flag: Set when transfer is complete.
 *      6: WCOL: Write Collision: Set if SPDR is written to while transferring
 *      0: SPI2x: double the speed, not available on all AVR
 */
#include "../inc/spi.h"
#include <util/delay.h>

void openSPI(void)
{
	DDRB = 0x2F; //setup for serial SCK (output), MISO (input), MOSI (output), SS (output)
	SPCR = 0x50; // SPI enabled as Master, Mode0 at 4 MHz (16M/4)
}

void closeSPI(void)
{
	SPCR = 0x00; // clear SPI enable bit
}

uint8_t xferSPI (uint8_t data)
{
	SPDR = data; // put data on bus
	while( !(SPSR & 0x80) ); // wait for transfer complete bit to set
	return SPDR; // return new values received
}

