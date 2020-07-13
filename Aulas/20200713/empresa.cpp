#include "empresa.h"
#include<iostream>


Empresa::Empresa(std::string _nome, std::string _cnpj) : nome(_nome), cnpj(_cnpj)
{
}

Empresa::~Empresa()
{
	delete[] &funcionarios;
}

void Empresa::set_nome(std::string _nome)
{
	nome=_nome;
}
void Empresa::set_cnpj(std::string _cnpj)
{
	cnpj=_cnpj;
}
std::string Empresa::get_nome()
{
	return nome;
}
std::string Empresa::get_cnpj()
{
	return cnpj;
}

void Empresa::add_funcionario()
{
	std::string _nome;
	std::string _departamento;
	std::string _data_admissao;
	double _salario;
	std::string _empresa;
	std::cout<<"Informe o nome do funcionario: ";
	std::cin>>_nome;
	std::cout<<"Informe o departamento do funcionario: ";
	std::cin>>_departamento;
	std::cout<<"Informe a data de admissao do funcionario: ";
	std::cin>>_data_admissao;
	std::cout<<"Informe o salario do funcionario: ";
	std::cin>>_salario;
	add_funcionario(_nome,nome,_salario,_data_admissao,_departamento);
}

void Empresa::add_funcionario(std::string _nome, std::string _empresa, double _salario, std::string _data_admissao, std::string _departamento)
{
	Funcionario* temp= new Funcionario(_nome,nome,_salario,_data_admissao,_departamento);
	funcionarios.push_back(temp);
}

void Empresa::alt_sal_por_dep(std::string departamento,double value)
{
	value/=100;
	for(size_t i=0;i<funcionarios.size();i++){
		std::cout<<funcionarios[i]->get_nome()<<std::endl;
		std::cout<<funcionarios[i]->get_salario()<<std::endl;
		if(funcionarios[i]->get_departamento()==departamento){
			funcionarios[i]->set_salario(funcionarios[i]->get_salario()+value*funcionarios[i]->get_salario());
		}
		std::cout<<funcionarios[i]->get_nome()<<std::endl;
		std::cout<<funcionarios[i]->get_salario()<<std::endl;
	}
}
