/* Programa vai testar o uso da fun��o feof() para verificar se um arquivo bin�rio chegou ao fim, pois em arquivos
bin�rios n�o temos como ver o fim atrav�s da macro EOF */

//-----------------------------------------------------------
//Bibliotecas

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/**************************************************************
*						Fun��o Principal					  *
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
	
	//-- copiando conte�do da string frase no arquivo texto.txt
	puts("Digite uma frase pra ser armazenada no arquivo texto.dat:");
	gets(frase);
	
	fwrite(frase, sizeof(char),strlen(frase), arq); // copia o conte�do da string no arquivo texto.dat
	
	fclose (arq);
	
	
	//---- copiar o conte�do do  arquivo texto.dat para o arquivo copia.bin
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
	
	while(!feof(arq)) // *****utiliza��o da fun��o objeto da aula*****
	{
		printf("%ld \n", ftell(arq)); // mostra a posi��o atual do ponteiro no arquivo		
		ch = fgetc(arq)	;
		fputc(ch,carq);
		
		if( ftell(arq) == 5)
		{			
			while(linha)
			{
				rewind(arq); // esta fun��o faz o ponteiro do arquivo voltar para a posi��o 0;
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
