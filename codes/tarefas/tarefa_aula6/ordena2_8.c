#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Endereco Endereco;

struct _Endereco
{
	char logradouro[72];
	char bairro[72];
	char cidade[72];
	char uf[72];
	char sigla[2];
	char cep[8];
	char lixo[2];
};

int compara(const void *e1, const void *e2)
{
	return strncmp(((Endereco*)e1)->cep,((Endereco*)e2)->cep,8);
}

int main(int argc, char**argv)
{
	FILE *f, *saida;
	Endereco *e;
	long posicao, qtd, metade, regBloco, sobra, buffer;


	f = fopen("cep2.dat","rb");
    fseek(f, 0, SEEK_END);
	posicao = ftell(f);
	qtd = posicao/sizeof(Endereco);
	regBloco = qtd/8;
    sobra = regBloco%8;
    buffer= (Endereco*) malloc((regBloco+1)*sizeof(Endereco));
	rewind(f);
	for( int i=0; i<8;i++){
        f = fopen(cep2(i),"wb");
        fread()
    }



	qsort(e,metade,sizeof(Endereco),compara);
	printf("Ordenado = OK\n");
	saida = fopen("cep_a.dat","wb");
	fwrite(e,sizeof(Endereco),metade,saida);
	fclose(saida);
	printf("Escrito = OK\n");
	free(e);

	e = (Endereco*) malloc((qtd-metade)*sizeof(Endereco));
	if(fread(e,sizeof(Endereco),qtd-metade,f) == qtd-metade)
	{
		printf("Lido = OK\n");
	}
	qsort(e,qtd-metade,sizeof(Endereco),compara);
	printf("Ordenado = OK\n");
	saida = fopen("cep_b.dat","wb");
	fwrite(e,sizeof(Endereco),qtd-metade,saida);
	fclose(saida);
	printf("Escrito = OK\n");
	free(e);

	fclose(f);
}

