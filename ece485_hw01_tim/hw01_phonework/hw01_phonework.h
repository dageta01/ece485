#ifndef HEADER_PHONEWORK
#define HEADER_PHONEWORK

#define TRUE 1
#define FALSE 0

#define TO_INT(x) (x)-'0'

#include <assert.h>

/***************************************************************/
const uint8_t phoneWorkLUT[8][3] = 					{	
																							{'A','B','C'},	//2
																							{'D','E','F'}, 	//3
																							{'G','H','I'}, 	//4
																							{'J','K','L'}, 	//5
																							{'M','N','O'},	//6
																							{'P','R','S'},	//7
																							{'T','U','V'},	//8
																							{'W','X','Y'}		//9
																						};
/***********************************************************/
																						
//Function prototypes
uint8_t validate_number(uint8_t *ptrNumber);
void print_failure(uint8_t *ptrNumber);
void print_number_words(uint8_t *ptrNumber, uint8_t numberOfWords);
void print_as_word(uint8_t *ptrNumber);
void print_number(uint8_t *ptrNumber);
void print_as_letter(uint8_t *ptrNumber, uint8_t numShift, uint8_t numLUT);

/*uint8_t phone_number_to_int(uint8_t *ptrNumber)
{
	return *(ptrNumber) - '0';
}
*/
																						
uint8_t validate_number(uint8_t *ptrNumber)
{
	uint8_t i = 0;
	for(i = 0; i < 7; i++)
	{
		if(*(ptrNumber + i) == '0' || *(ptrNumber + i) == '1')
		{
			return FALSE;
		}
	}
	//if the above fails then no numbers are 0;
	return TRUE;
}
/************************************************************/
void print_failure(uint8_t *ptrNumber)
{
	printf("No English word for telephone number \'");
	print_number(ptrNumber);
	printf("\'\n");
}
/************************************************************/
void print_number(uint8_t *ptrNumber)
{
	uint8_t i = 0;
	for(i = 0; i < 7; i++)
	{
		printf("%c", *(ptrNumber + i));
	}
	printf("\n");
}

/************************************************************
void print_as_words(uint8_t *ptrNumber, uint8_t lookUpNumber)
{
	uint8_t i = 0;
	//assert(0 <= lookUpNumber && lookUpNumber <= 2);

	for(i = 0; i < 7; i++)
	{
		print_as_letter(ptrNumber, i, lookUpNumber);
	}
	printf("\n");
}
************************************************************/
void print_as_letter(uint8_t *ptrNumber, uint8_t numShift, uint8_t numLUT)
{
	printf("%c", phoneWorkLUT[TO_INT(*(ptrNumber + numShift)) - 2][numLUT]);
}
/************************************************************/
void print_number_words(uint8_t *ptrNumber, uint8_t numberOfWords)
{
	uint8_t i = 0;
	uint8_t j = 0;
	uint8_t k = 0;
	uint8_t stepNumber[7] = {0,0,0,0,0,0,0}; //used to represent which letter that number is on;
	
	uint8_t count = 0;
	printf("The entered number is ");
	print_number(ptrNumber);
	
	for(i = 0; i < numberOfWords; i++)
	{
		for(j = 0; j < 7; j++)
		{
			if(stepNumber[j] > 2)
			{
				stepNumber[j] = 0;
				stepNumber[j - 1] += 1;
			}
			else if(stepNumber[0] > 2)
	print 		{
				break;
			}
			print_as_letter(ptrNumber, j, (int) stepNumber[j]);


		}
		stepNumber[6] += 1;
		count++;
		printf("\n");
	}
	printf("count");
}
#endif
