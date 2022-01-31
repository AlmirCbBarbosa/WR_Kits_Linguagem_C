#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE *arq; // ponteiro para apontar para o arquivo a ser criado
	
	arq = fopen("texto.txt","w"); // sentando um arquivo no modo "w" pra abri-lo se caso n�o existir cri�-lo
	
	if(arq == NULL)// caso erro na abertura cria��o do arquivo
	{
		puts("Erro ao abrir/criar arquivo!");
		exit(1);
	}
	else puts("Arquivo criado com sucesso!");
	
	//este trecho escreve letra por letra no arquivo criado, n�o � um modo eficiente de escreve uma palavra
	fputc('A',arq);
	fputc('L',arq);
	fputc('M',arq);
	fputc('I',arq);
	fputc('R',arq);
	
	
	
	
	fclose(arq); // nunca se esque�a de liberar espa�o na mem�ria!!!
		
	return 0;
}
