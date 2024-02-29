## Aula 02 - 29/02

- **copia1.c**: argc qtd de argumentos passados; argv é quais argumentos foram passados
```C
#include <stdio.h>
//stdout, stdin, stderr

int main(int argc, char** argv){
	
	FILE *entrada, *saida; // ponteiros que indicam arquivo aberto
	int c;t

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
```
- o arquivo pode ser visto como abstraçao para os SOs modernos, sendo uma sequencia de bytes persistentes
- Só existe EOF após uma tentativa de leitura que NÃO deu certo.

- **copia2.c**
- Alguns simbolos não sao imprimiveis em um arquivo texto, de acordo com a tabela *ASCII* (primeira parte da tabela na wikipedia)

### Criando arquivo binario 
```C
#include <stdio.h>

struct Pessoa // definindo um especificaçao para um binario
	char nome[40];
	int idade;
	float altura;
};
typedef struct _Pessoa Pessoa;

int main()
	FILE *f = fopen ("saida.dat", "wb"); //se esse arquivo nao existir ele cria, se ja existir ele apaga tudo.
	Pessoa p;
	strcpy(p.nome, "Nome"); // pois para strings nao pode fazer p.nome = "nome"
	p.idade = 20;
	p.altura = 150;
	fwrite(&p, sizeof(Pessoa),1,f); //escreva os bytes do end p (tamanho é o size of pessoa, que diz quantos bytes ocupa na memoria), quantos são, no lugar pra onde f aponta
	fclose(f);
	
	return 0;
}
```
- é possivel zerar todo o arquivo com memset(p,0,1000*sizeof(Pessoa))
- quando é executado, o arquivo é criado. Abrindo com editor convencional, só da pra ler o nome.
- Para investigar um arquivo binario, é possivel utilizar um plugin de editor **hexadecimal**. 




