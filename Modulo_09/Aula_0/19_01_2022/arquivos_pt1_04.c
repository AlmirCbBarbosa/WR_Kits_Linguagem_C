#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE  *arq, *carq;
	int linha;
	char frase[50];
	char ch;
	
	// -- primeira parte cria o arquivo texto.txt ------
	//pedi ao usuário uma entrada de frase
	puts("Escreva uma frase:");
	gets(frase);

	//criando o texto.txt
	arq = fopen("texto.txt","w"); //aponta o ponteiro para o local onde o arquivo deve ser criado.
	if(arq == NULL) // teste para verificar se o arquivo foi criado com sucesso
	{
		puts("Erro ao criar o arquivo texto.txt");
		exit(1);
	}//fim if
	else printf("Arquivo texto.txt criado com sucesso!\n \n \n");	
	
	for(linha = 0; frase[linha]; ++linha) // se o caracterer for nulo ele para de rodar o loop
	{
		fprintf(arq,"%c",frase[linha]);// copia caractere por caractere para o arquivo texto.txt
		printf("%c",frase[linha]);// printa o caractere copiado para a tela do console.
	}	
	printf("\n \n \n");
	fclose(arq);
	
	// -----segunda parte reabre o arquivo texto para copiá-lo para o ctexto.txt ----
	
	//abrindo o arquivo texto.txt
	arq = fopen("texto.txt","r");
	if(arq == NULL)
	{
		puts("Erro ao abrir o arquivo texto.txt para leitura!");
		exit(1);
	}
	else printf("Arquivo texto.txt aberto para leitura com sucesso.\n\n\n");
	
	//criando o arquivo ctexto.txt 
	carq = fopen("ctexto.txt","w");
	if(carq == NULL)
	{
		puts("Erro ao criar o arquivo ctexto.txt!");
		exit(1);
	}
	else printf("Arquivo ctexto.txt criado com sucesso!!!\n \n \n");
	
	for(linha = 0; frase[linha]; ++linha)// este laço copia caractere por caractere do arquivo texto.txt pra o arquivo ctexto.txt
	{
		fscanf(arq,"%c",&ch); // pega um caractere do arquivo texto.txt e armazena na variável ch
		fprintf(carq,"%c",ch); // pega o caractere ch e escreve no arquivo ctexto.txt		
	}
	puts("");
	
	fclose(arq);
	fclose(carq);	
	
	return 0;	
}
