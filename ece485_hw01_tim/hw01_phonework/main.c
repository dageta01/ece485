/*----------------------------------------------------------------------------
first LPC1768 hello
simply call Serial Port functions

 *----------------------------------------------------------------------------*/

#include <stdio.h>
#include <assert.h>
#include "LPC17xx.H"                         /* LPC17xx definitions           */
#include "Serial.h"
#include "hw01_phonework.h"

/*----------------------------------------------------------------------------
  Main Program
 *----------------------------------------------------------------------------*/
int main (void) {
	//uint8_t phoneWorkLUT[8][3];
	
	uint8_t phonenumber[] = "2223567";
	//uint8_t phonenumber[] = "2201111";
  
	uint8_t *ptrPhone = phonenumber;
	
	SER_Init();
	if(validate_number(ptrPhone))
	{
		print_number_words(ptrPhone, 50);
	}
	else 
	{
		print_failure(ptrPhone);
	}
    	
    return 0;
  }


