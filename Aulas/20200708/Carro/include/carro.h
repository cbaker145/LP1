#ifndef CARRO
#define CARRO

#include <string>

using namespace std;

class Carro
{
  public:
    Carro(string col, int num_portas);
    ~Carro();
    
    static int num_carros;

    string cor;
    int num_portas;
    double velocidade;

	void acelera(int valor);
    void freia(int valor);
};
#endif
