#include <stdio.h>
#include <stdlib.h>

int diagSecundaria(int lin, int col, float matriz[lin][col]) {
	int i, j;
	
	if (lin != col) {
		return 0;
	}
	
	printf("Mostrando pelo primeiro método: \n");
	for (i = 0; i < lin; i++) {
		for (j = 0; j < col; j++) {
			if (i + j == lin - 1) {
				printf("%i %i: %.2f \n", i, j, matriz[i][j]);
			}
		}
	}
	
	printf("Mostrando pelo segundo método: \n");
	for (i = 0; i < lin; i++) {
		printf(":: %i %i: %.2f \n", i, col-1-i, matriz[i][col-1-i]);
	}
	
	return 1;
}

int main(void) {
	int k, l, i, j, min, max,intervalo;
	printf("Informe o tamanho da matriz: \n");
	scanf("%i%i", &k, &l);
	float mat[k][l];
	
	//preenche a matriz
	for (i = 0; i < k; i++) {
		for (j = 0; j < l; j++) {
			mat[i][j] = rand()%10;
		}
	}
	
	//mostra a matriz
	for (i = 0; i < k; i++) {
		for (j = 0; j < l; j++) {
			printf("%.1f ", mat[i][j]);
		}
		printf("\n");
	}
	
	if (diagSecundaria(k, l, mat) == 0) {
		printf("Nao pode ser mostrada");
	}
		
	return 0;
}
