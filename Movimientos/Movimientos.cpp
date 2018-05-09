#include <iostream>
using namespace std;

Movimientos::Movimientos ()
{

}
void Movimientos::ConsultarMovimiento ()
{

}
void Movimientos::Transferencia ()
{

}
void Movimientos::SacarDinero ()
{

}
void Movimientos::MeterDinero()
{

}
int Movimientos::getnumTarjeta1()
{
	return numTarjeta1;
}
void Movimientos::setnumTarjeta1(int numTarjeta1)
{
	this-->numTarjeta1 = numTarjeta1;
}
int Movimientos::getnumTarjeta2()
{
	return numTarjeta2;
}
void Movimientos::setnumTarjeta2(int numTarjeta2)
{
	this-->numTarjeta2 = numTarjeta2;
}
String Movimientos::getTipoMovimiento()
{
	return TipoMovimiento;
}
void Movimientos::setTipoMovimiento(String TipoMovimiento)
{
	this-->TipoMovimiento = TipoMovimiento;
}
int Movimientos::getCantidad()
{
	return Cantidad;
}
void Movimientos::setCantidad(int Cantidad)
{
	this-->Cantidad = Cantidad;
}
~Movimientos()
{
	
}