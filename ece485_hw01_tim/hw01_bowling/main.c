/*----------------------------------------------------------------------------
first LPC1768 hello
simply call Serial Port functions

 *----------------------------------------------------------------------------*/

#include <stdio.h>
#include "LPC17xx.H"                         /* LPC17xx definitions           */
#include "Serial.h"
#include "hw01_bowling.h"


/*----------------------------------------------------------------------------
  Main Program
 *----------------------------------------------------------------------------*/
int main (void) 

{
	//variable declarations
	
	//static const uint8_t pins[]={9, 1, 0, 10, 10, 10, 6, 2 , 7, 3, 8, 2, 10, 9 ,0 , 9, 1, 10}; 
	static uint8_t pins[] = {10,10,10,10,10,10,10,10,10,10,10,10};
	uint8_t const *ptrPins = pins;
	uint8_t frameNumber = 0;
	uint16_t totalScore = 0;
	uint8_t roll1 = 0;
	uint8_t roll2 = 0;
	gamestate state = OPEN;

	SER_Init();	
	while(frameNumber < MAX_FRAMES)
	{
		if( *(ptrPins) == 10)
		{
			state = STRIKE;
			roll1 = 10;
			ptrPins++;
			roll2 = *ptrPins + *(ptrPins + 1);
			totalScore += roll1 + roll2;
		}
		else if (*(ptrPins) + *(ptrPins + 1) == 10)
		{	
			state = SPARE;
			roll1 = 10;
			ptrPins += 2;
			roll2 = *ptrPins;
			totalScore += roll1 + roll2;	
		}
		else
		{	
			state = OPEN;
			roll1 = *ptrPins;
			ptrPins++;
			roll2 = *ptrPins;
			ptrPins++;
			totalScore += roll1 + roll2;
		}//end of if block
		print_score(state,frameNumber,totalScore);
		frameNumber++;
	}
	
	return 0;
}
