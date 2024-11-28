/*
 * LCD_prog.c
 *
 *  Created on: Nov 24, 2024
 *      Author: User
 */
#include"stdTypes.h"
#include"errorState.h"

#include"DIO_int.h"

#include"LCD_priv.h"
#include"LCD_cofig.h"
#include"util/delay.h"



ES_ERROR LCD_enuInit(void)
{
	ES_ERROR local_enuErrorState = ES_OK;

local_enuErrorState|=DIO_enuSetpindir(RS_PORT, RS_PIN, DIO_u8OUTPUT);
local_enuErrorState|=DIO_enuSetpindir(RW_PORT, RW_PIN, DIO_u8OUTPUT);
local_enuErrorState|=DIO_enuSetpindir(EN_PORT, EN_PIN, DIO_u8OUTPUT);

local_enuErrorState|=DIO_enuSetpindir(D7_PORT, D7_PIN, DIO_u8OUTPUT);
local_enuErrorState|=DIO_enuSetpindir(D6_PORT, D6_PIN, DIO_u8OUTPUT);
local_enuErrorState|=DIO_enuSetpindir(D5_PORT, D5_PIN, DIO_u8OUTPUT);
local_enuErrorState|=DIO_enuSetpindir(D4_PORT, D4_PIN, DIO_u8OUTPUT);

	_delay_ms(35);

#if LCD_MODE == EIGHT_BIT

local_enuErrorState|=DIO_enuSetpindir(D3_PORT, D3_PIN, DIO_u8OUTPUT);
local_enuErrorState|=DIO_enuSetpindir(D2_PORT, D2_PIN, DIO_u8OUTPUT);
local_enuErrorState|=DIO_enuSetpindir(D1_PORT, D1_PIN, DIO_u8OUTPUT);
local_enuErrorState|=DIO_enuSetpindir(D0_PORT, D0_PIN, DIO_u8OUTPUT);

	//function set
local_enuErrorState|=LCD_INIT_SendCommend(0x38);
#elif LCD_MODE == FOUR_BIT
local_enuErrorState|=LCD_INIT_SendCommend(0x28);
#endif
	_delay_ms(1);
	local_enuErrorState|=LCD_INIT_SendCommend(0x0f);
	_delay_ms(1);
	local_enuErrorState|=LCD_INIT_SendCommend(0x01);
	_delay_ms(2);
	local_enuErrorState|=LCD_INIT_SendCommend(0x06);






	return local_enuErrorState;
}

ES_ERROR LCD_enuDisplayChar(u8 Copy_u8Data)
{

	//LCD_setCusor( copyu8_row, copy_u8_column);
	ES_ERROR local_enuErrorState = ES_OK;

local_enuErrorState|=	DIO_enuSetpinval(RS_PORT , RS_PIN , DIO_u8HIGH);

local_enuErrorState|=LCD_inerSendData(Copy_u8Data);

	return local_enuErrorState;
}

ES_ERROR LCD_enuSendCommand(u8 Copy_u8Command)
{
	ES_ERROR local_enuErrorState = ES_OK;

	// set rs as command
	local_enuErrorState|=DIO_enuSetpinval(RS_PORT , RS_PIN , DIO_u8LOW);

	local_enuErrorState|=LCD_inerSendData(Copy_u8Command);


	return local_enuErrorState;
}

static ES_ERROR LCD_inerSendData(u8 Copy_u8Data)
{    ES_ERROR local_enuErrorState=ES_OK;
	// set rw as write operation , EN is low
local_enuErrorState|=DIO_enuSetpinval(RW_PORT , RW_PIN , DIO_u8LOW);
local_enuErrorState|=DIO_enuSetpinval(EN_PORT , EN_PIN , DIO_u8LOW);
	//write Data
local_enuErrorState|=DIO_enuSetpinval(D7_PORT , D7_PIN , ((Copy_u8Data>>7)&1));
local_enuErrorState|=DIO_enuSetpinval(D6_PORT , D6_PIN , ((Copy_u8Data>>6)&1));
local_enuErrorState|=DIO_enuSetpinval(D5_PORT , D5_PIN , ((Copy_u8Data>>5)&1));
local_enuErrorState|=DIO_enuSetpinval(D4_PORT , D4_PIN , ((Copy_u8Data>>4)&1));

#if LCD_MODE == EIGHT_BIT

local_enuErrorState|=DIO_enuSetpinval(D3_PORT , D3_PIN , ((Copy_u8Data>>3)&1));
local_enuErrorState|=DIO_enuSetpinval(D2_PORT , D2_PIN , ((Copy_u8Data>>2)&1));
local_enuErrorState|=DIO_enuSetpinval(D1_PORT , D1_PIN , ((Copy_u8Data>>1)&1));
local_enuErrorState|=DIO_enuSetpinval(D0_PORT , D0_PIN , ((Copy_u8Data>>0)&1));

#elif LCD_MODE == FOUR_BIT

#endif

	// Enable latch
local_enuErrorState|=DIO_enuSetpinval(EN_PORT , EN_PIN , DIO_u8HIGH);
	_delay_ms(10);
local_enuErrorState|=DIO_enuSetpinval(EN_PORT , EN_PIN , DIO_u8LOW);


	_delay_ms(10);
	return local_enuErrorState;
}


