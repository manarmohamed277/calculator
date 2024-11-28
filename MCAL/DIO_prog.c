/*
 * DIO_prog.c
 *
 *  Created on: Nov 6, 2024
 *      Author: User
 */
#include"DIO_priv.h"
#include"DIO_cofig.h"
#include"..\errorState.h"
#include "..\stdTypes.h"


ES_ERROR DIO_enuInit(void){
ES_ERROR local_enuerrorstate=ES_NOK;

DDRA=conc(PA_PIN7_DIR,PA_PIN6_DIR,PA_PIN5_DIR,PA_PIN4_DIR,PA_PIN3_DIR,PA_PIN2_DIR,PA_PIN1_DIR,PA_PIN0_DIR);
DDRB=conc(PB_PIN7_DIR,PB_PIN6_DIR,PB_PIN5_DIR,PB_PIN4_DIR,PB_PIN3_DIR,PB_PIN2_DIR,PB_PIN1_DIR,PB_PIN0_DIR);
DDRC=conc(PC_PIN7_DIR,PC_PIN6_DIR,PC_PIN5_DIR,PC_PIN4_DIR,PC_PIN3_DIR,PC_PIN2_DIR,PC_PIN1_DIR,PC_PIN0_DIR);
DDRD=conc(PD_PIN7_DIR,PD_PIN6_DIR,PD_PIN5_DIR,PD_PIN4_DIR,PD_PIN3_DIR,PD_PIN2_DIR,PD_PIN1_DIR,PD_PIN0_DIR);

PORTA=conc(PA_PIN7_VAL,PA_PIN6_VAL,PA_PIN5_VAL,PA_PIN4_VAL,PA_PIN3_VAL,PA_PIN2_VAL,PA_PIN1_VAL,PA_PIN0_VAL);
PORTB=conc(PB_PIN7_VAL,PB_PIN6_VAL,PB_PIN5_VAL,PB_PIN4_VAL,PB_PIN3_VAL,PB_PIN2_VAL,PB_PIN1_VAL,PB_PIN0_VAL);
PORTC=conc(PC_PIN7_VAL,PC_PIN6_VAL,PC_PIN5_VAL,PC_PIN4_VAL,PC_PIN3_VAL,PC_PIN2_VAL,PC_PIN1_VAL,PC_PIN0_VAL);
PORTD=conc(PD_PIN7_VAL,PD_PIN6_VAL,PD_PIN5_VAL,PD_PIN4_VAL,PD_PIN3_VAL,PD_PIN2_VAL,PD_PIN1_VAL,PD_PIN0_VAL);

    local_enuerrorstate=ES_OK;

return local_enuerrorstate;
}

ES_ERROR DIO_enuSetportdir(u8 copy_u8portid,u8 copy_u8value){
	ES_ERROR local_enuerrorstate=ES_NOK;

	 if( copy_u8portid<=DIO_PORTD){
		 switch(copy_u8portid){
		 case DIO_PORTA :
			DDRA=copy_u8value;
		   break;
		 case DIO_PORTB :
			DDRB=copy_u8value;
			   break;
		 case DIO_PORTC :
			DDRC=copy_u8value;
			   break;
		 case DIO_PORTD :
			DDRD=copy_u8value;
			   break;
		 }
		  local_enuerrorstate=ES_OK;
	 }
	 else{local_enuerrorstate=ES_OUT_OF_RANGE;}

	return local_enuerrorstate;
}



ES_ERROR DIO_enuSetportval(u8 copy_u8portid,u8 copy_u8value){
	ES_ERROR local_enuerrorstate=ES_NOK;

	 if( copy_u8portid<=DIO_PORTD){
		 switch(copy_u8portid){
		 case DIO_PORTA :
			PORTA=copy_u8value;
		   break;
		 case DIO_PORTB :
			PORTB=copy_u8value;
			   break;
		 case DIO_PORTC :
			PORTC=copy_u8value;
			   break;
		 case DIO_PORTD :
			PORTD=copy_u8value;
			   break;
		 }
		  local_enuerrorstate=ES_OK;
	 }
	 else{local_enuerrorstate=ES_OUT_OF_RANGE;}

	return local_enuerrorstate;
}
ES_ERROR DIO_enuSetpindir(u8 copy_u8portid,u8 copy_u8pinid,u8 copy_u8value){
	ES_ERROR local_enuerrorstate=ES_NOK;

if(copy_u8portid<=DIO_PORTD&& copy_u8pinid<=DIO_PIN7&&copy_u8value<=OUTPUT ){
	 if( copy_u8portid<=DIO_PORTD){
			 switch(copy_u8portid){
			 case DIO_PORTA :
				DDRA&=~(MASK_BIT<<copy_u8pinid);
				DDRA|=(copy_u8value<<copy_u8pinid);
			   break;
			 case DIO_PORTB :
					DDRB&=~(MASK_BIT<<copy_u8pinid);
				    DDRB|=(copy_u8value<<copy_u8pinid);
				   break;
			 case DIO_PORTC :
				 DDRC&=~(MASK_BIT<<copy_u8pinid);
				 DDRC|=(copy_u8value<<copy_u8pinid);
				   break;
			 case DIO_PORTD :
				 DDRD&=~(MASK_BIT<<copy_u8pinid);
				 DDRD|=(copy_u8value<<copy_u8pinid);
				   break;
			 }
			 local_enuerrorstate=ES_OK;
		 }
}
else  {local_enuerrorstate=ES_OUT_OF_RANGE;}

		return local_enuerrorstate;
}

