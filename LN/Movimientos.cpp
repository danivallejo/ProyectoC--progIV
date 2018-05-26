#include <iostream>
#include <string>
#include "Movimientos.h"

using namespace std;


Movimientos::Movimientos (unsigned int numtarjeta, string tipoMovimiento, int cantidad)
{
	this -> numTarjeta = numtarjeta;
	this -> TipoMovimiento = tipoMovimiento;
	this -> Cantidad = cantidad;



}
int Movimientos::getnumTarjeta()
{
	return numTarjeta;
}
void Movimientos::setnumTarjeta(int numTarjeta1)
{
	this->numTarjeta = numTarjeta;
}
string Movimientos::getTipoMovimiento()
{
	return TipoMovimiento;
}
void Movimientos::setTipoMovimiento(string TipoMovimiento)
{
	this->TipoMovimiento = TipoMovimiento;
}
int Movimientos::getCantidad()
{
	return Cantidad;
}
void Movimientos::setCantidad(int Cantidad)
{
	this->Cantidad = Cantidad;
}
Movimientos::~Movimientos()
{
//delete m;
}
