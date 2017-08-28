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
	//array declarations
	static uint8_t pins[] = {10,10,10,10,10,10,10,10,10,10,10,10};
	static frame gameFrames[MAX_FRAMES];
		
	//integer declaratiosn
	uint8_t frameNumber = 0;
	uint16_t totalScore = 0;
	
	//declaration of pointers to the first arrays
	uint8_t *ptrPins = pins;
	frame *ptrFrames = gameFrames;
	

	init_frames(ptrFrames);
	SER_Init();	

	//main program loop
	while(frameNumber < MAX_FRAMES)
	{
		if( *(ptrPins) == 10)
		{
			ptrFrames -> frameState = STRIKE;
			ptrFrames -> roll1 = 10;
			ptrPins++;
			ptrFrames -> roll2 = *ptrPins + *(ptrPins + 1);
			update_score(ptrFrames);
		}
		else if (*(ptrPins) + *(ptrPins + 1) == 10)
		{
			ptrFrames -> frameState = SPARE;
			ptrFrames -> roll1 = 10;
			ptrPins += 2;
			ptrFrames -> roll2 = *ptrPins;
			update_score(ptrFrames);
		}
		else
		{
			ptrFrames -> frameState = OPEN;
			ptrFrames -> roll1 = *ptrPins;
			ptrPins++;
			ptrFrames -> roll2 = *ptrPins;
			ptrPins++;
			update_score(ptrFrames);
		}//end of if block
		
		totalScore += ptrFrames->score;
		print_score(ptrFrames -> frameState, frameNumber, totalScore);
		frameNumber++;
		ptrFrames += 1;

	}
	
	return 0;
}
