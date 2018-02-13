#include "automate.h"
#include <stdio.h>
#include <ctype.h>

enum Etats
{
Debut,
DebutBalise,
NomBalise,
FinBalise,
FinNom,
nomParametre,
Egal,
BaliseFin,
NomBaliseFin,
ParametreSans,
ParametreGuill,
ParametreQuote,
FinParametre,
};

char c;
enum Etats curEtat;
FILE ∗p fi;

if(fi = fopen("test.txt", "rt")) {
	while(!feof(fi)) {
		c = fgetc(fi);
		switch(curEtat) {
			case Debut : 
				if (c == '<') {
					curEtat = DebutBalise;
					break;
				}
			case DebutBalise :
				if(isalpha(c) || c == '_'){
					curEtat = NomBalise;
					break;
				}
				else if(c == '/'){
					curEtat = BaliseFin;
					break;
				}
			
		}
	}
}