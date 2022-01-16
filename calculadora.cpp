#include <stdio.h>
#include <clocale>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

int main() {
    setlocale(LC_ALL, "Portuguese");
    float resultado = 0;
    int i = 0, posicao = 0, invalido = 0, intercalar = 0, space = 0, x = 0; 
    char expressao[101];
    char operacao;
    int k ;
	char c;
    
    do { 
    
    printf("Digite a expressão a ser calculada: ");
    gets(expressao);
    
    resultado = atoi(expressao);
    
	    i = 0;
	    posicao = 0;
	    invalido = 0;
	    intercalar = 0;
	    space = 0;
		x = 0; 
		
	    while(expressao[i] != '\0') {
	    	k = expressao[i];
	    	if (isspace(expressao[i])) {
	    		//printf("isspace \n");
			} else if (isdigit(k)) {  
	    		if (intercalar == 1) {
	    			invalido = 1;
				}
				intercalar = 1;
			} else {
				space = 0;
				x = i+1;
				while (isspace(expressao[x])) {
					space += 1;
					x++;
				}
				operacao = expressao[i+1+space] - '0'; 
				switch(expressao[i]) { 
		    		case '+': resultado = resultado + operacao; 
		    		break;
		    		case '-': resultado = resultado -  operacao;
		    		break;
		    		case '*': resultado = resultado *  operacao;
		    		break;
		    		case '/': resultado = resultado /  operacao;
		    		break;
		    		case '^': resultado = pow(resultado,  operacao);
		    		break;
		    		default: invalido = 1;
		    		break;
				}
				if (intercalar == 0) { 
	    			invalido = 1;
				}
				intercalar = 0;
			}
	    	i++;
	    }
	    // printf("invalido: %i \n", i); 
	    
	    if (!isdigit(k)) {
	    	invalido = 1;
		}
	    
	    if (invalido == 1) { 
	    		printf("A expressão %s ", expressao);
				printf("é uma Expressão inválida\n");
			} else if (expressao[0] != '\0') {
				printf("A expressão %s ", expressao);
				printf("resulta em: %f \n", resultado);
		} else {
			printf("Fechando a calculadora \n");
		}
		
	} while (expressao[0] != '\0');
   
    return 0;
}

