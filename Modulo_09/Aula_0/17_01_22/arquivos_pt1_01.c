#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE *arq; // ponteiro para apontar para o arquivo a ser criado
	
	arq = fopen("texto.txt","w"); // sentando um arquivo no modo "w" pra abri-lo se caso não existir criá-lo
	
	if(arq == NULL)// caso erro na abertura criação do arquivo
	{
		puts("Erro ao abrir/criar arquivo!");
		exit(1);
	}
	else puts("Arquivo criado com sucesso!");
	
	//este trecho escreve letra por letra no arquivo criado, não é um modo eficiente de escreve uma palavra
	fputc('A',arq);
	fputc('L',arq);
	fputc('M',arq);
	fputc('I',arq);
	fputc('R',arq);
	
	
	
	
	fclose(arq); // nunca se esqueça de liberar espaço na memória!!!
		
	return 0;
}
