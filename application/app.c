/*
 * app.c
 *
 *  Created on: Nov 26, 2024
 *      Author: User
 */
#include "../stdTypes.h"
#include<util/delay.h>
#include"../errorState.h"
#include"../MCAL/DIO_int.h"
#include"../HAL/KEYPAD_int.h"
#include"../HAL/LCD_int.h"

void arrToNum(u8*ptr1,u8*ptr2,u8 n1,u8 n2,u8 operation);
void app(){
DIO_enuInit();
LCD_enuInit();
 KEYPAD_Init();
/*enter pass*/
u8 kp_pass= KP_NO_PRESSED_KEY; u8 pass_nums=0;
u8 pass_nums_arr[16];
u8 pass_ch_nums_arr[16];
LCD_enuDisplayStringPOS("enter password",1,2);

//STAY HERE UNTIL THE KET GET PRESSED
 while(1){
do{
	 kp_pass=KEYPAD_enuGetpressedKey();
}while(kp_pass== KP_NO_PRESSED_KEY);
if(kp_pass=='$') break;
pass_nums_arr[pass_nums++]=kp_pass;
LCD_enuDisplayNumPOS(kp_pass,2,pass_nums);
_delay_ms(100);
LCD_enuDisplayCharPOS('*',2,pass_nums);
_delay_ms(100);

}
LCD_enuClear();
//take password again to check
u8 count=0;
LCD_enuDisplayStringPOS("ensure password",1,2);

while(1){
do{
	 kp_pass=KEYPAD_enuGetpressedKey();
}while(kp_pass== KP_NO_PRESSED_KEY);
if(kp_pass=='$') break;
pass_ch_nums_arr[count++]=kp_pass;
LCD_enuDisplayNumPOS(kp_pass,2,count);
_delay_ms(100);
LCD_enuDisplayCharPOS('*',2,count);
}
_delay_ms(100);
LCD_enuClear();
 //check if pass is correct

int flag=1;
for(u8 i=0;i<pass_nums;i++){
	if(pass_ch_nums_arr[i]!=pass_nums_arr[i])
		flag=0;
	else
		break;
}

//display loading

	LCD_enuDisplayStringPOS("loading",1,2);
for(int i=0;i<3;i++){

	_delay_ms(350);
	LCD_enuDisplayCharPOS('.',1,(i+9));
}

//PASS correct  enter calculator

if(flag){
	_delay_ms(500);
	LCD_enuClear();
	_delay_ms(500);
	LCD_enuDisplayStringPOS("WELCOME",1,5);
	_delay_ms(600);
	LCD_enuClear();

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int operation=0;
u8 kpVal;
u8 first_num_arr[8];
u8 second_num_arr[8];
u8 count1=0;
u8 count2=0;
u8 ONflage=0;
//working
while(flag){
	int operation=0;
	u8 kpVal;
	u8 first_num_arr[8];
	u8 second_num_arr[8];
	u8 count1=0;
	u8 count2=0;
	u8 ONflage=0;
	u8 n1eql=0;
	// taking the first number
while(1){
do{
	kpVal=KEYPAD_enuGetpressedKey();
}while(kpVal== KP_NO_PRESSED_KEY);

if((kpVal=='-')|| (kpVal=='+')|| (kpVal=='%')||( kpVal=='x'))
{
	operation=kpVal;
	LCD_enuDisplayChar(kpVal);
	break;
}
else if(kpVal=='=')
{
	for(int i=0;i<count1;i++)
	{
		LCD_enuDisplayNumPOS(first_num_arr[i],2,8+i);

	}
	n1eql=1;
	break;

}
else if(kpVal=='$')
{
     LCD_enuClear();
     ONflage=1;
     break ;
}

first_num_arr[count1++]=kpVal;
LCD_enuDisplayNum(kpVal);

}

// taking the second number

while(!ONflage&&!n1eql)
{

	do{
		kpVal=KEYPAD_enuGetpressedKey();
	}while(kpVal== KP_NO_PRESSED_KEY);
	if(kpVal=='=')
	{
		arrToNum(first_num_arr,second_num_arr,count1,count2,operation);
		break;
	}

	else if(kpVal=='$')
	{
	     LCD_enuClear();
	     ONflage=1;
	     break;
	}

	second_num_arr[count2++]=kpVal;
	LCD_enuDisplayNum(kpVal);
}


}
}
else
{
	LCD_enuClear();
	LCD_enuDisplayString("WRONG PASSWORD");
}











}
void arrToNum(u8*ptr1,u8*ptr2,u8 n1,u8 n2,u8 operation)
{
	int num1=ptr1[0];
    int num2=ptr2[0];

	for(int i=1;i<n1;i++)
	{
		num1=num1 * 10 + ptr1[i];
	}


	for(int i=1;i<n2;i++)
		{
			num2=num2 * 10 +ptr2[i];
		}
	u32 sum , sub , mul , div ;

	//LCD_enuDisplayNumPOS(num1,2,2);
	//LCD_enuDisplayNumPOS(num2,2,6);

	switch(operation)
	{
	    case '+':
	    	      {
	    	    	  sum=num1+num2;
	    	    	  LCD_enuDisplayNumPOS(sum,2,12);
	    	    	  break;
	    	      }
	    case '-':{   if(num1<num2){
                     sub=num2-num1;
                     LCD_enuDisplayCharPOS('-',2,11);
                     LCD_enuDisplayNumPOS(sub,2,12);
                     break;
	                                  }
	             	sub=num1-num2;
	    	        LCD_enuDisplayNumPOS(sub,2,12);
	    	        break;
	    }
	    case 'x': {
	            	mul=num1*num2;
	    	        LCD_enuDisplayNumPOS(mul,2,10);
	    	        break;
	    }
	    case '%': { if(num2==0)
	                   {
	    	                 LCD_enuClear();
	    	                 LCD_enuDisplayStringPOS("ERROR1",1,3);
	    	                 break;
	                   }

	               div=num1/num2;
	    	       LCD_enuDisplayNumPOS(div,2,10);
	    	       break;
	    }
	}


}
