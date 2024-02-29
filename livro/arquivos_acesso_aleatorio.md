## Arquivos de acesso aleatório
- Registros em um arquivo criado com fprintf não possuem necessariamente o mesmo tamanho.
- Em contraste, registros em um arquivo de acesso aleatório geralmente têm o mesmo tamanho.
- Arquivos de acesso aleatório são adequados para sistemas que requerem **acesso rápido** a dados específicos.
- A implementação mais simples de arquivos de acesso aleatório utiliza **registros de comprimento fixo**.
- Todos os registros em um arquivo de acesso aleatório têm o **mesmo comprimento**, facilitando o cálculo da localização de um registro em relação ao início do arquivo com base em sua chave.
- Isso permite o acesso imediato a registros específicos, mesmo em arquivos grandes.
- Um arquivo de acesso aleatório é comparado a um trem de carga, onde cada "vagão" tem o mesmo comprimento.
- Os dados podem ser inseridos, atualizados ou excluídos em um arquivo de acesso aleatório **sem afetar** outros dados no arquivo.

## Criando arquivos de acesso aleatório
- Função **fwrite**: Alternativa ao fprintf para números int
  - Transfere para um arquivo um numero especifico de bytes.
  - Os dados são gravados iniciando no local do arquivo indicado pelo ponteiro de **posição** do arquivo
  ```C
  fwrite(Snumero, sizeof(int), 1, fPtr);
  ```
  - Sempre grava 4 bytes da variavel *numero* no arquivo representado por *fPtr*

- Função **fread**: Alternativa ao fscanf
  - Transfere uma qtd de bytes de um local da memoria definido por um ponteiro de posiçao do arquivo para outra área da memoria, iniciando por um endereço indicado
- Ambas essas funçoes são capazes de trabalhar com **arrays** de dados
- O **terceiro argumento** de ambas é o numero de elementos do array a serem trabalhados (lidos ou gravados)
- Normalmente, é gravada uma **struct** de cada vez

### Criando sequencialmente um arquivo de acesso aleatório
- Abrir o arquivo de acesso aleatorio
- Definir um formato de registro com struct
- Gravar dados no disco e fechar o arquivo
  - Inicializa 100 registros do arquivo com **structs vazias** com **fwrite** para criar espaço no disco e pra determinar se um registro contém ou não dados



