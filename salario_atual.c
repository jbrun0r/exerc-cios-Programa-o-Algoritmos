#include <stdio.h>
#include <stdlib.h>
 
int main(void) {
	int k, l, i, j, min, max,intervalo;
	
	//cria matriz do tamanho informado pelo usuario
	printf("Informe o tamanho da matriz: ");
	scanf("%i%i", &k, &l);
	float mat[k][l];
 
	//preenche a matriz em um intervalo informado pelo usuario
	printf("Defina o intervalo: ");
	scanf("%i%i", &min, &max);
	while (max < min) {
		printf("Intervalo invalido. Digite novos valores: ");
		scanf("%i%i", &min, &max);
	}
	
	intervalo = max - min;
	printf("Intervalo: %i \n", intervalo);
 
	for (i = 0; i < k; i++) {
		for (j = 0; j < l; j++) {
			mat[i][j] = rand()%intervalo + min; 
		}
	}
 
	//mostra a matriz
	for (i = 0; i < k; i++) {
		for (j = 0; j < l; j++) {
			printf("%.1f ", mat[i][j]);
		}
		printf("\n");
	}
 
	return 0;
}