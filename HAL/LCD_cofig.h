/*
 * LCD_cofig.h
 *
 *  Created on: Nov 24, 2024
 *      Author: User
 */

#ifndef LCD_COFIG_H_
#define LCD_COFIG_H_

#define LCD_MODE		EIGHT_BIT

/*			Control Pins	*/
#define RS_PORT		DIO_u8PORTB
#define RS_PIN		DIO_u8PIN2

#define RW_PORT		DIO_u8PORTB
#define RW_PIN		DIO_u8PIN1

#define EN_PORT		DIO_u8PORTB
#define EN_PIN		DIO_u8PIN0

/*			Data Pins		*/
#define D7_PORT		DIO_u8PORTA
#define D7_PIN		DIO_u8PIN0

#define D6_PORT		DIO_u8PORTA
#define D6_PIN		DIO_u8PIN1

#define D5_PORT		DIO_u8PORTA
#define D5_PIN		DIO_u8PIN2

#define D4_PORT		DIO_u8PORTA
#define D4_PIN		DIO_u8PIN3

#define D3_PORT	   DIO_u8PORTA
#define D3_PIN	   DIO_u8PIN4

#define D2_PORT	    DIO_u8PORTA
#define D2_PIN	    DIO_u8PIN5

#define D1_PORT	    DIO_u8PORTA
#define D1_PIN	    DIO_u8PIN6

#define D0_PORT	    DIO_u8PORTA
#define D0_PIN	    DIO_u8PIN7


#endif /* LCD_COFIG_H_ */
