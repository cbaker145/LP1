#ifndef PRODUTO
#define PRODUTO

#include <string>

struct Produto
{
	int cod;
	std::string nome;
	std::string nome_unidade;
	float preco;
	int quant;
	
	void set_from_string(std::string& base);
};

#endif
