/*
 * LCD_priv.h
 *
 *  Created on: Nov 24, 2024
 *      Author: User
 */

#ifndef LCD_PRIV_H_
#define LCD_PRIV_H_






#define EIGHT_BIT	51
#define FOUR_BIT	9

#define ROW1 1
#define ROW2 2

static inline ES_ERROR LCD_INIT_SendCommend(u8 Copy_u8Command);

static ES_ERROR LCD_inerSendData(u8 Copy_u8Data);

static void LCD_setCusor(u8 copyu8_row,u8 copy_u8_column);
//static void LCD_setCusor(u8 copyu8_row,u8 copy_u8_column);




#endif /* LCD_PRIV_H_ */
