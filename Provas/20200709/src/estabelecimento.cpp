#include "estabelecimento.h"

#include<iostream>
#include<fstream>
#include<ctype.h>

Estabelecimento::Estabelecimento(const std::string& name) : filename(name)
{
	std::ifstream infile(filename);
	if(!infile.is_open()){
		std::cout<<"Arquivo de estoque inexistente ou inacessivel\n";
	}
	while(!infile.eof()){
		Produto* temp = new Produto;
		std::string current_line;
		getline(infile,current_line);
		//std::cout<<current_line<<std::endl;
		if(current_line.size()>1&&!isalpha(current_line[0])){
			//std::cout<<"Valid line"<<std::endl;
			temp->set_from_string(current_line);
			produtos.push_back(temp);
			//std::cout<<temp.cod<<" "<<temp.nome<<" "<<temp.nome_unidade<<" "<<temp.preco<<" "<<temp.quant<<"\n";
		}
	}
	infile.close();
};

Estabelecimento::~Estabelecimento()
{
	atualizar_estoque();
};


void Estabelecimento::preencher_caixa(std::vector<Produto*> src){
	std::ofstream outfile("caixa.csv");
	float cent_fixer;
	outfile<<"COD,PRODUTO,UNIDADE DE MEDIDA,PREÇO,QUANTIDADE,TOTAL"<<std::endl;
	for(size_t i=0;i<src.size();i++){
		cent_fixer=(src[i]->preco-(int)src[i]->preco);
		cent_fixer*=100;
		cent_fixer+=0.1;
		if((int)cent_fixer==0){
			outfile<<src[i]->cod<<","<<src[i]->nome<<","<<src[i]->nome_unidade<<","<<'"'<<"R$ "<<(int)src[i]->preco<<",00"<<'"'<<","<<src[i]->quant<<","<<src[i]->quant*src[i]->preco<<std::endl;
		}else{
			outfile<<src[i]->cod<<","<<src[i]->nome<<","<<src[i]->nome_unidade<<","<<'"'<<"R$ "<<(int)src[i]->preco<<","<<(int)cent_fixer<<'"'<<","<<src[i]->quant<<","<<src[i]->quant*src[i]->preco<<std::endl;
		}
	}
	outfile.close();
}

void Estabelecimento::registrar_caixa(std::vector<Produto*>sacola){
	std::ifstream infile("caixa.csv");
	if(!infile.is_open()){
		infile.close();
		std::ofstream outfile("caixa.csv");
		if(!outfile.is_open()){
			std::cout<<"Arquivo de caixa inacessivel"<<std::endl;
			return;
		}
		outfile.close();
		preencher_caixa(sacola);
	}
	if(!infile.is_open()){
		infile.open("caixa.csv");
	}
	if(caixa.size()<1){
		while(!infile.eof()){
			Produto* temp = new Produto;
			std::string current_line;
			getline(infile,current_line);
			//std::cout<<current_line<<std::endl;
			if(current_line.size()>1&&!isalpha(current_line[0])){
				//std::cout<<"Valid line"<<std::endl;
				temp->set_from_string(current_line);
				caixa.push_back(temp);
				//std::cout<<temp.cod<<" "<<temp.nome<<" "<<temp.nome_unidade<<" "<<temp.preco<<" "<<temp.quant<<"\n";
			}
		}
	}
	for(size_t i=0;i<sacola.size();i++){
		bool found=false;
		for(size_t j=0;j<caixa.size();j++){
			if(sacola[i]->cod==caixa[j]->cod){
				caixa[j]->quant+=sacola[i]->quant;
				found=true;
				break;
			}
		}
		if(!found){
			Produto* temp = new Produto;
			temp->cod=sacola[i]->cod;
			temp->nome=sacola[i]->nome;
			temp->nome_unidade=sacola[i]->nome_unidade;
			temp->quant=sacola[i]->quant;
			temp->preco=sacola[i]->preco;
			caixa.push_back(temp);
		}
	}
	preencher_caixa(caixa);
	infile.close();
}

void Estabelecimento::atualizar_estoque(){
	float cent_fixer;
	std::ofstream outfile(filename);
	outfile<<"COD,PRODUTO,UNIDADE DE MEDIDA,PREÇO,QUANTIDADE"<<std::endl;
	for(size_t i=0;i<produtos.size();i++){
		cent_fixer=(produtos[i]->preco-(int)produtos[i]->preco);
		cent_fixer*=100;
		cent_fixer+=0.1;
		if((int)cent_fixer==0){
			outfile<<produtos[i]->cod<<","<<produtos[i]->nome<<","<<produtos[i]->nome_unidade<<","<<'"'<<"R$ "<<(int)produtos[i]->preco<<",00"<<'"'<<","<<produtos[i]->quant<<std::endl;
		}else{
			outfile<<produtos[i]->cod<<","<<produtos[i]->nome<<","<<produtos[i]->nome_unidade<<","<<'"'<<"R$ "<<(int)produtos[i]->preco<<","<<(int)cent_fixer<<'"'<<","<<produtos[i]->quant<<std::endl;
		}
	}
	outfile.close();
}
void Estabelecimento::listar(){
	for(size_t i=0;i<produtos.size();i++){
		std::cout<<produtos[i]->nome<<". "<<produtos[i]->quant<<" "<<produtos[i]->nome_unidade<<"s em estoque. UNI: R$ "<<produtos[i]->preco<<". Codigo: "<<produtos[i]->cod<<std::endl;
	}
}

void Estabelecimento::mostrar_caixa(){
	if(caixa.size()<1){
		std::ifstream infile("caixa.csv");
		if(!infile.is_open()){
			std::cout<<"Arquivo de caixa inexistente ou inacessivel\n";
			infile.close();
			return;
		}
		while(!infile.eof()){
			Produto* temp = new Produto;
			std::string current_line;
			getline(infile,current_line);
			//std::cout<<current_line<<std::endl;
			if(current_line.size()>1&&!isalpha(current_line[0])){
				//std::cout<<"Valid line"<<std::endl;
				temp->set_from_string(current_line);
				caixa.push_back(temp);
				//std::cout<<temp.cod<<" "<<temp.nome<<" "<<temp.nome_unidade<<" "<<temp.preco<<" "<<temp.quant<<"\n";
			}
		}
		infile.close();
	}
	for(size_t i=0;i<caixa.size();i++){
		std::cout<<caixa[i]->nome<<". "<<caixa[i]->quant<<" "<<caixa[i]->nome_unidade<<"s vendidos. UNI: R$ "<<caixa[i]->preco<<". Codigo: "<<caixa[i]->cod<<". Total vendido: R$ "<<caixa[i]->preco*caixa[i]->quant<<std::endl;
	}
}
