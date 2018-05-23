#include <iostream>
#include "Tarjeta.h"

using namespace std;

namespace Tarjeta
{

Tarjeta::Tarjeta()
{/*
	for(int i; i < tarjetas.size(); i++)
	{
		tarjetas[i].push_back(numTarjeta, PIN, saldo);
	}
*/	
}
int Tarjeta::getnumTarjeta()
{
return numTarjeta;
}
void Tarjeta::setnumTarjeta(int numTarjeta)
{
this->numTarjeta=numTarjeta;
}
int Tarjeta::getPIN()
{
return PIN;
}
void Tarjeta::setPIN(int PIN)
{
this->PIN=PIN;
}
int Tarjeta::getsaldo()
{
return saldo;
}
void Tarjeta::setsaldo(int saldo)
{
this->saldo=saldo;	
}
Tarjeta::~Tarjeta()
{
//delete tarjetas;
}
}
