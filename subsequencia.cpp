#include <stdio.h>
#include <clocale>

int main() {
    setlocale(LC_ALL, "Portuguese");
    int tamanho, i, o;
    int sequencia [tamanho];

	do {
		printf("Qual o tamanho da sequência? ");
		scanf("%i", &tamanho); 
		if (tamanho < 2) {  
			printf("O valor selecionado é inválido, por favor inserir um novo valor \n");
		}
	} while (tamanho < 2);
	printf("tamanho: %i\n", tamanho);
	
	for(i = 0; i < tamanho; i++) {
		printf("%iº valor: ", i+1); // não é aqui o problema
	    scanf("%i", &sequencia[i]);
	    printf("tamanho: %i\n", tamanho);
	} //está mudando o valor do tamanho para o ultimo valor
	
	
	for(o = 0; o < tamanho; o++) {
	    printf("%i ", sequencia[o]);
	}
	printf("\n");
	
	printf("tamanho 3: %i\n", tamanho);
	printf("i: %i\n", i);
   
    return 0;
}
 

// criar um array expansivo, usar o método do maior para o maior número, fazer um método menor(metodo maior mas caso menor seja igual a novo menor, menor = novo menor) para o menor
