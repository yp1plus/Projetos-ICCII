/* Somsom - 2019 */

#include <string.h>
#include <stdio.h>

void strsub(char *s1, char *s2, char *s3, char *s4){
    
    int s1Len = strlen(s1);
    int s2Len = strlen(s2);
    int s3Len = strlen(s3);

    // generalizando caso teste 2
    if(strcmp(s3, "\"\"") == 0){
        s3Len = 0;
    }

    int i, index;

    // procurando a substring em s1
    for(i = 0; i < s1Len; i++){
        if(strncmp(s1 + i, s2, s2Len) == 0){
            index = i;
            break;
        }
    }

    // comecando a montar a string resposta
    strncpy(s4, s1, index + 1);

    // inserindo a string desejada na string resposta
    strncpy(s4 + index, s3, s3Len);

    // completando o final da string resposta
    strncpy((s4 + index + s3Len), (s1 + index + s2Len), (s1Len - (index + 1) + s2Len));

}

int main(void){

    char s1[100];
    char s2[100];
    char s3[100];
    char s4[100];

    scanf("%s%s%s", s1, s2, s3);
    strsub(s1, s2, s3, s4);
    printf("%s\n", s4);

    return 0;
}