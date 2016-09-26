/*
 * UART_RX.c
 *
 *  Created on: 24/09/2016
 *  Author: D. O. Corlett
 *
 *	Receives a serial message and sends it back on the serial port.
 */

#include <avr/io.h>
#include "libser.h"

int main()
{
	char con[1024];		// Define display string
	int num = 0;		// Define a number variable to be incremented on the transmitted message
	uart0_init(96);		// Initalise the serial communication at a board rate of 9600 Hz

	while(1)
	{
		uart0_gets(con, sizeof(con));					// Receive serial communication from PC.
		snprintf(con,sizeof(con), "%s%i", con, num++);	// Modify the received message to confirm that it has passed through the Arduino and not just looped back to the PC.
		uart0_puts(con);								// Transmit received serial data back to the PC.
	}
	return 0;
}
