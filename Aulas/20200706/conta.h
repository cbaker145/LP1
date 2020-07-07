#ifndef CONTA
#define CONTA


#include <string>

using namespace std;

class Conta{
	public:
	int numero;
	double saldo;
	string titular;
	
	Conta(int n,double s,string t);
	void transfere(double valor, Conta &conta);
	void saca(double valor);
	void deposita(double valor);
};

#endif
