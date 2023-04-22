#include <stdio.h>

// stdout, stdin, stderr

int main(int argc, char** argv)
{
	FILE *entrada, *saida; // cria 2 ponteiros para arquivos, 1 para entrada e outra para saída 
	int c; // cria um int para pegar cada caractere do arquivo

	if(argc != 3) // se os argumentos passados forem diferentes de 3 entra no if
	{
		fprintf(stderr,"Erro na chamada do comando.\n");
		fprintf(stderr,"Uso: %s [ARQUIVO ORIGEM] [ARQUIVO DESTINO].\n", argv[0]);
		return 1;
	}

	entrada = fopen(argv[1],"rb"); // entrada recebe a abertura do primeiro arquivo passado nos argumentos, aberto por "rb" (leitura binária)
	if(!entrada) // se entrada for false entra no if de erro
	{
		fprintf(stderr,"Arquivo %s não pode ser aberto para leitura\n", argv[1]);
		return 1;
	}

	saida = fopen(argv[2],"wb"); // ponteiro saida recebe o segundo argumento passado e abre como "wb" (escrita binária) 
	if(!saida) // se saida for false entra no if de erro
	{
		fclose(entrada);
		fprintf(stderr,"Arquivo %s não pode ser aberto para escrita\n", argv[2]);
		return 1;
	}

	c = fgetc(entrada); //  c recebe cada caractere do ponteiro que esta apontando para o arquivo de entrada
	while(c != EOF) // enquanto c for fdiferente do EOF(final do arquivo) fica em loop
	{
		fputc(c, saida); // bota o caractere que pegou no arquivo de saida
		c = fgetc(entrada); // repete
	}

	fclose(entrada); // fecha o arquivo de entrada
	fclose(saida); // fecha o arquivo de saida
	return 0;
}