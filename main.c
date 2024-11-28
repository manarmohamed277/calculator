/*
 * main.c
 *
 *  Created on: Nov 26, 2024
 *      Author: User
 */
#include "stdTypes.h"
#include"errorState.h"
#include"DIO_int.h"
#include"KEYPAD_int.h"
#include"LCD_int.h"
#include"app.h"
int main(void){

app();

	/*LCD_enuInit();

	LCD_enuDisplayChar('A');
	//LCD_enuDisplayString("MANAR");
	LCD_enuDisplayNumPOS(56,2,5);
	while(1);*/


	return 1;
}
