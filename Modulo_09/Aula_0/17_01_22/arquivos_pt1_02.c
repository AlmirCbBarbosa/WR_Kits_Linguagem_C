#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE *arq; // ponteiro para apontar para o arquivo a ser criado
	int ch;
	
	arq = fopen("texto.txt","r"); // setando um arquivo no modo "r" pra para lê-lo
	
	if(arq == NULL)// caso erro na abertura do arquivo
	{
		puts("Erro ao abrir/ler arquivo!");
		exit(1);
	}
	else puts("Arquivo aberto com sucesso!");

/*  //ler caractere por caractere sem 	
	//este trecho lê letra por letra do arquivo aberto, não é um modo eficiente de ler um arquivo
	printf("%c",fgetc(arq));
	printf("%c",fgetc(arq));
	printf("%c",fgetc(arq));
	printf("%c",fgetc(arq));
	printf("%c",fgetc(arq)); //como tem cinco estruturas printf, serão lidos 5 letras da stream.
*/
	//ler com a funçao fgetc até encontra a constante EOF que indica o fim da stream
	
	while((ch = fgetc(arq)) != EOF) printf("%c",ch); // ch é inteiro pois a funçao fgetc() retorna int, mas não da problemas aparentes se for recebido por um char.
	
	
	
	
		
	return 0;
}
