#ifndef EMPRESA
#define EMPRESA

#include<vector>
#include<string>
#include "funcionario.h"

class Empresa{
	private:
		std::string nome;
		std::string cnpj;
		std::vector<Funcionario*> funcionarios;
		
	public:
		Empresa(std::string _cnpj,std::string _nome);
		~Empresa();
		std::string get_cnpj();
		std::string get_nome();
		void set_cnpj(std::string _nome);
		void set_nome(std::string _cnpj);
		void add_funcionario();
		void add_funcionario(std::string _nome, std::string _empresa, double _salario, std::string _data_admissao, std::string _departamento);
		void alt_sal_por_dep(std::string departamento,double value);
};


#endif
