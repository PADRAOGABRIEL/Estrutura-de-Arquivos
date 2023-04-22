#include <stdio.h>

#define TAMANHO 4096 // Define que o TAMANHO será de 4096bytes

int main(int argc, char** argv)
{
	FILE *entrada, *saida; // cria 2 ponteiros para arquivos, 1 para entrada e outra para saída 
	char buffer[TAMANHO]; // buffer é um array de char que irá ter o tamanho de 4096 bytes
	int qtd; // cria uma varável "qtd" inteira

	if(argc != 3)// se os argumentos passados forem diferentes de 3 entra no if
	{
		fprintf(stderr,"Erro na chamada do comando.\n");
		fprintf(stderr,"Uso: %s [ARQUIVO ORIGEM] [ARQUIVO DESTINO].\n", argv[0]);
		return 1;
	}

	entrada = fopen(argv[1],"rb");// entrada recebe a abertura do primeiro arquivo passado nos argumentos, aberto por "rb" (leitura binária)
	if(!entrada)// se entrada for false entra no if de erro
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

	qtd = fread(buffer,1,TAMANHO,entrada); //qtd recebe a leitura do buffer de 1 em 1 posição
	while(qtd > 0) // enquanto qdt for maior que 0 o lopp continua
	{
		fwrite(buffer,1,qtd,saida); // escreve no arquivo de saida
		qtd = fread(buffer,1,TAMANHO,entrada); // repete qtd
	}

	fclose(entrada);// fecha
	fclose(saida); // fecha
	return 0;
}
