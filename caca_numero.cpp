#include <stdio.h>
#include <clocale>
#include <stdlib.h> 

const int N = 5;

int main() {
	int m [N][N];
    setlocale(LC_ALL, "Portuguese");
    int i, j, k, noAnswer = 0, x = 0, y = 0; 	
	
	for (i = 0; i < N; i++ ) {
	    for ( j = 0; j < N; j++ ) {
	    	printf("Preencha a matriz: \n");
	    	printf("%iº fileira, %iº coluna: ", i + 1, j + 1);
	    	scanf("%i", &m[ i ][ j ]);
	    	system("cls");
	  	}
	}; 
	
	/*
	for (i = 0; i < N; i++ ) {
	    for ( j = 0; j < N; j++ ) {
	    	m[i][j] = j;
	  	}
	}; */
	  
	printf("Sua matriz: \n");	
	for (i = 0; i < N; i++ ) {
		printf(" |  ");
	    for (j = 0; j < N; j++ ) {
	    	printf("%i  ", m[ i ][ j ]);
	  	}
	  	printf("| \n");
	}; 
	
	do {
		printf("Qual o tamanho da sequencia que será buscada? ");
		scanf("%i", &k); 
		if (k > N || k < 2) {  
			printf("O valor selecionado é inválido, por favor inserir um novo valor \n");
		}
	} while (k > N || k < 2);
	
	int s [k];
	
	printf("Preencha a sequência: \n");
	for (i = 0; i < k; i++ ) {
    	printf("%iº valor da sequencia: ", i+1);
    	scanf("%i", &s[i]);
	}
	
	printf("Sua sequência desejada é: \n");
	printf("[");
	for (i = 0; i < k; i++ ) {
    	printf(" %i", s[i]);
    	if (i < k - 1) {
			printf(",");
		}
	}
	printf(" ] \n");
	
	//esquerda pra direita 
	for (i = 0; i < N; i++) {
		for (j = 0; j <= N - k; j++) { 
			if (s[x] == m[i][j]){ 
				printf("Primeiro caracter \n");
				y = j;
				do { 
					x++;
					y++;
				} while (s[x] == m[i][y] && x != k); 
				if (x == k) {
					printf("(%i, %i) sentido: esquerda pra direita \n", i, j);
					noAnswer = 1;
				}
				x = 0;
			}
		}
	} 
	
	//direita pra esquerda
	for (i = 0; i < N; i++) {
		for (j = N - 1; j >= k - 1; j--) { 
			if (s[x] == m[i][j]){ 
				printf("Primeiro caracter \n");
				y = j;
				do { 
					x++;
					y--;
				} while (s[x] == m[i][y] && x != k);
				if (x == k) {
					printf("(%i, %i) sentido: direita pra esquerda \n", i, j);
					noAnswer = 1;
				}
				x = 0;
			}
		}
	} 
	
	//cima pra baixo
	for (i = 0; i <= N - k; i++) {
		for (j = 0; j < N; j++) { 
			if (s[x] == m[i][j]){ 
				y = i;
				do { 
					x++;
					y++;
				} while (s[x] == m[y][j] && x != k); 
				if (x == k) {
					printf("(%i, %i) sentido: cima pra baixo \n", i, j);
					noAnswer = 1;
				}
				x = 0;
			}
		}
	} 
	
	//baixo pra cima
	for (i = N - 1; i >= k - 1; i--) {
		for (j = 0; j < N; j++) { 
			if (s[x] == m[i][j]){ 
				y = i;
				do { 
					x++;
					y--;
				} while (s[x] == m[y][j] && x != k); 
				if (x == k) {
					printf("(%i, %i) sentido: baixo pra cima \n", i, j);
					noAnswer = 1;
				}
				x = 0;
			}
		}
	}
	
	if (noAnswer == 0) {
		printf("Sequência não encontrada");
	}

    return 0;
}
