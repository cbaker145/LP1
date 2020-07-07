#ifndef CONTA
#define CONTA

#include "agencia.h"
#include "cliente.h"
#include <string>

using namespace std;

class Conta{
	public:
		int numero;
		double saldo;
		string titular;
		Cliente cliente;
		Agencia agencia;
	
	
		Conta(int n,double s,string t);
		void transfere(double valor, Conta &conta);
		void saca(double valor);
		void deposita(double valor);
};

#endif
