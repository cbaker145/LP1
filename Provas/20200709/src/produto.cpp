#include "produto.h"
#include<sstream>
#include<iostream>
#include<ctype.h>

//int cod, string nome, string nome_unidade, int quant, float preco
void Produto::set_from_string(std::string& base){
	preco=0;
	std::stringstream stream(base);
	char discard;
	float base_preco;
	stream>>cod;
	stream>>discard>>discard;
	stream>>std::noskipws;
	while(discard!=','){
		nome.push_back(discard);
		stream>>discard;
	}
	stream>>std::skipws;
	stream>>discard;
	while(discard!=','){
		nome_unidade.push_back(discard);
		stream>>discard;
	}
	stream>>discard>>discard>>discard;
	stream>>preco;
	stream>>discard;
	stream>>base_preco;
	preco+=base_preco/100;
	stream>>discard>>discard;
	stream>>quant;
	
	//std::cout<<cod<<" "<<nome<<" "<<nome_unidade<<" "<<preco<<" "<<quant<<"\n";
	//std::cout<<discard<<std::endl;
	//std::cout<<nome<<"\n";
}
