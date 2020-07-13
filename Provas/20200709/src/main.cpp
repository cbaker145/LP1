#include<iostream>
#include "cliente.h"
#include "estabelecimento.h"

int main(int argc, char* argv[]){
	std::cout<<"Bem-vindo ao Supermercado!"<<std::endl;
	Estabelecimento* estab = new Estabelecimento("estoque.csv");
	float sald;
	std::cout<<"Informe seu saldo para iniciar as compras: ";
	std::cin>>sald;
	Cliente* cli = new Cliente(sald);
	int action=-1;
	while(action!=0){
		std::cout<<"\nSelecione uma opcao:\n\n1) Ver sacola\n2) Adicionar produto na sacola\n3) Ver estoque\n4) Ver caixa\n0) Concluir compras\nSALDO: "<<cli->saldo<<"\n\n";
		std::cin>>action;
		switch(action){
			case 1:
				cli->verSacola();
				break;
			case 2:
				int cod, quant;
				std::cout<<"Informe o codigo do produto que deseja comprar, depois a quantidade: ";
				std::cin>>cod>>quant;
				cli->compra(cod,quant,estab->produtos);
				break;
			case 3:
				estab->listar();
				break;
			case 4:
				estab->mostrar_caixa();
				break;
			case 0:
				char choice;
				std::cout<<"Deseja iniciar um novo cliente? [y/n] ";
				std::cin>>choice;
				if(choice=='n'){
					estab->registrar_caixa(cli->sacola);
					delete cli;
					delete estab;
					return 0;
				}else{
					estab->registrar_caixa(cli->sacola);
					delete cli;
					std::cout<<"Informe seu saldo para iniciar as compras: ";
					std::cin>>sald;
					cli = new Cliente(sald);
					action = -1;
				}
				break;
		}
	}
	
	return 0;
}
