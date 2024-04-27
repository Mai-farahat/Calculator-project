/*
 * calculator project.c
 *
 * Created: 24/02/2024 5:39:50 PM
 * Author : MAI
 */ 

#include <avr/io.h>
#include "ECUAL/Keypad/Keypad.h"
#include "ECUAL/LCD/LCD.h"
int main(void)
{
	char key , second_key;
	uint8_t oper_1 =0, oper_2 =0;
	uint8_t res;
	char flag = 0 , operator_m = '@';
	
	LCD_8_bit_init();
	Keypad_init();
	
	LCD_8_bit_sendString("calculator :");
	_delay_ms(200);
	LCD_8_bit_sendCommand(LCD_CLEAR_SCREEN);
	
	/* Replace with your application code */
	while (1)
	{
		if (flag = 0)
		{
			key = Keypad_getkey();
		}
		if (flag = 1)
		{
			second_key =Keypad_getkey();
			key = second_key;
		}
		switch(key)
		{
			case('M'):
			{
				break;	
			}
			case('#'):
			{
				LCD_8_bit_sendCommand(LCD_CLEAR_SCREEN);
				oper_1 =0;
				oper_2 =0;
				flag =0;
				operator_m = '@';
				break;
			}
			default:
			{
				LCD_8_bit_sendChar(key);
				if(key == '=')
				{
					LCD_GotoXY(2,0);
					res = Keypad_calculator(oper_1,oper_2,operator_m);
					LCD_display_number(res);
					oper_1 = 0;
					oper_2 = 0;
					flag = 0;
					operator_m = '@';
					
				}
				else if((key == '+' ) || (key ==  '-') || (key==  '*') || (key ==  '/') )
				{
					operator_m = key;
					flag = 1;
				}
				else if (key >= '0' && key <= '9'&& operator_m == '@')
				{
					oper_1 = oper_1 * 10 + (key-'0');
				}
				else if (key >= '0' && key <= '9' && operator_m != '@')
				{
					oper_2 = oper_2 * 10 + (key-'0');
				}
				break;	
			}
		}
	}
}

