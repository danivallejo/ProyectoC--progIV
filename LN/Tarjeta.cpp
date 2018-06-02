#include <iostream>
#include "Tarjeta.h"

using namespace std;


Tarjeta::Tarjeta(unsigned int numtarjeta, unsigned int pin, int Saldo, unsigned int dniUsuario)
{
	this -> numTarjeta = numtarjeta;
	this -> PIN = pin;
	this -> saldo = Saldo;
	this -> DNIUsuario = dniUsuario
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
int Tarjeta::getdniUsuario()
{
return saldo;
}
void Tarjeta::setdniUsuario(int dniUsuario)
{
this->dniUsuario=dniUsuario;	
}


Tarjeta::~Tarjeta()
{
//delete tarjetas;
}