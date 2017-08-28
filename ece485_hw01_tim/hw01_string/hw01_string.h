#ifndef _HW_STRING
#define _HW_STRING

//function prototypes
char *hw_strtok (char *text, const char *delims);				//extracts tokens from a string
int hw_strops(const char *text, const char findChar); 					//return index of first occurence
uint8_t hw_strspn(const char *text, const char *delims); 		//finds index of first non-delimiter char
uint8_t hw_strcspn(const char *text, const char *delims); 	// index of first delimter char

/************************************************************/
char *hw_strtok(char *text, const char *delims)
{
	static char *ptrNextToken;
	
	if(!text)
	{
		text = ptrNextToken;
	}
	text += hw_strspn(text,delims);
	if(*(text) == '\0')
	{
		return NULL;
	}
	ptrNextToken = text + hw_strcspn(text,delims);
	if(*ptrNextToken != '\0')
	{
		*ptrNextToken++ = '\0';
	}
	return text;
}

/**************************************************************/
int hw_strops(const char *text, const char findChar)
//returns index of occurence of findChar
{
	uint8_t i = 0;
	while(*(text + i) != '\0')
	{
		if(*(text + i) == findChar)
		{
			return i;
		}
		i++;
	}
	return -1;
}
/*************************************************************/
uint8_t hw_strspn(const char *text, const char *delims)
// finds index of first non-delimiter char
{
	uint8_t i = 0;
	uint8_t j = 0;
	
	while(*(text + i) != '\0')
	{
		j= 0;
		while(*(text + i) != *(delims + j))
		{
			if(*(delims + j) == '\0')
			{
				return i;
			}
			else
			{
				j++;
			}
		}
		i++;
	}
	return '\0';
}
/************************************************************/
uint8_t hw_strcspn(const char *text, const char *delims)
{
	uint8_t i = 0;
	uint8_t j = 0;
	while(*(text + i) != '\0')
	{
		j = 0;
		while(*(delims + j) != '\0')
		{
			if(*(text + i) == *(delims + j))
			{
				return i;
			}
			else
			{
			}
			j++;
		}
		i++;
	}
	return '\0';
}
/**************************************************************/
#endif
