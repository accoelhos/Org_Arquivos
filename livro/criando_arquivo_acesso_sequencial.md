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
  if ((cfPtr = fopen("clientes.dat", "w") == NULL)
    printf("Arquivo nao pode ser aberto\n");
  else{
    printf("digite a conta, nome e saldo: ");
    printf("digite EOF para encerrar a entrada: ");
    printf("?");
    scanf("%d%s%f", &conta, nome, &saldo);
    while (!feof(stdin)){
      fprintf(cfPtr, "%d %s %.2f\n",conta,nome,saldo);
      printf("?");
      scanf("%d%s%f", &conta, nome, &saldo);
      }
    fclose(cfPtr);
  }
  return 0;
}
```
