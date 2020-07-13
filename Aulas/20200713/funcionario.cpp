#include "funcionario.h"

Funcionario::Funcionario(std::string _nome, std::string _empresa, double _salario, std::string _data_admissao,std::string _departamento) : 
nome(_nome),
empresa(_empresa),
departamento(_departamento),
data_admissao(_data_admissao),
salario(_salario)
{
}
Funcionario::~Funcionario()
{
}

void Funcionario::set_nome(std::string _nome)
{
	nome=_nome;
}
void Funcionario::set_empresa(std::string _empresa)
{
	empresa=_empresa;
}
void Funcionario::set_departamento(std::string _departamento)
{
	departamento=_departamento;
}
void Funcionario::set_data_admissao(std::string _data_admissao)
{
	data_admissao=_data_admissao;
}
void Funcionario::set_salario(double _salario)
{
	salario=_salario;
}

std::string Funcionario::get_nome()
{
	return nome;
}
std::string Funcionario::get_empresa()
{
	return empresa;
}
std::string Funcionario::get_departamento()
{
	return departamento;
}
std::string Funcionario::get_data_admissao()
{
	return data_admissao;
}
double Funcionario::get_salario()
{
	return salario;
}
