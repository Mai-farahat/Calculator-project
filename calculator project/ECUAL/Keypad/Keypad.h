/*
 * Keypad.h
 *
 * Created: 07/02/2024 3:35:05 PM
 *  Author: MAI
 */ 
#ifndef KEYPAD_H_
#define KEYPAD_H_
// Section :INCLUDES
#include "./../../Utilities/Atmega32_Config.h"

// Section :Macro Declarations
#define R0 0
#define R1 1
#define R2 2
#define R3 3
#define C0 4
#define C1 5
#define C2 6
#define C3 7

#define keypad_PORT PORTD
#define keypad_PIN PIND
#define keypad_DDR DDRD

// Section: Keypad functions

void  Keypad_init();
char Keypad_getkey();
uint8_t Keypad_calculator(uint8_t operand_1, uint8_t operand_2, char oper);



#endif /* KEYPAD_H_ */