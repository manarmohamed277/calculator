/*
 * KEYPAD_prog.c
 *
 *  Created on: Nov 24, 2024
 *      Author: User
 */
#include "..\stdTypes.h"
#include "..\errorState.h"
#include<util/delay.h>
#include"..\MCAL\DIO_int.h"

#include "KEYPAD_config.h"
#include "KEYPAD_priv.h"



void KEYPAD_Init(void) {

    DIO_enuSetpindir(DIO_u8PORTC, DIO_u8PIN4, DIO_u8INPUT);
    DIO_enuSetpindir(DIO_u8PORTC, DIO_u8PIN5, DIO_u8INPUT);
    DIO_enuSetpindir(DIO_u8PORTC, DIO_u8PIN6, DIO_u8INPUT);
    DIO_enuSetpindir(DIO_u8PORTC, DIO_u8PIN7, DIO_u8INPUT);

    DIO_enuSetpindir(DIO_u8PORTC, DIO_u8PIN0,  DIO_u8OUTPUT);
    DIO_enuSetpindir(DIO_u8PORTC, DIO_u8PIN1, DIO_u8OUTPUT );
    DIO_enuSetpindir(DIO_u8PORTC, DIO_u8PIN2, DIO_u8OUTPUT );
    DIO_enuSetpindir(DIO_u8PORTC, DIO_u8PIN3, DIO_u8OUTPUT );

    DIO_enuSetpinval(DIO_u8PORTC, DIO_u8PIN4, DIO_u8PULLUP);
    DIO_enuSetpinval(DIO_u8PORTC, DIO_u8PIN5, DIO_u8PULLUP);
    DIO_enuSetpinval(DIO_u8PORTC, DIO_u8PIN6, DIO_u8PULLUP);
    DIO_enuSetpinval(DIO_u8PORTC, DIO_u8PIN7, DIO_u8PULLUP);
}












u8 KEYPAD_enuGetpressedKey(void)
{

    u8 local_u8pressedKey= KEYPAD_NO_PRESSED_KEY;
static	u8 local_u8ketpadArr[4][4]=KEYPAD_ARR;
static	u8 local_u8AkeypadColumnArr[COLUMN_NUM]={KEYPAD_COLUMN0_PIN ,KEYPAD_COLUMN1_PIN ,KEYPAD_COLUMN2_PIN,KEYPAD_COLUMN3_PIN};
static	u8 local_u8AkeypadRowArr[ROW_NUM]={KEYPAD_ROW0_PIN ,KEYPAD_ROW1_PIN ,KEYPAD_ROW2_PIN,KEYPAD_ROW3_PIN};

	u8 local_u8ColumnIter=0;
	u8 local_u8RowIter=0;

  for(local_u8ColumnIter=0;local_u8ColumnIter<COLUMN_NUM;local_u8ColumnIter++)
  {
	  //activate currant column
	   DIO_enuSetpinval(KEYPAD_PORT,local_u8AkeypadColumnArr[local_u8ColumnIter],DIO_u8LOW);
	  // _delay_ms(10);
       for(local_u8RowIter=0; local_u8RowIter<ROW_NUM; local_u8RowIter++)
       {
    	   u8 local_u8RowVal=KEYPAD_NO_PRESSED_KEY;
    	   DIO_enugetpinval(KEYPAD_PORT,local_u8AkeypadRowArr[local_u8RowIter],&local_u8RowVal);

    	 //check if switch is pressed
    	   if(local_u8RowVal==DIO_u8LOW){
    		  local_u8pressedKey=local_u8ketpadArr[local_u8RowIter][local_u8ColumnIter];
    	   //polling until the key is released
    	   while(local_u8RowVal==DIO_u8LOW)
    	    {
    	    	DIO_enugetpinval(KEYPAD_PORT,local_u8AkeypadRowArr[local_u8RowIter],&local_u8RowVal);


    	    }
    	   return local_u8pressedKey;

       }
       }
       //deactivate currant column
       DIO_enuSetpinval(KEYPAD_PORT,local_u8AkeypadColumnArr[local_u8ColumnIter],DIO_u8HIGH);


  }

  return local_u8pressedKey;
}
