/* By Yure Pablo em Agosto de 2019 
 * Programa que converte string para float na base indicada
 */
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
        return (float) strtoul(string, NULL, base); //chama a funcao que converte string p/int na base indicada
}

int main(void){
    string value[MAX_CARACTERES];
    int base;

    scanf("%s %d", value, &base);
    
    printf("%.2f\n", strtofloat(value, base));
 
    return 0;
}
