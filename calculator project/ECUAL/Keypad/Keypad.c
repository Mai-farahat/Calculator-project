/*
 * Keypad.c
 *
 * Created: 07/02/2024 3:35:24 PM
 *  Author: MAI
 */ 
// Section :INCLUDES
#include "Keypad.h"
uint8_t Keypad_Row[4] = {R0, R1, R2, R3};
uint8_t Keypad_Col[4] = {C0, C1, C2, C3};
/*
* @FN			:Keypad_init
* @brief		:initialization  Keypad
* @param(in)	:none
* @retval		:none
* @Note		:none
*/
void  Keypad_init()
{
	keypad_DDR &= ~ (1<<R0)|(1<<R1)|(1<<R2)|(1<<R3); //set upper part of keypad port as input
	keypad_DDR |= ((1<<C0)|(1<<C1)|(1<<C2)|(1<<C3));//set lower part of keypad port as output.
	//This is the part of the keypad port where the rows are connected.
	keypad_PORT = 0xFF ;
}
/*
* @FN			:Keypad_getkey
* @brief		:get key function
* @param(in)	:none
* @retval		:char
* @Note		    :none
*/
char Keypad_getkey()
{
	uint8_t C , R;
	for(C = 0; C < 4; C++)
	{
		keypad_PORT |= ((1<<Keypad_Col[0] ) | (1<<Keypad_Col[1] ) | (1<<Keypad_Col[2] ) | (1<<Keypad_Col[3] ));
		keypad_PORT &= ~ (1 << Keypad_Col[C]);
		for(R = 0; R < 4; R++)
		{
			if(!(keypad_PIN & (1<<Keypad_Row[R])))
			{
				while(!(keypad_PIN & (1<<Keypad_Row[R])));
				switch(C)
				{
					case(0):
					{
						if (R == 0) return '7';
						else if (R == 1) return '4';
						else if (R == 2) return '1';
						else if (R == 3) return '#';
						break;
					}
					case(1):
					{
						if (R == 0) return '8';
						else if (R == 1) return '5';
						else if (R == 2) return '2';
						else if (R == 3) return '0';
						break;
					}
					case(2):
					{
						if (R == 0) return '9';
						else if (R == 1) return '6';
						else if (R == 2) return '3';
						else if (R == 3) return '=';
						break;
					}
					case(3):
					{
						if (R == 0) return '/';
						else if (R == 1) return '*';
						else if (R == 2) return '-';
						else if (R == 3) return '+';
						break;
					}
					
				}
			}
		}
	}
return 'M'; //Return 'M' if no key is pressed.
}


uint8_t Keypad_calculator(uint8_t operand_1, uint8_t operand_2, char oper)
{
	uint8_t result = 0;
	if (oper == '+')
	{
		result = operand_1 + operand_2;
	}
	else if (oper == '-')
	{
		result = operand_1 - operand_2;
	}
	else if (oper == '*')
	{
		result = operand_1 * operand_2;
	}
	else if ((oper == '/') && (operand_2 != 0 ))
	{
		result = operand_1 / operand_2;
	}
	return result;
}