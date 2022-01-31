#include<stdio.h>
#include<stdlib.h>


int main()
{
	FILE *arq;
	char endereco[50], frase[50] = "eu amo minha vida.";
	
	puts("escreva o endereco e o nome do arquivo a ser criado:");
	gets(endereco); // pode criar o arquivo mas o diretorio digitado deve existir pois ele não cria pasta
	
	arq = fopen(endereco,"w");
	if(arq ==NULL)
	{
		printf("Erro ao criar o arquivo local %s",endereco);
		exit(1);
	}
	else puts("Arquivo criado com sucesso!");
	
	fputs(frase,arq);
	
	fclose(arq);
	
	
	return 0;
}
