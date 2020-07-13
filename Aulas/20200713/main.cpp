#include<iostream>
#include<string>

#include "empresa.h"

int main(int argc,char* argv[]){
	Empresa *emp = new Empresa("nome","cnpj");
	emp->add_funcionario("jao",emp->get_nome(),100,"hoje","nnsei");
	emp->add_funcionario("matheus",emp->get_nome(),100,"hoje","nnsei");
	emp->add_funcionario("ana",emp->get_nome(),100,"hoje","nnsabemos");
	emp->add_funcionario("calista",emp->get_nome(),100,"hoje","nnsei");
	emp->add_funcionario("miro",emp->get_nome(),100,"hoje","nnsei");
	emp->add_funcionario("samuel",emp->get_nome(),100,"hoje","nnsei");
	emp->alt_sal_por_dep("nnsei",10);
	return 0;
}
