#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Endereco Endereco;
typedef struct _Indice Indice;

struct _Endereco {
    char logradouro[72];
	char bairro[72];
	char cidade[72];
	char uf[72];
	char sigla[2];
	char cep[8];
	char lixo[2];
};

struct _Indice {
    char cep[8];
    int indice;
};

int compara(const void *e1, const void *e2) {
    return strncmp(((Indice*)e1)->cep, ((Indice*)e2)->cep, 8);
}

int main() {
    FILE *arquivo_cep, *arquivo_indice;
    Endereco endereco;
    Indice *indices;
    long posicao, qtd, i;

    arquivo_cep = fopen("cep.dat", "rb");
    if (arquivo_cep == NULL) {
        perror("Erro ao abrir cep.dat");
        return 1;
    }

    fseek(arquivo_cep, 0, SEEK_END);
    posicao = ftell(arquivo_cep);
    qtd = posicao / sizeof(Endereco);
    indices = (Indice*)malloc(qtd * sizeof(Indice));
    if (indices == NULL) {
        printf("Erro: memória não alocada\n");
        fclose(arquivo_cep);
        return -1;
    }

    rewind(arquivo_cep);
    for (i = 0; i < qtd; i++) {
        fread(&endereco, sizeof(Endereco), 1, arquivo_cep);
        strncpy(indices[i].cep, endereco.cep, 8);
        indices[i].indice = i;
    }
    fclose(arquivo_cep);

    qsort(indices, qtd, sizeof(Indice), compara);

    arquivo_indice = fopen("indice.dat", "wb");
    if (arquivo_indice == NULL) {
        perror("Erro ao criar indice.dat");
        free(indices);
        return 1;
    }

    fwrite(indices, sizeof(Indice), qtd, arquivo_indice);
    fclose(arquivo_indice);
    free(indices);

    printf("Arquivo cep.dat ordenado e escrito em indice.dat\n");
    return 0;
}
