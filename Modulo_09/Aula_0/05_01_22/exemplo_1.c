//Programa que cria e escreve em um arquivo de texto

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
	int linha,coluna;
	FILE *arq; // cria um ponteiro que aponta para arquivo
	
	arq= fopen("Amir.txt","w"); // abre ou cria um arquivo na pasta raiz do programa
	
	if(arq == NULL) 
	{
		puts("Erro ao abrir o arquivo");
		exit(1);
	}
	
	for(linha=0; linha<20; ++linha)
	{
		for(coluna=0; coluna<40; ++coluna) fputc('O',arq);
		
		fputc('\n',arq);
	}
	
	fclose(arq);
	puts("mensagem escrita com sucesso!");
	
	return 0;
}
