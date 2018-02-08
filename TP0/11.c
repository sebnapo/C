#include <stdio.h>
#include <stdlib.h>

int getNombre() {
	printf("Rentrez un nombre");
	char c = '0';
	do {
		c = getchar();
		if(c >= '0' && c <= '9') {
			printf("%c\n",c );
			c += c;
		} else {
			return c;
		}
	} while(1);
    return c;
}

char getOperande(char fin) {
	printf("Rentrez un opérande");
	char c = '0';
	do {
		c = getchar();
		printf("%c\n", c);
		if(c < '0' || c > '9') {
			return c;
		}
	} while(c != fin);
    return c;
}

int main(int argc, char *argv[])
{
	printf("Rentrez l'opération et appuyer sur entree");
	char c;
	int nombre;
	int nombre1;
	char operande;
	char operande2;
	int result;
	nombre = getNombre();
	printf("%c\n",nombre);
	operande = getOperande('=');
	printf("%c\n",operande );
	nombre1 = getNombre();
	printf("%c\n",nombre1);
	operande2 = getOperande('=');
	if(operande2 == '='){
		switch(operande) {
			case '+' :
				result = nombre + nombre1;
			case '-' :
				result = nombre - nombre1;
			case '/' :
				result = nombre / nombre1;
			case '*' :
				result = nombre * nombre1;
			case '%' :
				result = nombre % nombre1;
		}
	}
	printf("%d\n", result);
    return(0);
}