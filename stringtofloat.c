#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int nstrlen(char* string);
float potencia(int base, int expoente);

int nstrlen(char* string){
	int i;
	
	for(i=0;;i++){
		if(string[i]=='\0') return (i+1);
	}
}

float potencia(int base, int expoente){
    int i,acm=1;
    float resultado;
    
    if(expoente==0) return 1.0;
    
    if (expoente>0){
        for(i=0;i<expoente;i++){
            acm=acm*base;
        }
    return ((float)acm);
    } else{
        expoente=expoente*-1;
        if((1/potencia(base,expoente))!=0) resultado=1/potencia(base,expoente);
        return (resultado);
    }
    
    return 0;
}

int main(void){

	char stringdonumero[100];
	int i,j,cont,pontopos;
	int tamanhodonumero;
	int base;
	float resultado=0;
	
	scanf("%s",stringdonumero);
	scanf("%d",&base);
	
	tamanhodonumero=nstrlen(stringdonumero);
	
	for(i=0;i<tamanhodonumero-1;i++){
	    if(stringdonumero[i]=='.'){
	        cont=-1;
	        pontopos=i-1;
	        for(j=i+1;j<tamanhodonumero-1;j++){
	            resultado+=(float)(((int)stringdonumero[j]-48)*potencia(base,cont));
	            cont--;
	        }
            break;
	    }
        else if (i == tamanhodonumero - 2){
            pontopos = i;
        }
	}
	
	cont=0;
	
	for(i=pontopos;i>=0;i--){
	   resultado+=(float)(((int)stringdonumero[i]-48)*potencia(base,cont));
	   cont++;
	}
	
	printf("%.2f\n",resultado);
    


    return 0;
}



/*

/* By Yure Pablo em Agosto de 2019 
 * Programa que converte string para float na base indicada
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define decimal_base 10
#define MAX_CARACTERES  100

typedef char string;

float strtofloat(char *string, int base){
    if (base == decimal_base) 
        return strtof(string, NULL); //chama a funcao que converte string p/float diretamente
    else 
        return (float) strtoul(string, NULL, base); //chama a funcao que converte string p/ unsigned int na base indicada
}

int main(void){
    string value[MAX_CARACTERES];
    int base;

    scanf("%s %d", value, &base);
    
    printf("%.2f\n", strtofloat(value, base));
 
    return 0;
}
*/ 
