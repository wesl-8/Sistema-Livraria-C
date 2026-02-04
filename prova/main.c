#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void concatenarinvertido(char str_origem[], char str_destino[],char str_origem2[]){
strcpy(str_destino, str_origem2);
strcat(str_destino, str_origem);


}
int main(){
char frase1[101];
char frase2[101];
char frase3[101];
int s;
printf("Digite frase 1: ");
scanf("%100[^\n]",frase1);
printf("Digite frase 2:\n ");
scanf("%100[^\n]",frase2);
printf("Digite frase 3:\n ");
scanf("%100[^\n]",frase3);
concatenarinvertido(frase1,frase2,frase3);
printf("%s\n",frase1);
 return 0;
}
