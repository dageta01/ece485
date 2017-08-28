#ifndef HEADER_PHONEWORK
#define HEADER_PHONEWORK

#define TRUE 1
#define FALSE 0
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
void print_number(uint8_t *ptrNumber);
uint8_t phone_number_to_int(uint8_t *ptrNumber)
{
	return *(ptrNumber) - '0';
}

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
	//if all fails and goes wrong, the number is returned as a failure
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
}

/************************************************************/
void print_number_words(uint8_t *ptrNumber, uint8_t numberOfWords)
{
	uint8_t i = 0;
	uint8_t j = 0;

}
#endif
