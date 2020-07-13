#ifndef CLIENTE
#define CLIENTE

#include "produto.h"
#include <string>
#include <vector>

class Cliente
{
	public:
		static int num_cliente;
		//quanto de dinheiro o cliente tem
		float saldo;
		float total_gasto;
		//contem todas as compras do cliente
		std::vector<Produto*> sacola;
		
		
		//informar saldo internamente no construtor, pra facilitar criar varios clientes
		Cliente(float &sald);
		~Cliente();
		//DEFINIR TIPOS DOS ATRIBUTOS
		void compra(int produto, int quantidade, std::vector<Produto*> produtos);
		//mostra o conteudo da sacola
		void verSacola();
		//escreve o conteudo da sacola num cliente_<cliente_id>.txt
		void registro();
};

#endif
