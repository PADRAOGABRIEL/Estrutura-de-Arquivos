#include <stdio.h>
#include <string.h>

typedef struct _Endereco Endereco; // define como a estrutura vai ser chamada


struct _Endereco // define a estrutura do Endereço e o espaço que cada informacao ocupa 
{
	char logradouro[72]; 
	char bairro[72];
	char cidade[72];
	char uf[72];
	char sigla[2];
	char cep[8];
	char lixo[2]; // Ao Espaço no final da linha + quebra de linha
};

int main(int argc, char**argv)
{
	FILE *f; // ponteiro de arquivo
	Endereco e; // cria uma estrutura de endereço
	int qt; // cria uma variavel qt
	int c; // cria uma variavel c

	if(argc != 2) // se a contagem de argumentos for diferente de 2 entra no if de erro
	{
		fprintf(stderr, "USO: %s [CEP]", argv[0]);
		return 1;
	}

	c = 0; // define c para 0
	printf("Tamanho da Estrutura: %ld\n\n", sizeof(Endereco)); // Imprime o tamanho de "Endereco"
	f = fopen("cep.dat","r"); // f recebe cep.dat aberto em leitura
	qt = fread(&e,sizeof(Endereco),1,f); // qt recebe a leitura do Endereco e, irá ler o tamanho do Endereco, 1 vez do ponteiro de arquivo f
	while(qt > 0) // enquanto qt for diferente de 0
	{
		c++; // Incrementa o valor de c para armazenar quantas estruturas foram lidas

		// ****para o strncmp****
		// argv[1] < e.cep  => strcmp(argv[1],e.cep) < 0 -  Se o cep passado no argumento for menor do que o cep da estrura de Endereco
		// argv[1] > e.cep  => strcmp(argv[1],e.cep) > 0 -  Se o cep passado no argumento for maior do que o cep da estrura de Endereco
		// argv[1] == e.cep  => strcmp(argv[1],e.cep) == 0 -  Se o cep passado no argumento for igual ao cep da estrura de Endereco


		if(strncmp(argv[1],e.cep,8)==0)// comparando parametro 1 com parametro 2 com tamanho de 8 e verificando se o retorno é = 0
		{
			printf("%.72s\n%.72s\n%.72s\n%.72s\n%.2s\n%.8s\n",e.logradouro,e.bairro,e.cidade,e.uf,e.sigla,e.cep); // Imprime todos as informações contidas em Endereco
			break; // sai do if
		}
		qt = fread(&e,sizeof(Endereco),1,f); // repete leitura de 1 Endereco até achar o Endereco correspondente	
	}
	printf("Total Lido: %d\n", c); // Imprime o total lido
	fclose(f); // fecha o ponteiro do arquivo "f"
}
