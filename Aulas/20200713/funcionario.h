#ifndef FUNCIONARIO
#define FUNCIONARIO

#include<string>

class Funcionario{
	private:
		std::string nome;
		std::string departamento;
		std::string data_admissao;
		double salario;
		std::string empresa;
		
	public:
		Funcionario(std::string _nome, std::string _empresa, double _salario, std::string _data_admissao, std::string _departamento);
		~Funcionario();
		void set_nome(std::string _nome);
		void set_empresa(std::string _empresa);
		void set_salario(double _salario);
		void set_data_admissao(std::string _data_admissao);
		void set_departamento(std::string _departamento);
		std::string get_nome();
		std::string get_data_admissao();
		std::string get_empresa();
		std::string get_departamento();
		double get_salario();
};

#endif
