#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
  
int val(char c) 
{ 
    if (c >= '0' && c <= '9') 
        return (float)c - '0'; 
    else
        return (float)c - 'A' + 10; 
} 
   
int toDeci(char *str, int base) 
{ 
    int len = strlen(str); 
    float power = 1;  
    float num = 0;  
    int i; 
  
    for (i = len - 1; i >= 0; i--) 
    { 
        if (val(str[i]) >= base) 
        { 
           printf("Número inválido"); 
           return -1; 
        } 
  
        num += val(str[i]) * power; 
        power = power * base; 
    } 
  
    return num; 
} 


int main(){
    char numero[20];
    int base;
    float resp;

    scanf("%s %d", numero, &base);

    if(base != 10){
    resp = toDeci(numero, base);
    }
    else
    {
        resp = strtof(numero, NULL);
    }
    
    printf("%.2f\n", resp);

    return 0;
}