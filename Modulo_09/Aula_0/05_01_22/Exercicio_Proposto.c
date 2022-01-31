#include<stdio.h>
#include<stdlib.h>



int main()
{
	FILE *criptografado, *normal;	
	char frase[50]="Curso linguagem C!!!";
	register int i;
	char ch;
	
	criptografado = fopen("codificado.txt","w");
	if(!criptografado)
	{
		puts("Erro ao abrir arquivo para escrita!!!");
		exit(1);
	}
	
	for(i=0; *(frase+i); ++i)// criptografa a mensagem e o grava no arquivo de texto.
	{
		printf("%c",*(frase + i)+3);
		putc(*(frase + i)+3,criptografado);
	}
		
	puts(" ");
		
	fclose(criptografado);
	
	criptografado = fopen("codificado.txt","r"); // reabre o arquivo codificado mas so que no modo leitura "r".
	if(!criptografado)
	{
		puts("Erro ao abrir o arquivo para leitura!!!!");
		exit(2);
	}
	
	normal = fopen("descodificado.txt","w"); // cria um arquivo que vai receber os caracteres do outro arquivo descriptografado.
	if(!normal)
	{
		puts("Erro ao abrir o arquivo de descodificacao!!!");
		exit(3);
	}
	
	while((ch = getc(criptografado)) != EOF)// pegar os caracteres de um arquivo e copia para o outro arquivo decoficado.
	{
		printf("%c",ch-3);
		putc(ch-3,normal);
	}
	fclose(normal);
	fclose(criptografado);
	
	return 0;
}

