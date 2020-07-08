#include "conta.h"

int Conta::num_contas=0;

Conta::Conta(int n,double s,string t)
{
	this->numero=n;
	this->saldo=s;
	this->titular=t;
	this->num_contas++;
}
	
void Conta::transfere(double valor, Conta &conta)
{
	this->saldo-=valor;
	conta.deposita(valor);
};
	
void Conta::saca(double valor)
{
	this->saldo-=valor;
};
	
void Conta::deposita(double valor)
{
	this->saldo+=valor;
};
