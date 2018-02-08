#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	printf("Rentrez un caractère juste après cette phrase :");
	char c = getchar();
	char HEX1=c/16;
	if(HEX1<=9)
	  	HEX1+='0';
	else
	  	HEX1=HEX1-10+'A'; 
	char HEX2=c%16;
	if(HEX2<=9)
	  	HEX2+='0';
	else
	  	HEX2=HEX2-10+'A';
	printf("%c = %d = %c%c\n", c, c, HEX1,HEX2);
    return(0);
}