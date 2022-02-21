#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <malloc.h>

char Table[100][100] = {
	"IAEAVMTMTZF",
	"FAILLEIONEZ",
	"SUNDITUIERP",
	"TTAWEQOVIER",
	"PHPAOJJLANE",
	"EETBNLOEUGF",
	"PNEEBPCUPIE",
	"ITBMOLPFESR",
	"EICHAINESSE",
	"GFBLNITIFAR",
	"EIOBAACYOUA",
	"ZEITEUQSGCI",
	"CEOBOTAUDIS",
	"ACADEMICIEN",
	"EGACEJVERTE"
	};
int Result[50][2];

void printTable(int row){
	printf("\t|");
	for(int i=0, ii= strlen(Table[0]); i< ii; i++)
		printf(" %d |", i + 1);
	printf("\n\n");
	for(int i=0; i< row; i++){
		printf("%d |\t|", i+1);
		for(int j= 0, jj = strlen(Table[i]); j< jj; j++)
			printf(" %c |", Table[i][j]);
		printf("\n---\t");
		for(int k=0, kk= strlen(Table[0]); k< kk; k++)
			printf("----");
		printf("-\n");
	}
}

void reset(){
	for(int i=0; i< 50; i++){
		Result[i][0] = -50;
		Result[i][1] = -50;
	}
}


void printResult(int row, int col, int sizeWord){
	int counter = 0;
	printf("\t|");
	for(int i=0, ii= strlen(Table[0]); i< ii; i++)
		printf(" %d |", i + 1);
	printf("\n\n");
	for(int i=0; i< row; i++){
		printf("%d |\t|", i+1);
		for(int j= 0, jj = strlen(Table[i]); j< jj; j++){
			bool found = false;
			for(int ii=0; ii< sizeWord; ii++){
				if(Result[ii][0] == i && Result[ii][1] == j){
					printf("*%c*|", Table[i][j]);
					found = true; break;
				}
			}
			if(!found)
				printf(" %c |", Table[i][j]);
		}
		printf("\n---\t");
		for(int k=0, kk= strlen(Table[0]); k< kk; k++)
			printf("----");
		printf("-\n");
	}
}


bool find(char* word, int r, int c, char *debugMessage){
	bool found = false;
	char tmp[] = "Trouvé a la lignes %d colonne %d sense ";
	int size = strlen(word);
	int ii= 0, jj= 0;
	for(int i=0; i< r; i++){
		for(int j=0; j< c+1; j++){
			if(word[0] == Table[i][j]){
				found = true; 
				if((c-j+1)>= size){ //look Right
					found = true;
					for(int rigth =0; rigth< size; rigth++){
						if(word[rigth] != Table[i][j + rigth]){
							found = false; break;
						}else{
							Result[rigth][0] = i;
							Result[rigth][1] = j + rigth;
						}
					}
					if(found){
						sprintf(debugMessage, "Trouvé a la lignes %d colonne %d Direction droite\n", i+1, j+1);
						return true;
					}
					if((i+1) >= size){ //Lock on right-top
						ii = i; jj= j;
						found = true;
						for (int rigthTop = 0; rigthTop < size; rigthTop++){
							if(word[rigthTop] != Table[ii--][jj++]){
								found = false; break;
							}else{
								Result[rigthTop][0] = ii+1;
								Result[rigthTop][1] = jj-1;
							}
						}
						if(found){
							sprintf(debugMessage, "Trouvé à la lignes %d colonne %d sense droit-haut\n", i+1, j+1);
							return true;
						}
					}
					if((r-i+1) >= size){ //Lock on right-bottum
						ii = i; jj= j;
						found = true;
						for (int rigthBottum = 0; rigthBottum < size; rigthBottum++){
							if(word[rigthBottum] != Table[ii++][jj++]){
								found = false; break;
							}else{
								Result[rigthBottum][0] = ii-1;
								Result[rigthBottum][1] = jj-1;
							}
						}
						if(found){
							sprintf(debugMessage, "Trouvé à la lignes %d colonne %d sense droit-bas\n", i+1, j+1);
							return true;
						}
					}

				}
				if(j+1 >= size){ //look Left
					found = true;
					for(int left= 0; left< size; left++){
						if(word[left] != Table[i][j - left]){
							found = false; break;
						}else{
							Result[left][0] = i;
							Result[left][1] = j-left;
						}
					}
					if(found){
						sprintf(debugMessage, "Trouvé à la lignes %d colonne %d sense gauche\n", i+1, j+1);
						return true;
					}
					if((i+1) >= size){ //Look Left-top
						ii = i; jj= j; found = true;
						for(int leftTop= 0; leftTop< size; leftTop++){
							if(word[leftTop] != Table[ii--][jj--]){
								found = false; break;
							}else{
								Result[leftTop][0] = ii+1;
								Result[leftTop][1] = jj+1;
							}
						}
						if(found){
							sprintf(debugMessage, "Trouvé à la lignes %d colonne %d sense gauche-haut\n", i+1, j+1);
							return true;
						}
					}
					if((r-i+1) >= size){ //Look left-bottum
						ii = i; jj = j; found = true;
						for(int leftBottum=0; leftBottum< size; leftBottum++){
							if(word[leftBottum] != Table[ii++][jj--]){
								found= false; break;
							}else{
								Result[leftBottum][0] = ii-1;
								Result[leftBottum][1] = jj+1;
							}
						}
						if(found){
							sprintf(debugMessage, "Trouvé à la lignes %d colonne %d sense gauche-bas\n", i+1, j+1);
							return true;
						}
					}
				}
				if(i+1 >= size){ //look top
					found = true;
					for(int top = 0; top< size; top++){
						if(word[top] != Table[i - top][j]){
							found = false; break;
						}else{
							Result[top][0] = i-top;
							Result[top][1] = j;
						}
					}
					if(found){
						sprintf(debugMessage, "Trouvé à la lignes %d colonne %d sense haut\n", i+1, j+1);
						return true;
					}
				}
				if((r-i+1) >= size){ //look Bottum
					found = true;
					for(int bottum = 0; bottum< size; bottum++){
						if(word[bottum] != Table[i + bottum][j]){
							found = false; break;
						}else{
							Result[bottum][0] = i+bottum;
							Result[bottum][1] = j;
						}
					}
					if(found){
						sprintf(debugMessage, "Trouvé à la lignes %d colonne %d sense bas\n", i+1 , j+1);
						return true;
					}
				}

			}else{
				found= false;
			}
		}
	}
	return found;
}

int main(int argc, char const *argv[])
{
	int row, col;
	row = 15; col = 11;
	char word[100];
	char debug[100];
	printf("Aide au jeu de mot mélés\nDimension: ");
	scanf("%d", &row);
	scanf("%d", &col);
	if(row > 100 || col > 100){
		puts("Trop grand!");
		return 0;
	}
	if(row< 1 || col < 1){
		puts("Trop petit!");
		return 0;
	}
	printf("Entrez les lignes:\n\n");
	Table[0][col]= '\0';
	for(int i=0; i< row; i++){
		printf("%d\t", i+1);
		scanf("%s", Table[i]);
		Table[i][row]= '\0';
	}
	printTable(row);
	int sizeWord= 0;
	while(strcmp(word, "QUIT3") !=0 ){
		printf("Entrez le mot à chercher: ");
		scanf("%s", word);
		sizeWord = strlen(word);
		if(find(word, row, col, debug)){
			printResult(row, col, sizeWord);
			printf("%s: %s \n", word, debug);
		}else{
			printTable(row);
			printf("%s, Not found\n", word);
		}
		reset();
	}
	return 0;
}
