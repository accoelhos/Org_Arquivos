## Arquivos e fluxos
- Cada arquivo é visto como um fluxo sequencial de bytes em **C**
- Cada arquivo termina com um *end-of-file marker*, que é mantido pelo sistema. Quando é **aberto** um **fluxo** é associado a ele
- TRÊS arquivos e seus fluxos também são abertos quando um programa é iniciado:
  - entrada padrão: permite que um programa leia dados de entrada
  - saída padrão: permite que um programa leia dados de saída
  - erro
### Abertura de arquivos
- retorna um **ponteiro** para uma estrutura **FILE** (de <stdio.h>) contendo infos usadas no processamento do arquivo
- **FILE** contém um **descritor** do arquivo -> um **array** do SO chamado **Tabela de arquivos abertos**
  - cada elemento desse array possui um **bloco de controle de arquivo** (file control block), usado pelo SO para **administrar** um arquivo em particular
- **ponteiros que manipulam os padroes**
  - E: *stdin*
  - S: *stdout*
  - Erro: *stderr*
### Funções para ler e gravar dados
- *fgtec*: lê um carac de arquivo
  - argumento: ponteiro FILE do arquivo a ser lido.
  - a chamada le um char de **stdin**
  - equivalente a *getchar()*
- *fputc*: escreve um carac em arquivo
  - argumento: um char a ser escrito em um arquivo e o ponteiro do arquivo a ser escrito
  - equivalente a *putchar()*
  - *f pute*('a', stdout) escreve o char 'a' em stdout
- *f gets*: ler uma linha de arquivo
- *f puts*: gravar uma linha em um arquivo
