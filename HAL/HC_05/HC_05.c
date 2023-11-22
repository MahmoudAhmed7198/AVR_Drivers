/*
 * HC_05.c
 *
 *  Created on: Nov 15, 2023
 *      Author: Lenovo
 */
#include<util/delay.h>
#include<stdio.h>
#include"../../Std_Types.h"
#include"HC_05.h"
#include"../../MCAL/UART/uart.h"
void sendATCommand(const uint8_t* command) {
    // Use your UART library to send the command
	UART_sendString(command);
	UART_sendByte('\r');
	UART_sendByte('\n');
	_delay_ms(500);
}
void receiveResponse() {
    char response[256];  // Adjust the buffer size based on your needs
    uint8_t index = 0;

    // Use your UART library to receive characters until a newline character is encountered
    char receivedChar = UART_recieveByte();
    while (receivedChar != '\n') {
        response[index++] = receivedChar;
        receivedChar = UART_recieveByte();
    }

    // Null-terminate the response string
    response[index] = '\0';

    // Print the response
    printf("Response: %s\n", response);
}
