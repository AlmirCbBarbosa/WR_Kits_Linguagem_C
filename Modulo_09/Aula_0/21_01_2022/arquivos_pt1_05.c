//sugest�es de atividades
// +criar arquivos em outro diret�rios que n�o seje onde o programa esteja sendo executado
// + verificar outros m�todos de abertura de arquivo alem do para leitura "r" e para escrita "w".

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	FILE  *arq , *carq;
	char nome[20], cnome[20];
	char ch;
	
	//---- abrindo arquivo arq para ler  ok
	puts("Digite o nome do arquivo a ser aberto:");
	gets(nome);
	strcat(nome,".txt");// concatena a extens�o ao nome do arquivo
	
	arq = fopen(nome,"r");
	if(arq == NULL)
	{
		printf("Erro ao abrir o arquivo %s.\n",nome);
		exit(1);
	}else printf("Arquivo %s aberto com sucesso!\n",nome);// deu erro por esquecer de colocar a string de refer�ncia da m�scara %s
	
	
	//---- abrindo arquivo carq para escrever
	printf("Digite o nome da c�pia do arquivo %s:\n",nome);
	gets(cnome);
	strcat(cnome,".txt");// concatena a extens�o .txt ao nome do arquivo
	
	carq = fopen(cnome,"w");
	if(carq == NULL)
	{
		printf("Erro ao criar o arquivo %s!\n", cnome);
		exit(1);
	}else printf("Arquivo %s criado com sucesso!\n",cnome); // deu erro por esquecer de colocar a string de refer�ncia da m�scara %s
	
	//---- printar conte�do de arq na tela e copi�-lo para o carq
	while((fscanf(arq,"%c",&ch)) != EOF)
	{
		printf("%c",ch);
		fprintf(carq,"%c",ch);
	}
	puts("");
	printf("Copia do conte�do do arquivo %s para o arquivo %s foi realizada com sucesso!\n", nome, cnome);
	
	
	//---- fechando os arquivo e liberando mem�ria
	fclose(arq);
	fclose(carq);
	
	return 0;
}
