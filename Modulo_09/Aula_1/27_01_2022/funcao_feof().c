/* Programa vai testar o uso da função feof() para verificar se um arquivo binário chegou ao fim, pois em arquivos
binários não temos como ver o fim através da macro EOF */

//-----------------------------------------------------------
//Bibliotecas

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/**************************************************************
*						Função Principal					  *
**************************************************************/
int main()
{
	FILE *arq, *carq;
	
	char frase[20];
	char ch;
	int linha = 1;
	
	if((arq = fopen("texto.dat","wb")) == NULL) // criando o arquivo texto.txt
	{
		puts("Erro ao criar o arquivo texto.dat");
		exit(1);
	}
	
	//-- copiando conteúdo da string frase no arquivo texto.txt
	puts("Digite uma frase pra ser armazenada no arquivo texto.dat:");
	gets(frase);
	
	fwrite(frase, sizeof(char),strlen(frase), arq); // copia o conteúdo da string no arquivo texto.dat
	
	fclose (arq);
	
	
	//---- copiar o conteúdo do  arquivo texto.dat para o arquivo copia.bin
	if((arq = fopen("texto.dat","rb")) == NULL)
	{
		puts("Erro ao abrir o arquivo texto.dat para leitura!");
		exit(1);	
	}
	
	if((carq = fopen("copia.bin","wb")) == NULL)
	{
		puts("Erro ao criar o arquivo copia.bin!");
		exit(1);	
	}
	
	while(!feof(arq)) // *****utilização da função objeto da aula*****
	{
		printf("%ld \n", ftell(arq)); // mostra a posição atual do ponteiro no arquivo		
		ch = fgetc(arq)	;
		fputc(ch,carq);
		
		if( ftell(arq) == 5)
		{			
			while(linha)
			{
				rewind(arq); // esta função faz o ponteiro do arquivo voltar para a posição 0;
				fputc(' ',carq);
				linha = 0;
			}
		}
	}
	puts("");
	fclose(arq);
	fclose(carq);
	
	return 0;
}
