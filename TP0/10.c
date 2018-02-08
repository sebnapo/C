#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	printf("Rentrez des caractères un par un pour y mettre appuyer sur entrée");
	char c;
	do {
		c = getchar();
		printf("%c\n", c);
		if(c >= '0' && c <= '9') {
			printf("Bien jouer c'est un nombre !\n");
		} else {
			printf("Oulala tu n'as pas rentré un nombre gros nul !\n");
		}
	} while(c != '\n');
    return(0);
}