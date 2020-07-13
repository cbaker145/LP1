#include "cliente.h"
#include<iostream>
#include<fstream>

int Cliente::num_cliente=1;

Cliente::Cliente(float &sald) : saldo(sald), total_gasto(0){
	std::ifstream infile;
	while(true){
		std::string current=std::to_string(num_cliente);
		infile.open("cliente_"+current+".txt");
		if(!infile.is_open()){
			infile.close();
			break;
		}else{
			num_cliente++;
			infile.close();
		}
	}
	//std::cout<<"Cliente "<<num_cliente<<std::endl;
}

Cliente::~Cliente(){
	registro();
}

void Cliente::compra(int produto,int quantidade, std::vector<Produto*> produtos){
	bool found=false;
	if(quantidade<=0){
		std::cout<<"Pedido cancelado."<<std::endl;
	}
	for(size_t i=0;i<produtos.size();i++){
		if(produtos[i]->cod==produto){
			found=true;
			if(produtos[i]->preco*quantidade+total_gasto>saldo||quantidade>produtos[i]->quant){
				std::cout<<"O gasto excede seu saldo ou a quantidade requerida nao se encontra em estoque!"<<std::endl;
				return;
			}
			for(size_t j=0;j<sacola.size();j++){
				if(sacola[j]->cod==produto){
					sacola[j]->quant+=quantidade;
					total_gasto+=sacola[j]->preco*quantidade;
					saldo-=sacola[j]->preco*quantidade;
					produtos[i]->quant=produtos[i]->quant-quantidade;
					std::cout<<"Itens adicionados na sacola com sucesso! Custo dos itens: R$"<<total_gasto<<std::endl;
					return;
				}
			}
			//int cod, string nome, string nome_unidade, int quant, float preco
			Produto* temp = new Produto;
			temp->cod=produtos[i]->cod;
			temp->nome=produtos[i]->nome;
			temp->nome_unidade=produtos[i]->nome_unidade;
			temp->quant=produtos[i]->quant;
			temp->preco=produtos[i]->preco;
			sacola.push_back(temp);
			produtos[i]->quant=produtos[i]->quant-quantidade;
			break;
		}
	}
	if(!found){
		std::cout<<"Codigo Invalido!"<<std::endl;
		return;
	}
	for(size_t i=0;i<sacola.size();i++){
		if(sacola[i]->cod==produto){
			sacola[i]->quant=quantidade;
		}
		total_gasto+=sacola[i]->preco*sacola[i]->quant;
		saldo-=sacola[i]->preco*sacola[i]->quant;
	}
	std::cout<<"Itens adicionados na sacola com sucesso! Custo dos itens: R$"<<total_gasto<<std::endl;
}

void Cliente::registro(){
	if(sacola.size()<1) return;
	std::string current_client=std::to_string(num_cliente);
	std::ofstream outfile("cliente_"+current_client+".txt");
	for(size_t i=0;i<sacola.size();i++){
		outfile<<sacola[i]->nome<<". "<<sacola[i]->quant<<" "<<sacola[i]->nome_unidade<<"s. UNI: R$ "<<sacola[i]->preco<<". Codigo: "<<sacola[i]->cod<<std::endl;
	}
	outfile<<"TOTAL: "<<total_gasto<<std::endl;
	outfile.close();
}

void Cliente::verSacola(){
	if(sacola.size()<1){
		std::cout<<"Sacola Vazia"<<std::endl;
	}else{
		for(size_t i=0;i<sacola.size();i++){
			std::cout<<sacola[i]->nome<<". "<<sacola[i]->quant<<" "<<sacola[i]->nome_unidade<<"s na sacola. UNI: R$ "<<sacola[i]->preco<<". Codigo: "<<sacola[i]->cod<<std::endl;
		}
	}
	std::cout<<"Total: "<<total_gasto<<std::endl;
}
