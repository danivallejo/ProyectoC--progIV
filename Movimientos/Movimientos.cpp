#include <iostream>
using namespace std;

Movimientos::Movimientos ()
{

}
void Movimiento::ConsultarMovimiento ()
{

}
void Movimiento::Transferencia ()
{

}
void Movimiento::SacarDinero ()
{

}
void Movimiento::MeterDinero()
{

}
int getnumTarjeta1()
{
	return numTarjeta1;
}
void setnumTarjeta1(int numTarjeta1)
{
	this-->numTarjeta1 = numTarjeta1;
}
int getnumTarjeta2()
{
	return numTarjeta2;
}
void setnumTarjeta2(int numTarjeta2)
{
	this-->numTarjeta2 = numTarjeta2;
}
String getTipoMovimiento()
{
	return TipoMovimiento;
}
void setTipoMovimiento(String TipoMovimiento)
{
	this-->TipoMovimiento = TipoMovimiento;
}
int getCantidad()
{
	return Cantidad;
}
void setCantidad(int Cantidad)
{
	this-->Cantidad = Cantidad;
}
~Movimientos()
{
	
}