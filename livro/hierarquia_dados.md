## Hierarquia de dados
- Os itens de dados processados pelo computador formam uma **hierarquia de dados**
- esses dados da hierarquia se tornam maiores e mais complexos na estrutura de acordo com a evolução de **bits** para **caracteres**
### Registro
- É uma *struct* em C, composto de vários campos, como nome, endereço, telefone, etc.
- é um grupo de campos **relacionados entre si**, como se os dados pertencessem à mesma pessoa.
- Dessa forma, um **ARQUIVO** é um grupo de **registros relacionados**
- Para **facilitar** que registros de um arquivo sejam recuperados, um campo de cada registro é escolhido como *chave dos registros*, identificando um registro sendo pertencente a determinada entidade
## Organização
### **arquivo sequencial**
- os regitros são armazenados em ordem de acordo com a *chave*, geralmente em ordem crescente (menor pro maior número, por exemplo)
### Banco de dados
- um grupo de arquivos relacionados entre si pode ser considerado um *banco de dados*, gerenciados por *SGBD*
  
