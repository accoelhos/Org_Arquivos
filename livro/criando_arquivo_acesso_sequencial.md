## Criando um arquivo de acesso sequencial
## Escrevendo dados em arquivo sequencial
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
- Cada arquivo deve ter um nome e um ponteiro diferente retornado por **f open**
- 2º argumento do f open - Modos de acesso:
  - W: escrita no arquivo  (write)
  - R: leitura do arquivo (read)
  - A: adicionar registros ao final de um arquivo existende (arquive anexação)
  - Modos de atualização:
    - R+: ABRE o arquivo pra leitura e escrita/gravação
    - W+: CRIA o arquivo pra leitura e escrita/gravaçao
    - A+: ABRE o arquivo pra leitura e escrita/gravação no FINAL do arquivo. Se não existir, o arquivo é criado.

## Lendo dados em arquivo sequencial
- Mesmo exemplo de conta e mesmos comando, mas agora para LER dados:
```C
#include <stdio.h>

main(){
  int conta;
  char nome[30];
  float saldo;
  FILE *cfPtr; /* ponteiro do arquivo */

  if((cfPtr fopen("clientes.dat", r) == NULL) /* abrindo o arquivo para LEITURA com r e ve se foi aberto corretamente*/
    printf("Arquivo nao pode ser aberto");

  else{
   
   printf("%-10s%-13s%s\n", "Conta", "Nome", "Saldo");
   fscanf(cfPtr, "%d%s%f", &conta, nome, &saldo); /* lê um REGISTRO do arquivo. funciona igual o scanf mas recebendo um argumento do ponteiro do arquivo a ser lido. Cada vez que fscanf for executado, os valores se tornam outros (outras contas, nomes, saldos) até o final do arquivo*/
  
   while (!feof(cfPtr)) {
      printf("%-10d%-13s%7.2f\n", conta, nome, saldo);
      fscanf(cfPtr, "%d%s%f", &conta, nome, &saldo);
   }
   fclose(cfPtr);
   }
 return 0;
 }
```
## Recuperar dados sequencialmente 
- Leitura do arquivo sequencialmente até chegar no dado buscado
- Instrução: **rewind(cfPtr);
  - 

