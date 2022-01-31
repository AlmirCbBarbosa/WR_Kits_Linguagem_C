/* Estudo da função fseek() e suas utilidades */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//***********Protótipo de funções*******************
void limpar_tela();
void verificando_arquivo(FILE *arquivo, char *caminho);

//***********Função Principal***********************
int main ()
{
	FILE *arq;
	char nome[30], texto[200];
	long int tamanho_texto;
	
	puts("Digite o endereco e o nome do arquivo criado:");
	scanf("%s",&nome);
	setbuf(stdin,NULL);
	strcat(nome,".dat"); // concatena a string ".dat" no fim da string nome
	
	arq = fopen(nome,"wb");
	
/*
	if((arq = fopen(nome,"wb")) == NULL) // cria e verifica se houve sucesso
	{
		printf("O arquivo %s não foi aberto com sucesso!\n",nome);
		exit(1);
	}// fim if
	else printf("O arquivo %s foi criado com sucesso!\n",nome);
*/	
	verificando_arquivo(arq, nome);
	limpar_tela();//pausa e limpa a tela
	
	//-- Escrevendo um texto para ser armazenado no arquivo criado
	printf("Escreva um texto para ser armazenado no arquivo %s.\n",nome);
	gets(texto);
	
	tamanho_texto = strlen(texto);
	fwrite(texto,sizeof(char),tamanho_texto,arq); // escreve o conteúdo da string texto no arquivo criado apontado pelo arq.
	
	fclose(arq); // fechando o arquivo apontado por arq
	
	//** função alvo de estudo - verificar o tamanho do arquivo arq.
	arq = fopen(nome,"rb");
	verificando_arquivo(arq,nome);
	limpar_tela();
	
	fseek(arq,0,2);// ***função alvo de estudo
	printf("O tamaho do %s e de %ld caracteres.", nome, ftell(arq)); 
	
	return 0;
}// fim função principal

//*******************Desenvolvimento Funções*****************************
void limpar_tela()
{
	system("pause");
	system("cls");
}







void verificando_arquivo(FILE *arquivo, char *caminho)
{
	if(arquivo  == NULL) // cria e verifica se houve sucesso
	{
		printf("O arquivo %s não foi aberto com sucesso!\n",caminho);
		exit(1);
	}// fim if
	else printf("O arquivo %s foi criado com sucesso!\n",caminho);	
}
	
	
