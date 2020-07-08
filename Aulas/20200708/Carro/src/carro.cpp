#include "carro.h"

int Carro::num_carros=0;

Carro::Carro(string col, int num_portas)
{
  this->cor = "Branco";
  this->num_portas = 2;
  this->velocidade = 0;
  this->num_carros++;
}

Carro::~Carro()
{
}

void Carro::acelera(int quantidade)
{
  this->velocidade += quantidade;
}

void Carro::freia(int quantidade)
{
  this->velocidade -= quantidade;
}

