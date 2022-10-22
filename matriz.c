#include <stdio.h>

int main(void) {
	int mat[3][3] = {1,3,5,
		     3,7,2,
		     0,5,1}, i, j, maior, smaior;
	
	maior = mat[0][0];
	smaior = maior;
	for (i = 0; i < 3; i++) {
		for (j=0; j < 3; j++) {
			if (mat[i][j] > maior) {
				smaior = maior;
				maior = mat[i][j];
			}	
		}
	}
	
	for (i = 0; i < 3; i++) {
		for (j=0; j < 3; j++) {
			if (mat[i][j] == smaior) {
				printf("Posicao: %i %i\n", i, j);
				i = 5;
				j = 5;
			}	
		}
	}

	printf("Maior: %i \n", maior);
	printf("Segundo Maior: %i", smaior);
	return 0;
}
