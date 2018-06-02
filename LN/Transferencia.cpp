#include <iostream>
#include <string>
#include "Transferencia.h"

using namespace std;

Transferencia::Transferencia (unsigned int numtarjeta1, unsigned int numtarjeta2, int cantidad)
{
	this -> numTarjeta1 = numtarjeta1;
	this -> numTarjeta2 = numtarjeta2;
	this -> Cantidad = cantidad;
}
int Transferencia::getnumTarjeta1()
{
	return numTarjeta1;
}
void Transferencia::setnumTarjeta1(int numTarjeta1)
{
	this->numTarjeta1 = numTarjeta1;
}
int Transferencia::getnumTarjeta2()
{
	return numTarjeta2;
}
void Transferencia::setnumTarjeta2(int numTarjeta2)
{
	this->numTarjeta2 = numTarjeta2;
}
int Transferencia::getCantidad()
{
	return Cantidad;
}
void Transferencia::setCantidad(int Cantidad)
{
	this->Cantidad = Cantidad;
}
Transferencia::~Transferencia()
{
//delete m;
}