static inline ES_ERROR LCD_INIT_SendCommend(u8 Copy_u8Command)
{      ES_ERROR local_enuErrorState=ES_OK;
	// set rs as command
local_enuErrorState|=DIO_enuSetpinval(RS_PORT , RS_PIN , DIO_u8LOW);
	// set rw as write operation , EN is low
local_enuErrorState|=DIO_enuSetpinval(RW_PORT , RW_PIN , DIO_u8LOW);
local_enuErrorState|=DIO_enuSetpinval(EN_PORT , EN_PIN , DIO_u8LOW);
	//write Data
local_enuErrorState|=DIO_enuSetpinval(D7_PORT , D7_PIN , ((Copy_u8Command>>7)&1));
local_enuErrorState|=DIO_enuSetpinval(D6_PORT , D6_PIN , ((Copy_u8Command>>6)&1));
local_enuErrorState|=DIO_enuSetpinval(D5_PORT , D5_PIN , ((Copy_u8Command>>5)&1));
local_enuErrorState|=DIO_enuSetpinval(D4_PORT , D4_PIN , ((Copy_u8Command>>4)&1));
#if LCD_MODE == EIGHT_BIT
local_enuErrorState|=DIO_enuSetpinval(D3_PORT , D3_PIN , ((Copy_u8Command>>3)&1));
local_enuErrorState|=DIO_enuSetpinval(D2_PORT , D2_PIN , ((Copy_u8Command>>2)&1));
local_enuErrorState|=DIO_enuSetpinval(D1_PORT , D1_PIN , ((Copy_u8Command>>1)&1));
local_enuErrorState|=DIO_enuSetpinval(D0_PORT , D0_PIN , ((Copy_u8Command>>0)&1));
#elif  LCD_MODE == FOUR_BIT

#endif
	// Enable latch
local_enuErrorState|=DIO_enuSetpinval(EN_PORT , EN_PIN , DIO_u8HIGH);
	_delay_ms(10);
	local_enuErrorState|=DIO_enuSetpinval(EN_PORT , EN_PIN , DIO_u8LOW);
return local_enuErrorState;
}


ES_ERROR LCD_enuDisplayString(u8 *pcopy_u8string){

	ES_ERROR local_enuErrorState = ES_OK;

	if(pcopy_u8string!=NULL)
	{

		while((*pcopy_u8string)!='\0'){

		local_enuErrorState|=	DIO_enuSetpinval(RS_PORT , RS_PIN , DIO_u8HIGH);

				LCD_inerSendData(*pcopy_u8string);
				pcopy_u8string++;
		}

	}
	else
	{
		local_enuErrorState = ES_NULL_POINTER;
	}


		return local_enuErrorState;
}

/////////////////////////////////////////////////////////////////////////////////////////


ES_ERROR LCD_enuDisplayNum(u32 copyu32_num)
{      ES_ERROR local_u8errorState=ES_OK;
	 u8 local_u8AnumArr[10],local_u8NumIter=0,local_u8DisIter=0;
		   if(copyu32_num == 0)
		   {
			   local_u8errorState|=  LCD_enuDisplayChar('0');
		   }
		   else
		   {
			   while(copyu32_num)
			   {
				   local_u8AnumArr[local_u8NumIter]=copyu32_num%10+'0';
				   copyu32_num/=10;
					local_u8NumIter++;
			   }
			   for(local_u8DisIter=local_u8NumIter;local_u8DisIter>0;local_u8DisIter--)
			   {
				   local_u8errorState|= LCD_enuDisplayChar(local_u8AnumArr[local_u8DisIter-1]);
			   }
		   }
		   return  local_u8errorState;
}





 void LCD_setCusor(u8 copyu8_row,u8 copy_u8_column)
{      copy_u8_column--;

		switch(copyu8_row){
		            case ROW1:  LCD_enuSendCommand((0x80 + copy_u8_column)); break;
		            case ROW2:  LCD_enuSendCommand((0xc0 +copy_u8_column)); break;
		            default:;
		        }


}

ES_ERROR LCD_enuClear()
{
	ES_ERROR local_u8errorState=ES_OK;
	local_u8errorState|=LCD_enuSendCommand(0x01);

return local_u8errorState;

}





ES_ERROR LCD_enuDisplayCharPOS(u8 Copy_u8Data,u8 copyu8_row,u8 copy_u8_column){

	LCD_setCusor(copyu8_row, copy_u8_column);
	LCD_enuDisplayChar(Copy_u8Data);
return ES_OK;
}

ES_ERROR LCD_enuDisplayStringPOS(u8 *pcopy_u8string,u8 copyu8_row,u8 copy_u8_column){
	LCD_setCusor(copyu8_row, copy_u8_column);
	LCD_enuDisplayString(pcopy_u8string);
	return ES_OK;
}

ES_ERROR LCD_enuDisplayNumPOS(u32 copyu32_num,u8 copyu8_row,u8 copy_u8_column){
	LCD_setCusor(copyu8_row, copy_u8_column);
	LCD_enuDisplayNum(copyu32_num);
	return ES_OK;
}













