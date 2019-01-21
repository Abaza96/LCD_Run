/*
 * LCD.h
 *
 *  Created on: Jan 19, 2019
 *      Author: Mahmoud Abaza
 */

#ifndef HAL_LCD_H_	//If it is not Defined
#define HAL_LCD_H_	//Define it

//Libs and Defs
	//Service Stack Files
#include "../ServicesStack/std_Types.h"

	//HAL Files
#include "LCD_cfg.h"

	//Definitions
#define in +		//Define in as + for the Readability

	//User-Defined Data Types
typedef enum LCD_Row1
{
	LCD_Character10  = 0x00,	 	//Define Row 1 Column 01 as LCD_Character10
	LCD_Character11  ,			 	//Define Row 1 Column 02 as LCD_Character11
	LCD_Character12  ,			 	//Define Row 1 Column 03 as LCD_Character12
	LCD_Character13  ,	 			//Define Row 1 Column 04 as LCD_Character13
	LCD_Character14  ,	 			//Define Row 1 Column 05 as LCD_Character14
	LCD_Character15  ,	 			//Define Row 1 Column 06 as LCD_Character15
	LCD_Character16  ,	 			//Define Row 1 Column 07 as LCD_Character16
	LCD_Character17  ,	 			//Define Row 1 Column 08 as LCD_Character17
	LCD_Character18  ,	 			//Define Row 1 Column 09 as LCD_Character18
	LCD_Character19  ,	   			//Define Row 1 Column 10 as LCD_Character19
	LCD_Character110 ,				//Define Row 1 Column 11 as LCD_Character110
	LCD_Character111 ,				//Define Row 1 Column 12 as LCD_Character111
	LCD_Character112 ,				//Define Row 1 Column 13 as LCD_Character112
	LCD_Character113 ,				//Define Row 1 Column 14 as LCD_Character113
	LCD_Character114 ,   			//Define Row 1 Column 15 as LCD_Character114
	LCD_Character115 				//Define Row 1 Column 16 as LCD_Character115
}FirstRow;

typedef enum LCD_Row2
{
	LCD_Character20  = 0x40,	 	//Define Row 2 Column 01 as LCD_Character20
	LCD_Character21  , 				//Define Row 2 Column 02 as LCD_Character21
	LCD_Character22  ,	 			//Define Row 2 Column 03 as LCD_Character22
	LCD_Character23  ,	 			//Define Row 2 Column 04 as LCD_Character23
	LCD_Character24  ,	 			//Define Row 2 Column 05 as LCD_Character24
	LCD_Character25  ,	 			//Define Row 2 Column 06 as LCD_Character25
	LCD_Character26  ,	 			//Define Row 2 Column 07 as LCD_Character26
	LCD_Character27  ,	 			//Define Row 2 Column 08 as LCD_Character27
	LCD_Character28  ,	 			//Define Row 2 Column 09 as LCD_Character28
	LCD_Character29  ,	    		//Define Row 2 Column 10 as LCD_Character29
	LCD_Character210 ,				//Define Row 2 Column 11 as LCD_Character210
	LCD_Character211 ,				//Define Row 2 Column 12 as LCD_Character211
	LCD_Character212 ,				//Define Row 2 Column 13 as LCD_Character212
	LCD_Character213 ,				//Define Row 2 Column 14 as LCD_Character213
	LCD_Character214 ,    			//Define Row 2 Column 15 as LCD_Character214
	LCD_Character215 				//Define Row 2 Column 16 as LCD_Character215
}SecondRow;

//External Prototypes
extern void LCD_vidInitialization(void);		//Function to Initialize LCD
extern void LCD_vidExecuteCommand(u8 Command);	//Function to Execute Commands of LCD
extern void LCD_vidWriteData(u8 Data);			//Function to Write a Specific Data from LCD

#endif //Stop Here
