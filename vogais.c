#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int Nvogal(char *string){
	int i, count = 0;
	for(i = 0; i < strlen(string); i++){
		if(string[i] == 'a' || string[i] == 'e' || string[i] == 'i' || string[i] == 'o' || string[i] == 'u' || string[i] == 'A' || string[i] == 'E' || string[i] == 'I' || string[i] == 'O' || string[i] == 'U'){
			count ++;
		}
	}
	return count;
}

int main(){
	char string[20];
	int c;
	scanf("%s", string);
	c = Nvogal(string);
	printf("%d\n", c);
	return 0;
}
