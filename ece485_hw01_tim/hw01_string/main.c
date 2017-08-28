/*----------------------------------------------------------------------------
first LPC1768 hello
simply call Serial Port functions

 *----------------------------------------------------------------------------*/

#include <stdio.h>
#include "LPC17xx.H"                         /* LPC17xx definitions           */
#include "Serial.h"
#include "hw01_string.h"

/*----------------------------------------------------------------------------
  Main Program
 *----------------------------------------------------------------------------*/
int main (void) 

{
	char string[] ="Test,string1,Test,string2:Test:string3";
	char *p;
	SER_Init();
	
	#ifdef DEBUG
	printf("strcspn: %d\n",hw_strcspn("ty: this"," :"));
	printf("strspn: %d\n", hw_strspn(":~ :2"," :~"));
	printf("strops: %d\n", hw_strops("hello world",'d'));
	#endif
	
	printf("String \"%s\" is split into tokens: \n", string);
	p = hw_strtok(string, ",:");
	while(p != NULL)
	{
		printf("%s\n",p);
		p = hw_strtok(NULL, ",:");
	}
	printf("%s\n",p);
	return 0;
}
