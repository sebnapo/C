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

struct Pile
{
	char pile[20][20];
	int pos = 0;
}
void addToPile(Pile pile, char* value){
	pile[pile->pos] = value;
	pile->pos++;
}

char* popPile(Pile pile){
	char* valeur = pile[pile->pos];
	pile->pos--;
	return valeur;
}

int size(Pile pile){
	return pile->pos;
}

Pile pile;
char buf[20];
char c;
enum Etats curEtat;
FILE ∗p fi;
bool estFermante = false;
notErreur = true;

if(fi = fopen("test.txt", "rt")) {
	while(!feof(fi) && notErreur) {

		c = fgetc(fi);
		switch(curEtat) {
			case Debut : 
				if (c == '<') {
					curEtat = DebutBalise;
					break;
				} else {
					notErreur = false;
					break;
				}
			case DebutBalise :
				if(isalpha(c) || c == '_'){
					curEtat = NomBalise;
					buf[] = c;
					break;
				}
				else if(c == '/'){
					curEtat = BaliseFin;
					break;
				} else {
					notErreur = false;
					break;
				}
			case NomBalise :
				if(isalpha(c) || c == '_'){
					buf[] = c;
					break;
				}
				else if(c == " "){
					curEtat = FinNom;
					break;
				}
				else if(c == ">"){
					curEtat = FinBalise;
					break;
				} else {
					notErreur = false;
					break;
				}
			case FinBalise :
				if(estFermante == true){
					if(popPile(pile) != buf){
						notErreur = false;
					} else {
						curEtat = Debut;
					}
					break;
				} else {
					addToPile(pile, buf);
					curEtat = Debut;
					break;
				}
			case FinNom :
				if(c == " "){
					break;
				}
				else if(c == ">"){
					curEtat = FinBalise;
					break;
				}
				else if(isalpha(c) || c == '_'){
					curEtat = nomParametre;
				} else {
					notErreur = false;
					break;
				}
			case nomParametre :
				if(isalpha(c) || c == '_'){
					break;
				}
				else if(c == "="){
					curEtat = Egal;
					break;
				} else {
					notErreur = false;
					break;
				}
			case Egal :
				if(c == "'"){
					curEtat = ParametreQuote;
					break;
				}
				else if(c == '"'){
					curEtat = ParametreGuill;
					break;
				}
				else if(isalpha(c) || c == '_'){
					curEtat = ParametreSans;
					break;
				} else {
					notErreur = false;
					break;
				}
			case ParametreQuote :
				if(c != "'"){
					break;
				}
				else if(c == "'"){
					curEtat = FinParametre;
					break;
				} else {
					notErreur = false;
					break;
				}
			case ParametreGuill :
				if(c != '"'){
					break;
				}
				else if(c == '"'){
					curEtat = FinParametre;
					break;
				} else {
					notErreur = false;
					break;
				}
			case ParametreSans :
				if(isalpha(c) || c == '_'){
					break;
				}
				else if(c == ">"){
					curEtat = FinBalise;
					break;
				}
				else if(c == " "){
					curEtat = FinNom;
					break;
				} else {
					notErreur = false;
					break;
				}
			case FinParametre :
				if(c == ">"){
					curEtat = FinBalise;
					break;
				} else {
					notErreur = false;
					break;
				}
			case BaliseFin :
			
		}
	}
}