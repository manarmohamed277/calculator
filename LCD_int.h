/*
 * LCD_int.h
 *
 *  Created on: Nov 24, 2024
 *      Author: User
 */

#ifndef LCD_INT_H_
#define LCD_INT_H_

ES_ERROR LCD_enuinit(void);

ES_ERROR LCD_enuSendCommand(u8 copy_u8command);

ES_ERROR LCD_enuDisplayChar(u8 Copy_u8Data);

ES_ERROR LCD_enuDisplayString(u8 *pcopy_u8string);

ES_ERROR LCD_enuDisplayNum(u32 copyu32_num);


ES_ERROR LCD_enuClear();

ES_ERROR LCD_enuDisplayNumPOS(u32 copyu32_num,u8 copyu8_row,u8 copy_u8_column);

ES_ERROR LCD_enuDisplayStringPOS(u8 *pcopy_u8string,u8 copyu8_row,u8 copy_u8_column);

ES_ERROR LCD_enuDisplayCharPOS(u8 Copy_u8Data,u8 copyu8_row,u8 copy_u8_column);

#endif /* LCD_INT_H_ */
