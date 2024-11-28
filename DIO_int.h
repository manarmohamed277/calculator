/*
 * DIO_int.h
 *
 *  Created on: Nov 6, 2024
 *      Author: User
 */

#ifndef DIO_INT_H_
#define DIO_INT_H_

#define DIO_u8PORTA		0
#define DIO_u8PORTB		1
#define DIO_u8PORTC		2
#define DIO_u8PORTD		3


#define DIO_u8PIN0 0
#define DIO_u8PIN1 1
#define DIO_u8PIN2 2
#define DIO_u8PIN3 3
#define DIO_u8PIN4 4
#define DIO_u8PIN5 5
#define DIO_u8PIN6 6
#define DIO_u8PIN7 7

#define DIO_u8INPUT 0
#define DIO_u8OUTPUT 1
#define DIO_u8HIGH 1
#define DIO_u8LOW 0
#define DIO_u8PULLUP 1
#define DIO_u8FLOAT 0

ES_ERROR DIO_enuInit(void);

ES_ERROR DIO_enuSetportdir(u8 copy_u8portid,u8 copy_u8value);

ES_ERROR DIO_enuSetportval(u8 copy_u8portid,u8 copy_u8value);

ES_ERROR DIO_enuSetpindir(u8 copy_u8portid,u8 copy_u8pinid,u8 copy_u8value);

ES_ERROR DIO_enuSetpinval(u8 copy_u8portid,u8 copy_u8pinid,u8 copy_u8value);

ES_ERROR DIO_enutogport(u8 copy_u8portid);

ES_ERROR DIO_enutogpin(u8 copy_u8portid,u8 copy_u8pinid);

ES_ERROR DIO_enugetportval(u8 copy_u8portid,u8* copy_pu8value);

ES_ERROR DIO_enugetpinval(u8 copy_u8portid,u8 copy_u8pinid,u8* copy_pu8value);

#endif /* DIO_INT_H_ */
