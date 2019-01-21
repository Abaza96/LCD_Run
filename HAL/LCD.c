/*
 * LCD.c
 *
 *  Created on: Jan 19, 2019
 *      Author: Mahmoud Abaza
 */
//Libs and Defs
	//Service Stack Files
#include "../ServicesStack/Registers.h"
	//MCAL Files
#include "../MCAL/DIO.h"
#include <util/delay.h>
	//HAL Files
#include "LCD_cfg.h"
#include "LCD.h"

//Functions Implementation
extern void LCD_vidExecuteCommand(u8 Command)	//Function to Execute Commands of LCD
{
	//First is Initializing the Register Select (RS) by Zero to Execute a Command
	DIO_vidWritePinValue(LCD_ControlPort, RS, LOW);

    //Second is Initializing the Read/Write (RW) by Zero to Write
	DIO_vidWritePinValue(LCD_ControlPort, RW, LOW);

	//Third is Loading The Data
	DIO_vidSetPortValue(LCD_DataPort, Command);

	//After That is Initializing the Enable (E) by One to Run Command
	DIO_vidWritePinValue(LCD_ControlPort, E, HIGH);

	//Delay to Let it Execute for a Time
	_delay_ms(LCD_ExecutionTime);

    //Finally is Initializing the Enable (E) by Zero to Stop
	DIO_vidWritePinValue(LCD_ControlPort, E, LOW);
}

extern void LCD_vidWriteData(u8 Data)			//Function to Write a Specific Data from LCD
{
	//First is Initializing the Register Select (RS) by One to Display Data
	DIO_vidWritePinValue(LCD_ControlPort, RS, HIGH);

    //Second is Initializing the Read/Write (RW) by Zero to Write
	DIO_vidWritePinValue(LCD_ControlPort, RW, LOW);

	//Third is Loading The Data
	DIO_vidSetPortValue(LCD_DataPort, Data);

	//After That is Initializing the Enable (E) by One to Run Command
	DIO_vidWritePinValue(LCD_ControlPort, E, HIGH);

	//Delay to Let it Execute for a Time
	_delay_ms(LCD_ExecutionTime);

    //Finally is Initializing the Enable (E) by Zero to Stop
	DIO_vidWritePinValue(LCD_ControlPort, E, LOW);
}

extern void LCD_vidInitialization(void)		//Function to Initialize LCD
{
	DIO_vidSetPinDirection(LCD_ControlPort, RS, OUTPUT);	//Initialize The RS's Direction as 1

	DIO_vidSetPinDirection(LCD_ControlPort, RW, OUTPUT);	//Initialize The RW's Direction as 1

	DIO_vidSetPinDirection(LCD_ControlPort, E, OUTPUT);		//Initialize The E's  Direction as 1

	DIO_vidSetPortDirection(LCD_DataPort, FullyCharged);	//Charge The Whole Data Port with 1s

	_delay_ms(LCD_PowerOnDelay);	//Delay for at least 30 microseconds

	LCD_vidExecuteCommand(LCD_FunctionSet);					//The Function Set Command Setup

	_delay_ms(LCD_ExecutionTime);	//Delay for at least 30 microseconds

	LCD_vidExecuteCommand(LCD_DisplayControl);				//The Display ON/OFF Control Command Setup

	_delay_ms(LCD_ExecutionTime);	//Delay for at least 30 microseconds

	LCD_vidExecuteCommand(LCD_ClearDisplay);				//The Clear Display Command Setup

	_delay_ms(LCD_ExecutionTime);	//Delay for at least 30 microseconds

	LCD_vidExecuteCommand(LCD_EntryMode);				//The Entry Mode Command Setup
}
