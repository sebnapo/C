#include <stdio.h>
#include <stdlib.h>

int chamionnat(int nbEquipe) {
	int N1 = 0;
	if((nbEquipe % 2) == 0) {
		N1 = nbEquipe;
	} else {
		N1 = nbEquipe- 1;
	}
	int NbMatch = N1 / 2;
	int NbJours = N1 - 1;

	for(int i=0; i < NbJours; i++){
		printf("Jours numéro : %d\n", i);
		for (int j = 1; j <= NbMatch; j++)
		{
			printf("Match numéro : %d",j);
			if(j == 1){
				if((nbEquipe % 2) == 0){
					printf("%d Est l'équipe qui reçoit et %d est l'équipe qui se déplace\n",N1,N1+1);
				} else {
					printf("Pas de match aujourd'hui\n");
				}
			} else {
				int Recoit = ((i+j-2)%(N1-1)) +1;
				int deplacement = ((i-j+N1-1)%(N1-1))+1;
				printf("%d Est l'équipe qui reçoit et %d est l'équipe qui se déplace\n",Recoit,deplacement);
			}
		}
	}
	return(0);
}

int main(int argc, char *argv[])
{
    chamionnat(16);
}