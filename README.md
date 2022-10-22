# exerc-cios-Programa-o-Algoritmos #hacktoberfest

![](https://hacktoberfestswaglist.com/img/Hfest-Logo-2-Color-Manga.png)

Um conjunto de exercícios de Programação a serem desenvolvidos e solucionados em linguagem de programação C.

## 1° - salario_atual:
Um funcionário de uma empresa recebe, anualmente, aumento salarial. Sabe-se que: 1) esse funcionário foi contratado em 2005 com salário inicial de R$ 1.000,00; 2) em 2006 ele recebeu aumento de 1,5% sobre seu salário inicial; e 3) a partir de 2007, os aumentos salariais sempre corresponderam ao dobro do percentual do ano anterior. Faça um algoritmo que determine o salário atual desse funcionário. O arquivo .c com a solução esperada é "salario_atual.c".

```c
#include <stdio.h>

int main(void) {
	float salario = 1000, aumento = 1.5/100;
	int i, anoIni = 2005, anoFim = 2010;
	
	for (i = anoIni + 1; i < anoFim; i++) {
		salario = salario + (salario * aumento);
		printf("Salario em %i: %.2f - aumento de %.1f\% \n", i, salario, aumento*100);
		aumento = 2 * aumento;
	}
	
	printf("Salario final: %.2f", salario);
	
	return 0;
}
```


## 2° - matriz:
Elabore um algoritmo que solicite ao usuário dois valores inteiros que representam o tamanho de uma matriz que armazena valores inteiros. O algoritmo também deve solicitar um intervalo de valores e preencher a matriz gerada com os valores no intervalo especificado. Valide se os valores do intervalo fornecidos são válidos, onde o primeiro valor deve ser menor do que o segundo. Se os valores não forem válidos, solicite outros até valores válidos serem fornecidos (1,2 ponto). Em seguida, o algoritmo deve determinar qual o segundo maior valor da matriz e uma posição (índices da matriz) esse valor pode ser encontrado (o valor pode ter se repetido na matriz, mas apenas uma das posições deve ser mostrada) (1,8 pontos).  O arquivo .c com a solução esperada é "matriz.c".

```c
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
```

## 3° -  diagonal_secundaria:
Elabore uma função que recebe uma matriz e mostre a diagonal secundária da matriz (a função pode receber mais argumentos do que somente a matriz). Se a função pode mostrar a diagonal ela retorna 1, senão ela retorna zero.

![q3](http://www.galirows.com.br/meublog/programacao/wp-content/uploads/sites/2/2018/06/diagSecundaria-300x158.gif)

Dica: em uma matriz quadrada, a diagonal principal é formada pelos elementos aij tais que i = j. Na diagonal secundária, temos i + j = n + 1.
Vale uma consideração importante aqui: é preciso lembrar que na programação em linguagem C, a matriz inicia nas linha e coluna com índice zero. Com isso é preciso adaptar o teste para determinar as posições da diagonal secundária. O arquivo .c com a solução esperada é "diagonal_secundaria.c"

```c
#include <stdio.h>
 
int main(void) {
	int mat[3][3] = {1,3,5,3,7,2,0,5,1}, i, j, maior, smaior;
 
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
```

## 4° - leitura:
Elabore um algoritmo que leia uma string (um texto) e determine um valor correspondente a quantas letras ‘a’ (maiúsculas ou minúsculas) existem na string. Calcule a fatorial do valor determinado e mostre quantos números múltiplos de 3 existem no intervalo entre 1 e o fatorial calculado.
O arquivo .c com a solução esperada é "leitura.c"

```c
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
```

##

![Badge em Desenvolvimento](https://img.shields.io/static/v1?label=STATUS&message=EM%20DESENVOLVIMENTO&color=GREEN&style=for-the-badge)
