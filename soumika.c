#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int * aloca(int tamanho){
	int * vetor;
	if((vetor = (int *) malloc(sizeof(int) * tamanho)) == NULL){
		printf("Sem espaço!\n");
		exit(1);
	}
	return vetor;
}

int * stringParaInt(char * string){
	int * vetorDeInt = aloca(strlen(string));

	for(int i = strlen(string) - 1; i >= 0; i--){
		vetorDeInt[i] = atoi(&string[i]);
		string[i] = '\n';
	}

	return vetorDeInt;
}

int calculaQuantosPares(int * vetor, int tamanho){
	int pares = 0;
	for(int i = 0; i < tamanho; i++)
		if(vetor[i] % 2 == 0) pares ++;

	return pares;
}

int main(){
	char * entrada;
	scanf("%ms", &entrada);
	int m = strlen(entrada);
	int * vetor = stringParaInt(entrada);
	int quantidadeDePares = calculaQuantosPares(vetor, m);
	for(int i = 0; i < m; i++){
		printf("%d ", quantidadeDePares);
		if(vetor[i] % 2 == 0) quantidadeDePares --;
	}
	printf("\n");

	free(vetor);
	free(entrada);

	return 0;
}
