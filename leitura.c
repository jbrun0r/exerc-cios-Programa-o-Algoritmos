/*Elabore um algoritmo que leia uma string (um texto) e determine um valor correspondente a 
quantas letras ‘a’ (maiúsculas ou minúsculas) existem na string. Calcule a fatorial do valor 
determinado e mostre quantos números múltiplos de 3 existem no intervalo 
entre 1 e o fatorial calculado*/
#include <stdio.h>

int fatorial(int x) {
	int i, res = 1;
	
	for (i = x; i > 1; i--) {
		res = res * i;
	}
	return res;
}

int main(void) {
	int num, fat, cont=0, contA=0, i;
	char texto[100];
	//scanf("%s", &texto);
	gets(texto);
	
	//conta ocorrencias da letra "a"
	for (i = 0; i < strlen(texto); i++) {
		if (texto[i] == 'a' || texto[i] == 'A') {
			contA++;
		}
	}
	
	fat = fatorial(contA);

	for (i = 1; i <= fat; i++) {
		if (i % 3 == 0) {
			cont++;
			printf("%i \n", i);
		}
	}
	
	printf ("Fatorial: %i \nQtd a: %i \nMultiplos de 3: %i", fat, contA, cont);
	printf ("\nMultiplos de 3: %i", fat/3);
	
	return 0;
}
