#include <stdio.h>
#include <clocale>
#include <string.h>

int main() {
    setlocale(LC_ALL, "Portuguese");
    int tamanho, i, o, subsequecia_tam, maior = 0, subsequencia_soma = 0, x = 0, u = 0, menor;

	do {
		printf("Qual o tamanho da sequência? ");
		scanf("%i", &tamanho); 
		if (tamanho <= 2) {  
			printf("O valor selecionado é inválido, por favor inserir um novo valor \n");
		}
	} while (tamanho <= 2);
	//printf("tamanho: %i\n", tamanho);
	
	int sequencia [tamanho]; //tem que ficar aqui ou um undefined behavior vai ocorrer
	
	for(i = 0; i < tamanho; i++) {
		printf("%iº valor: ", i+1);
	    scanf("%i", &sequencia[i]);
	    //printf("tamanho: %i\n", tamanho);
	} 
	
	for(i = 0; i < tamanho; i++) {
	    printf("%i ", sequencia[i]);
	}
	printf("\n");
	
	do { 
		printf("Qual o tamanho das subsequência? ");
		scanf("%i", &subsequecia_tam); 
		if (subsequecia_tam < 2 || subsequecia_tam > tamanho - 1) {  
			printf("O valor selecionado é inválido, por favor inserir um novo valor \n");
		}
	} while (subsequecia_tam < 2 || subsequecia_tam > tamanho - 1);
	
	int subsequencia [subsequecia_tam];
	int maiorSubsequencia [subsequecia_tam];
	
	for (o = 0; o <= tamanho - subsequecia_tam; o++) {
		for (i = o; i < subsequecia_tam + o; i++) { 
			subsequencia_soma += sequencia[i];
			subsequencia[0 + x] = sequencia[i];
			// printf("subsequencia = [ %i  ] \n", subsequencia[x]);
			if (subsequencia_soma > maior) {
				maior = subsequencia_soma;
				for(u = 0; u < subsequecia_tam; u++) {
				    maiorSubsequencia[u] = subsequencia[u];
				}    
			}	
			x++;
		}
		subsequencia_soma = 0;	
		x = 0;
		/*printf("maior: %i \n", maior);
		printf("Soma da subsequencia: %i \n", subsequencia_soma);
		printf("======================================================================================================\n"); */
	}
	
	printf("A maior subsequencia é = [");	
	for (i = 0; i < subsequecia_tam; i++) {
		printf(" %i", maiorSubsequencia[i]);
		if (i < subsequecia_tam - 1) {
			printf(",");
		}
	}
	printf(" ] ");
	
	printf("que dá um valor total de %i. \n", maior);
	
	int menorSubsequencia [subsequecia_tam];
	menor = maior;
	
	for (o = 0; o <= tamanho - subsequecia_tam; o++) { 
		for (i = o; i < subsequecia_tam + o; i++) {
			subsequencia_soma += sequencia[i]; 
			subsequencia[0 + x] = sequencia[i];
			//printf("subsequencia = [ %i  ] \n", subsequencia[x]);
			x++;
		}
		if (subsequencia_soma <= menor) { 
			menor = subsequencia_soma;
			for(u = 0; u < subsequecia_tam; u++) {
			    menorSubsequencia[u] = subsequencia[u];
			}    
		}	
		subsequencia_soma = 0;	
		x = 0;	
		/*printf("menor: %i \n", menor);
		printf("Soma da subsequencia: %i \n", subsequencia_soma);
		printf("======================================================================================================\n"); */
	}
	
	printf("A menor subsequencia é = [");	
	for (i = 0; i < subsequecia_tam; i++) {
		printf(" %i", menorSubsequencia[i]);
		if (i < subsequecia_tam - 1) {
			printf(",");
		}
	}
	printf(" ] ");
	
	printf("que dá um valor total de %i. \n", menor);

   
    return 0;
}
 

// criar um array expansivo, usar o método do maior para o maior número, fazer um método menor(metodo maior mas caso menor seja igual a novo menor, menor = novo menor) para o menor
