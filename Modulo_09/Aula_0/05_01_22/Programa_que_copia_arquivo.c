#include<stdio.h>
#include<stdlib.h>


int main()
{
	FILE *ler, *destino;
	char ch;
	
	ler = fopen("Amir.txt","r");
	
	if(ler == NULL) puts("Erro ao carregar arquivo!!!!");// verifica se o arquivo a ser lido foi carregado com sucesso.
	//if(copiar)
	if((destino = fopen("Copia.txt","w"))) puts("Arquivo criado com sucesso!!!"); // criar e verifica se teve sucesso na ciração do arquivo.
	puts(" ");
	while((ch = fgetc(ler)) != EOF)
	{
		fprintf(destino,"%c",ch);	// não deve se jogar a função fgetc para que a string receba o caracteres pois da erro na cópia.	
		//fprintf(destino,"%c",fgetc(ler)); copia o arquivo de maneiro errada.
		printf("%c",ch);// imprime no console o texto a ser copiado.
	}
	fclose(ler);
	fclose(destino);
	puts("Copia finalizada!!!");
	
	return 0;	
}//fim do programa 
