#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	FILE *arq;
	char nome[20];	
	
	puts("Digite o endereco e o nome do arquivo a ser criado:");
	scanf("%s",&nome);
	setbuf(stdin,NULL);
	strcat(nome,".dat");
	
	//-- abrindo e verificando o sucesso da cria��o do arquivo
	arq = fopen(nome,"w");
	if( arq == NULL) // n�o estava escrevendo no arquivo bin�rio devido ao erro de colocar um sinal de atribui��o "= ", ao inv�s de compara��o "==".
	{
		printf("O arquivo %s n�o foi criado com sucesso!",nome);
		exit(1); // fun��o da head "stdlib.h"
	}
	
	// Inserindo informa��es de modo particionado
	fputc(0xbc,arq);
	fputc(0x3c,arq);
	
	
	fseek(arq,0x0b,SEEK_SET); // salto de 11 bytes apartir do in�cio do arquivo "SEEK_SET".
	
	fputc(0xa1,arq);
	fputc(0x73,arq);
	
	fclose(arq);
	return 0;
}


