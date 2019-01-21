/*
 * main.c
 *
 *  Created on: Jan 19, 2019
 *      Author: Mahmoud Abaza
 */
//Libs and Defs
	//HAL Files
#include "HAL/LCD.h"

#define Size 6
//Main Function
int main(void)
{
	u8 Name[Size] = "Abaza", i;
	LCD_vidInitialization();	//Initialize The LCD

	for(i = False ; i < Size ; i++)
		LCD_vidWriteData(Name[i]);	//Print The String

	return True;	//Stop The Program and Get 1 to The main
}
