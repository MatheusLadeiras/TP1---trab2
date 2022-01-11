#include <stdio.h>
#include <clocale>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

int main() {
    setlocale(LC_ALL, "Portuguese");
    float resultado = 0;
    int i, posicao = 0, invalido = 0, desligar = 0; 
    char expressao[100];
    char input [1];
    int holdNumberInput;
    char holdSignInput;
    
    // paramos a checagem em 4 * - 8
    // - em próximo numeral deu 45, o problema disso não está na leitura, eu tenho que fazer a impressão ler como %c em vez de %i
    //opicional: fazer aparecer a expressao depois de colocar cada valor 
    
    
    printf("ATENÇÃO: Para sair da calculadora, aperte enter sem ter colocado um valor. \n");
    printf("Qual o primeiro número da expressão? ");
    fgets(input, 2, stdin);
	if (input[0] == '\n') {
		desligar++;
		invalido = invalido - 1;
		expressao[0] = 0;
		printf("Desligando a calculadora, resultado final: \n"); 
	} else {
    	resultado = atoi(input);
		expressao[0] = resultado; 
	}
	
    /* printf("resultado: %f \n", resultado);
    printf("expressao: %i \n", expressao[0]);
	printf("input: %s \n", input); */
	
    
    do {

    	if (desligar == 0) {
			posicao = posicao + 1; 
	    	//printf("posicao: %i \n", posicao);
	    	printf("Digite o sinal da operação: "); 
	    	fflush(stdin);
	    	fgets(input, 2, stdin);
	    	if (input[0] == '\n') {
	    		desligar++;
	    		invalido = invalido - 1;
	    		posicao = posicao - 1;
	    		printf("Desligando a calculadora, resultado final: \n"); 
			} else {
		    	holdSignInput = input[0];
				expressao[posicao] = holdSignInput; 
			}
				/* printf("holdSignInput: %c \n", holdSignInput);
				 printf("resultado: %f \n", resultado);
		   		 printf("expressao: %i \n", expressao[0]);
				 // printf("expressao: %s \n", expressao);*/
				 //printf("input: %s \n", input); 
    	}
    	

    	if (desligar == 0) {
			posicao = posicao + 1;
	    	printf("Digite o próximo numeral da operação: ");
	    	fflush(stdin);
	    	fgets(input, 2, stdin);
	    	if (input[0] == '\n') {
	    		desligar++; 
	    		posicao = posicao - 1;
	    		printf("Desligando a calculadora, resultado final: \n"); 
			} else if (!isdigit(input[0])) {
				invalido++;
				holdSignInput = input[0];
				expressao[posicao] = holdSignInput; 
			} else {
		    	holdNumberInput = atoi(input);
				expressao[posicao] = holdNumberInput; 
			}
				 /*printf("resultado: %f \n", resultado);
		   		 printf("expressao: %i \n", expressao[0]);
				 // printf("expressao: %s \n", expressao);
				 printf("input: %s \n", input); */
		
	
	    	switch(expressao[posicao - 1]) {
	    		case '+': resultado = resultado + expressao[posicao];
	    		break;
	    		case '-': resultado = resultado - expressao[posicao];
	    		break;
	    		case '*': resultado = resultado * expressao[posicao];
	    		break;
	    		case '/': resultado = resultado / expressao[posicao];
	    		break;
	    		case '^': resultado = pow(resultado, expressao[posicao]);
	    		break;
	    		default: invalido++;
	    		break;
			}
		
		}
		 
		for(i = 0; i <= posicao; i++) {
			int c = 0;
			c == expressao[i];
			if (isdigit(c)) { // só o de baixo está pegando
				printf("%i ", expressao[i]);
			} else {
				printf("%c ", expressao[i]);
			}
		} 
		
		//método antigo
		/* for(i = 0; i <= posicao; i++) {
			printf("%i ", expressao[i]);
			i++;
			printf("%c ", expressao[i]);
		} */
		
		if (invalido >= 1) {
			printf("é uma Expressão inválida\n", resultado);
		} else {
			printf("que dá um total de: %f \n", resultado);
		}
		
	} while (desligar == 0); 
   
    return 0;
}

