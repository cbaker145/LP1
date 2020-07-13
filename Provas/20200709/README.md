# Projeto Supermercado
Projeto de armazenamento e venda de produtos, com registros de compras feitas por cliente e total de itens vendidos.
## Compilação
Compila-se com `make`. Para remover os arquivos.o e o executável, usa-se `make clean`.
## Uso
Primeiramente, o progrma pede que o usuário informe seu saldo para instanciar o objeto `Cliente` e dar início às operações. O programa abre então um menu interativo, no qual estão disponíveis 5 opções. **Todas as opções do menu são selecionáveis simplesmente digitando seus respectivos números**. Algumas requerem mais informações após acionadas.
- **1: Ver sacola.** Exibe os produtos que o usuário pretende comprar. Caso nenhum produto tenha sido adicionado, é mostrada uma mensagem indicando que a sacola está vazia. A sacola é preenchida através do comando 2.
- **2: Adicionar produto na sacola.** Após seleção, informar `<codigo> <quantidade>` (ambos inteiros positivos), sendo estes, respectivamente, o codigo do produto a ser comprado e a quantidade solicitada. O programa confere se suas compras excedem o saldo e os produtos disponíveis no estoque em cada chamada, e exibe uma mensagem de erro se algum destes requisitos for cumprido.
- **3: Ver estoque.** Mostra todos os produtos no estoque, com seus códigos, quantidades e preços unitários.
- **4: Ver caixa.** Exibe na tela o registro de todos os produtos vendidos a todos os clientes, acessando o arquivo caixa. Se o arquivo não existir, uma mensagem de erro é mostrada.
- **0: Concluir compras.** Cria um arquivo com as informações do cliente e atualiza os arquivos de estoque e caixa de acordo com as compras realizadas (caso o arquivo de caixa não exista, o programa cria um `caixa.csv` com o conteúdo da sacola do usuário atual. É perguntado ao usuário se deseja entrar como um novo cliente, dando as opções `<y/n>`. Caso o usuário deseje entrar com um cliente novo, o programa instancia um novo objeto `Cliente` e pede que o saldo do novo cliente seja informado, e então contina normalmente. Caso o usuário não deseje entrar como um cliente novo, o programa termina.

## Formatação do arquivo `estoque.csv`
O arquivo foi mantido como enviado, sem alterações estruturais ou sintáticas.