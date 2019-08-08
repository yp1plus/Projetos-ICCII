#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void strsubst(char *s1, char * s2, char * s3){
    int i, flag = 0, j = 0;
    //printf("%ld\n", strlen(s1));
    for(i = 0; i < strlen(s1); i++){
        if(s1[i] == s2[flag]){
            //printf("s1[%d] == %c, s2[%d] == %c\n", i, s1[i], flag, s2[flag]);
            flag++;
        }
        else{
            flag = 0;
        }
        if(flag == 1){
            //printf("j = %d\n", j);
            j = i;
        }
        if(flag == strlen(s2)){
            //printf("%s\n", s1);
            strcpy(s1 + j, s3);
        }
    }
}

int main(){
    char s1[20], s2[20], s3[20];
    //printf("\"\"");

    scanf("%s %s %s", s1, s2, s3);
    if(!strcmp(s3, "\"\"")){
        strcpy(s3, "");
    }
    strsubst(s1, s2, s3);
    printf("%s\n", s1);

    return 0;
}