//sugestões de atividades
// +criar arquivos em outro diretórios que não seje onde o programa esteja sendo executado
// + verificar outros métodos de abertura de arquivo alem do para leitura "r" e para escrita "w".

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
	strcat(nome,".txt");// concatena a extensão ao nome do arquivo
	
	arq = fopen(nome,"r");
	if(arq == NULL)
	{
		printf("Erro ao abrir o arquivo %s.\n",nome);
		exit(1);
	}else printf("Arquivo %s aberto com sucesso!\n",nome);// deu erro por esquecer de colocar a string de referência da máscara %s
	
	
	//---- abrindo arquivo carq para escrever
	printf("Digite o nome da cópia do arquivo %s:\n",nome);
	gets(cnome);
	strcat(cnome,".txt");// concatena a extensão .txt ao nome do arquivo
	
	carq = fopen(cnome,"w");
	if(carq == NULL)
	{
		printf("Erro ao criar o arquivo %s!\n", cnome);
		exit(1);
	}else printf("Arquivo %s criado com sucesso!\n",cnome); // deu erro por esquecer de colocar a string de referência da máscara %s
	
	//---- printar conteúdo de arq na tela e copiá-lo para o carq
	while((fscanf(arq,"%c",&ch)) != EOF)
	{
		printf("%c",ch);
		fprintf(carq,"%c",ch);
	}
	puts("");
	printf("Copia do conteúdo do arquivo %s para o arquivo %s foi realizada com sucesso!\n", nome, cnome);
	
	
	//---- fechando os arquivo e liberando memória
	fclose(arq);
	fclose(carq);
	
	return 0;
}
