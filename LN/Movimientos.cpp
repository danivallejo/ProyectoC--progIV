#include <iostream>
#include <string>
#include "Movimientos.h"

using namespace std;


Movimientos::Movimientos (unsigned int numtarjeta1, unsigned int numtarjeta2, string tipoMovimiento, int cantidad)
{
	this -> numTarjeta1 = numtarjeta1;
	this -> numTarjeta2 = numtarjeta2;
	this -> TipoMovimiento = tipoMovimiento;
	this -> Cantidad = cantidad;



}
int Movimientos::getnumTarjeta1()
{
	return numTarjeta1;
}
void Movimientos::setnumTarjeta1(int numTarjeta1)
{
	this->numTarjeta1 = numTarjeta1;
}
int Movimientos::getnumTarjeta2()
{
	return numTarjeta2;
}
void Movimientos::setnumTarjeta2(int numTarjeta2)
{
	this->numTarjeta2 = numTarjeta2;
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