ES_ERROR DIO_enuSetpinval(u8 copy_u8portid,u8 copy_u8pinid,u8 copy_u8value){
	ES_ERROR local_enuerrorstate=ES_NOK;

	if(copy_u8portid<=DIO_PORTD&& copy_u8pinid<=DIO_PIN7&&copy_u8value<=OUTPUT ){

				 switch(copy_u8portid){
				 case DIO_PORTA :
					PORTA&=~(MASK_BIT<<copy_u8pinid);
					PORTA|=(copy_u8value<<copy_u8pinid);
				   break;
				 case DIO_PORTB :
						PORTB&=~(MASK_BIT<<copy_u8pinid);
					    PORTB|=(copy_u8value<<copy_u8pinid);
					   break;
				 case DIO_PORTC :
					 PORTC&=~(MASK_BIT<<copy_u8pinid);
					 PORTC|=(copy_u8value<<copy_u8pinid);
					   break;
				 case DIO_PORTD :
					 PORTD&=~(MASK_BIT<<copy_u8pinid);
					 PORTD|=(copy_u8value<<copy_u8pinid);
					   break;
				 }
				  local_enuerrorstate=ES_OK;

	}
	else  {local_enuerrorstate=ES_OUT_OF_RANGE;}

		return local_enuerrorstate;
}

ES_ERROR DIO_enutogport(u8 copy_u8portid){
	ES_ERROR local_enuerrorstate=ES_NOK;


	 if( copy_u8portid<=DIO_PORTD){
			 switch(copy_u8portid){
			 case DIO_PORTA :
				PORTA=~PORTA;
			   break;
			 case DIO_PORTB :
				PORTB=~PORTB;
				   break;
			 case DIO_PORTC :
				PORTC=~PORTC;
				   break;
			 case DIO_PORTD :
				PORTD=~PORTD;
				   break;
			 }
			  local_enuerrorstate=ES_OK;
		 }
		 else{local_enuerrorstate=ES_OUT_OF_RANGE;}


		return local_enuerrorstate;
}

ES_ERROR DIO_enutogpin(u8 copy_u8portid,u8 copy_u8pinid){
	ES_ERROR local_enuerrorstate=ES_OK;

	if(copy_u8portid<=DIO_PORTD&& copy_u8pinid<=DIO_PIN7 ){

					 switch(copy_u8portid){
					 case DIO_PORTA :
						PORTA^=(MASK_BIT<<copy_u8pinid);

					   break;
					 case DIO_PORTB :
						 PORTB^=(MASK_BIT<<copy_u8pinid);
						   break;
					 case DIO_PORTC :
						 PORTC^=(MASK_BIT<<copy_u8pinid);
						   break;
					 case DIO_PORTD :
						 PORTD^=(MASK_BIT<<copy_u8pinid);
						   break;
					 }
					  local_enuerrorstate=ES_OK;
				 }

		else  {local_enuerrorstate=ES_OUT_OF_RANGE;}


		return local_enuerrorstate;
}

ES_ERROR DIO_enugetportval(u8 copy_u8portid,u8* copy_pu8value){
	ES_ERROR local_enuerrorstate=ES_OK;
 if(copy_pu8value!=NULL){
	 if( copy_u8portid<=DIO_PORTD){
	 		 switch(copy_u8portid){
	 		 case DIO_PORTA :
	 			* copy_pu8value=PINA;
	 		   break;
	 		 case DIO_PORTB :
	 			* copy_pu8value=PINB;
	 			   break;
	 		 case DIO_PORTC :
	 			* copy_pu8value=PINC;
	 			   break;
	 		 case DIO_PORTD :
	 			* copy_pu8value=PIND;
	 			   break;
	 		 }
	 		  local_enuerrorstate=ES_OK;
	 	 }
	 	 else{local_enuerrorstate=ES_OUT_OF_RANGE;}




	}


 else{
	 local_enuerrorstate=ES_NULL_POINTER;
 }


		return local_enuerrorstate;
}

ES_ERROR DIO_enugetpinval(u8 copy_u8portid,u8 copy_u8pinid,u8* copy_pu8value){
	ES_ERROR local_enuerrorstate=ES_OK;
	 if(copy_pu8value!=NULL){
	if(copy_u8portid<=DIO_PORTD&& copy_u8pinid<=DIO_PIN7 ){

				 switch(copy_u8portid){
				 case DIO_PORTA :
					 * copy_pu8value=	(PINA>>copy_u8pinid)&MASK_BIT;
				   break;
				 case DIO_PORTB :
					 * copy_pu8value=	(PINB>>copy_u8pinid)&MASK_BIT;
					   break;
				 case DIO_PORTC :
					 * copy_pu8value=	(PINC>>copy_u8pinid)&MASK_BIT;
					   break;
				 case DIO_PORTD :
					 * copy_pu8value=	(PIND>>copy_u8pinid)&MASK_BIT;
					   break;
				 }
				  local_enuerrorstate=ES_OK;
			 }

	else  {local_enuerrorstate=ES_OUT_OF_RANGE;}}
	else local_enuerrorstate=ES_NULL_POINTER;

		return local_enuerrorstate;
}

