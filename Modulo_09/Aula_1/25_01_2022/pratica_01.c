#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define tam 30

int main()
{
	FILE *arq, *carq;
	char frase[tam]="Minha familia e tudo.", cfrase[tam];
	int tamanho;
	
	tamanho = strlen(frase);
	
	//printf("%d",strlen(frase)); // funçao da biblioteca strinh.h que verifica o tamanho do arquivo sem o digito nulo "\0".

//---- cria o arquivo e armazena uma frase nele e o salva em formato de bytes.
		
	arq = fopen("texto.dat", "wb");
	if(arq == NULL)
	{
		puts("Erro ao criar o arquivo!!");
		exit(1);
	}
	
	fwrite(frase,sizeof(char),tamanho,arq);
	puts("Arquivo criado com sucesso!");
	
	fclose(arq);
	
//---- criar um outro arquivo que receberá os dados de arq
	
	if((arq = fopen("texto.dat","rb")) ==NULL)	
	{
		puts("Erro ao abrir o arquivo texto.dat!");
		exit(1);
	}
	
	if((carq = fopen("ctexto.bin","wb")) ==NULL)// criando o arquivo que vai receber a cópia de texto.txt
	{
		puts("Erro ao abrir o arquivo ctexto.dat!");
		exit(1);
	}
	
	fread(cfrase,sizeof(char),tamanho,arq);// lê o conteúdo de texto.txt e armazena na string cfrase.
	fwrite(cfrase,sizeof(char),tamanho,carq);//copia o conteúdo da string cfrase e escreve no arquivo ctexto.txt
	
	printf("lido: %s", cfrase);// printa oque foi lido do arquivo arq.
	
	// fechando os arquivo para liberar memória do sistema
	fclose(arq);
	fclose(carq);
	
	return 0;
}
