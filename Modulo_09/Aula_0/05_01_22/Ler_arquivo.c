//Programa que abre e lê um arquivo

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
	int  ch;
	
	
	FILE *ler;
	
	ler = fopen("Amir.txt","r");// abrir o arquivo para leitura pois o ultimo parâmetro é o "r".
	if(ler == NULL) 
	{
		puts("Erro ao abrir o arquivo !!!");
		exit(1);//pertence a biblioteca stdlib.h
	}
	
	while((ch = fgetc(ler)) != EOF) // EOF é uma macro do tipo inteira que fica no final do arquivo.
		printf("%c",ch);
	
	fclose(ler);
	puts("Arquivos lidos com sucesso!!!");
	
	return 0;
}
