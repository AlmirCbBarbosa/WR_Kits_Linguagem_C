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
	
	//-- abrindo e verificando o sucesso da criação do arquivo
	arq = fopen(nome,"w");
	if( arq == NULL) // não estava escrevendo no arquivo binário devido ao erro de colocar um sinal de atribuição "= ", ao invés de comparação "==".
	{
		printf("O arquivo %s não foi criado com sucesso!",nome);
		exit(1); // função da head "stdlib.h"
	}
	
	// Inserindo informações de modo particionado
	fputc(0xbc,arq);
	fputc(0x3c,arq);
	
	
	fseek(arq,0x0b,SEEK_SET); // salto de 11 bytes apartir do início do arquivo "SEEK_SET".
	
	fputc(0xa1,arq);
	fputc(0x73,arq);
	
	fclose(arq);
	return 0;
}


