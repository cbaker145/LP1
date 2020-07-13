#ifndef ESTABELECIMENTO
#define ESTABELECIMENTO

#include <string>
#include <vector>
#include "Produto.h"

//A classe carrega os produtos no estoque.csv
//A classe gera um arquivo de saida caixa.csv, contendo os produtos vendidoss e o dinheiro ganho nas vendas
//caixa.csv contem o codigo do produto, preço, quantidade vendida de cada e o total ganho

class Estabelecimento
{
	public:
		//vector com todos os produtos presentes no arquivo
		//int cod, string nome, string nome_unidade, int quant, float preco
		std::vector<Produto*> produtos;
		std::string filename;
		std::vector<Produto*> caixa;
		
		//inicializa abrindo o arquivo e carregando os produtos
		Estabelecimento(const std::string& name);
		~Estabelecimento();
		
		//carrega caixa se ainda nao tiver sido carregado, e mostra seus conteudos na tela
		void mostrar_caixa();
		
		//deve listar os produtos
		void listar();
		
		//escreve no arquivo estoque as informacoes atualizadas pos-venda
		void atualizar_estoque();
		
		//escreve no arquivo caixa o conteudo da sacola ou do proprio arquivo atualizado com a sacola
		void preencher_caixa(std::vector<Produto*> src);
		
		//retorna tudo que foi vendido e o total ganho
		void registrar_caixa(std::vector<Produto*> sacola);
		
		
};

#endif
