## Criando um arquivo de acesso sequencial
- **exemplo**: sistema de contas
- P/ cada cliente, o pgm obtém um número de conta, nome e saldo do cliente, constituindo um **registro** para ele. O **campo chave** é o numero da conta, mantendo e ordenando os arquivos.
```C
#include <stdio.h>
main(){
  int conta;
  char nome[30];
  float saldo;
  FILE *cfPtr; /* ponteiro do arquivo clientes.dat */

  if ((cfPtr = fopen("clientes.dat", "w") == NULL) /* indica o arquivo a ser usado, estabelecendo uma comunicação com o arquivo. Ao ponteiro cfPtr é atribuido um ponteiro para FILE aberto com o fopen, que exige 2 argumentos: o nome do arquivo e o modo de abertura. W indica aberto para escrita (writing). fopen cria um arquivo se nao existir, mas se um existente for aberto, apaga o conteudo sem aviso. IF determina se cfPtr é NULL (não aberto). se for NULL, msg de erro e encerra o programa. */
    printf("Arquivo nao pode ser aberto\n");

  else{
    printf("digite a conta, nome e saldo: ");
    printf("digite EOF para encerrar a entrada: ");
    printf("?");
    scanf("%d%s%f", &conta, nome, &saldo);

    while (!feof(stdin)){ /* feof serve para ver se o indicador de FIM DE DIGITAÇAO foi digitado para o arquivo referido por stdin. Argumento de feof é o ponteiro para o arquivo em que o indicador do fim será testado (stdin) */
      fprintf(cfPtr, "%d %s %.2f\n",conta,nome,saldo); /* grava dados no arquivo, igual o printf mas recebe o ponteiro do arquivo como argumento */
      printf("?");
      scanf("%d%s%f", &conta, nome, &saldo);
      }
    fclose(cfPtr); /* fecha o arquivo, recebendo seu ponteiro */
  }
  return 0;
}
```
