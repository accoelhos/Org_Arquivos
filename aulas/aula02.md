## Aula 02 - 29/02

- copia1.c: argc qtd de argumentos passados; argv é quais argumentos foram passados
  
ˋˋˋC

#include <stdio.h>
//stdout, stdin, stderr

int main(int argc, char** argv){
	
	FILE *entrada, *saida; // ponteiros que indicam arquivo aberto
	int c;

	if(argc != 3) // verificando de 3 argumentos foram passados
	{
		fprintf(stderr,"Erro na chamada do comando.\n");
		fprintf(stderr,"Uso: %s [ARQUIVO ORIGEM] [ARQUIVO DESTINO].\n", argv[0]);
		return 1; // indicio de que o programa terminou com algum erro, se fosse 0 faz o serviço OK
	}

	entrada = fopen(argv[1],"rb"); // inicio do processo de abertura do arquivo, fopen instancia a estrutura e ABRE O ARQUIVO. RB significa q vai abrir para LEITURA em modo BINÁRIO, por isso o B (arquivo binário)
	if(!entrada) // verificando se consegue abrir ou nao o arquivo da entrada
	{
		fprintf(stderr,"Arquivo %s não pode ser aberto para leitura\n", argv[1]);
		return 1; // 1 pois deu errado
	}

	saida = fopen(argv[2],"wb"); // abrindo outro arquivo em modo ESCRITA BINARIA 
	if(!saida) // se deu errado a abertura
	{
		fclose(entrada); // fecha a entrada pois a saida deu errado, entao fecha os 2.
		fprintf(stderr,"Arquivo %s não pode ser aberto para escrita\n", argv[2]);
		return 1; 
	}

	c = fgetc(entrada); // fgetc pede o proximo byte do arquivo, que é uma sequencia de bytes PERSISTENTES atéchegar em EOF, lendo cada byte do arquivo
	while(c != EOF) // le enquanto nao tem EOF
	{
		fputc(c, saida); // enquanto le, ESCREVE o byte da saida 
		c = fgetc(entrada); // ler o proximo byte para contiuar o while
	}

	fclose(entrada);
	fclose(saida);
	return 0;
}
ˋˋˋ
- o arquivo pode ser visto como abstraçao para os SOs modernos, sendo uma sequencia de bytes persistentes
- Só existe EOF após uma tentativa de leitura que NÃO deu certo.

- copia2.c
ˋˋˋC
	#include <stdio.h>

	#define TAMANHO 8192 // alocando bytes de memoria para trabalhar em blocos

		int main(int argc, char** argv){
	
		FILE *entrada, *saida;
		char buffer[TAMANHO];
		int qtd;
	
		if(argc != 3)
		{
			fprintf(stderr,"Erro na chamada do comando.\n");
			fprintf(stderr,"Uso: %s [ARQUIVO ORIGEM] [ARQUIVO DESTINO].\n", argv[0]);
			return 1;
		}
	
		entrada = fopen(argv[1],"rb");
		if(!entrada)
		{
			fprintf(stderr,"Arquivo %s não pode ser aberto para leitura\n", argv[1]);
			return 1;
		}
	
		saida = fopen(argv[2],"wb");
		if(!saida)
		{
			fclose(entrada);
			fprintf(stderr,"Arquivo %s não pode ser aberto para escrita\n", argv[2]);
			return 1;
		}
	
		qtd = fread(buffer,1,TAMANHO,entrada);
		while(qtd > 0)
		{
			fwrite(buffer,1,qtd,saida);
			qtd = fread(buffer,1,TAMANHO,entrada);
		}
	
		fclose(entrada);
		fclose(saida);
		return 0;
	}
ˋˋˋ

