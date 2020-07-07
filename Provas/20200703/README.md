# Projeto Diary
O projeto objetiva criar um registro de mensagens organizadas por timestamp.
## Diary.config
É o documento com as definições a serem usadas na execução do programa. Nele, são informados o caminho para a pasta e a configuração padrão de exibição de mensagens no console.
## Usos
Atualmente, existem 4 formas de utilização:
### `./exerc list` ou `./exerc list <format>`
Exibe no console todas as mensagens na DB organizadas por timestamp. O usuário pode definir um formato de exibição através do `diary.config` ou como argumento na chamada, entre aspas simples.
### `./exerc add` ou `./exerc add '<msg_content>'`
Adiciona uma mensagem à DB. É necessário informar o conteúdo da mensagem. Caso <msg_content> esteja vazio, seu valor será então informado pelo usuário internamente.
### `./exerc search` ou `./exerc search '<query>'`
Procura por todas as mensagens que contenham o trecho especificado em seu conteudo. É necessário informar o trecho a ser encontrado, assim como em "add"
### `./exerc interactive`
Abre um menu interativo que permite ao usuário a utilização de todos os outros comandos de maneira contínua, utilizando números equivalentes às ações desejadas, sendo estes:

- 1: list
- 2: add
- 3: search
- 0: finalizar programa

Os parâmetros precisam ser informados nos os itens do menu da mesma forma que com os comandos de execução.