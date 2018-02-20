#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int testTri(int *tab, int size){
	int last = 0;
	for(int z =0; z < size; z++){
		if(tab[z] <= last){
			return 0;
		} else last = tab[z];
	}
	return 1;
}

void initTab(int* tab, int size){
	for(int i =0; i < 50; i++){
		tab[i] = rand();
		printf("%d\n",tab[i]);
	}
}

int triInterne( int tab[], int debut, int fin) {
   int pivot, i, j, t;
   pivot = tab[debut];
   i = debut; j = fin+1;
		
   while( 1)
   {
   	do ++i; while( tab[i] <= pivot && i <= fin );
   	do --j; while( tab[j] > pivot );
   	if( i >= j ) break;
   	t = tab[i]; tab[i] = tab[j]; tab[j] = t;
   }
   t = tab[debut]; tab[debut] = tab[j]; tab[j] = t;
   return j;
}
void quickSort(int tab[], int debut, int fin)
{
   int j;

   if( debut < fin ) 
   {
       j = triInterne( tab, debut, fin);
       quickSort( tab, debut, j-1);
       quickSort( tab, j+1, fin);
   }
	
}

void printTab(int* tab, int size){
	for(int i =0; i < size; i++){
		printf("%d\n",tab[i]);
	}
}


int main(int argc, char *argv[])
{
	int tab[50];
	initTab(tab,50);
	srand(time(NULL));
	if(testTri(tab,50)){
		printf("Tableau trie de base");
	} else {
		printf("Tableau non trie au depart");
	}
	quickSort(tab,0,50);
	printTab(tab,50);
    return(0);
}