#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE *arq, *carq; // ponteiro para apontar para o arquivo a ser criado
	int ch;
	
	//arquivo arq
	arq = fopen("texto.txt","r"); // setando um arquivo no modo "r" pra para l�-lo
	
	if(arq == NULL)// caso erro na abertura do arquivo
	{
		puts("Erro ao abrir/ler arquivo!");
		exit(1);
	}
	else puts("Arquivo aberto com sucesso!");
	
	//arquivo carq
	carq = fopen("ctexto.txt","w");
	
	if(carq == NULL)
	{
		puts("Erro ao criar o arquivo ctexto.txt!");
		exit(2);
	}
	else puts("Arquivo ctexto.txt criado com sucesso");	
	

/*  //ler caractere por caractere sem 	
	//este trecho l� letra por letra do arquivo aberto, n�o � um modo eficiente de ler um arquivo
	printf("%c",fgetc(arq));
	printf("%c",fgetc(arq));
	printf("%c",fgetc(arq));
	printf("%c",fgetc(arq));
	printf("%c",fgetc(arq)); //como tem cinco estruturas printf, ser�o lidos 5 letras da stream.
*/
	//ler com a fun�ao fgetc() o ponteiro arq e copia para o arquivo criado e setado pelo ponteiro carq, ate que ch = EOF.	
	while((ch = fgetc(arq)) != EOF) 
	{
		printf("%c",ch); // ch � inteiro pois a fun�ao fgetc() retorna int, mas n�o da problemas aparentes se for recebido por um char.
		fputc(ch, carq);
	}
	 
	
	fclose(arq); 
	fclose(carq);
		
	return 0;
}
