#include <stdio.h>
#include <clocale>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

// Essa versão foi minha tentativa de fazer o exercicio 2, ao me deparar com uma duvida, falei com o professor e ele apontou que eu entendi o exercício de forma incorreta
// apesar disso eu descobri o erro ao me deparar com o mesmo problema ao fazer o exercício de forma correta, assim, consertei aqui
// essa versão consegue entregar as respostas corretas apesar de receber a expressão de forma errada e ter expressões desnecessárias 
int main() {
    setlocale(LC_ALL, "Portuguese");
    float resultado = 0;
    int i = 0, posicao = 0, invalido = 0, desligar = 0; 
    char expressao[100];
    char input [1];
    int holdNumberInput;
    char holdSignInput;
    int c;

    
    printf("ATENÇÃO: Para sair da calculadora, aperte enter sem ter colocado um valor. \n");
    printf("Qual o primeiro número da expressão? ");
    fgets(input, 2, stdin);
	if (input[0] == '\n') {
		desligar++;
		invalido = invalido - 1;
		expressao[0] = 0;
		printf("Desligando a calculadora, resultado final: \n"); 
	} else if (!isdigit(input[0])) {
		invalido = invalido + 2;
		holdSignInput = input[0];
		expressao[posicao] = holdSignInput; 
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
		
		i = 0;
		while(expressao[i] != '\0'){
		c = expressao[i] + '0';
	        if(isdigit(c)) {
	             printf("%i ",expressao[i]);
	        } else {
				printf("%c ", expressao[i]);
			} 
	        i++;
    	}
   
		
		if (invalido >= 1) {
			printf("é uma Expressão inválida\n", resultado);
		} else {
			printf("que dá um total de: %f \n", resultado);
		}
		
		
	} while (desligar == 0); 
   
    return 0;
}

