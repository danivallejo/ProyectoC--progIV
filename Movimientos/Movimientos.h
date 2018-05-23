#ifndef _MOVIMIENTOS_H
#define _MOVIMIENTOS_H

#include <iostream>
#include <string>

using namespace std;

namespace Movimientos
{
class Movimientos

{
	int numTarjeta1;
	int numTarjeta2;
	string TipoMovimiento;
	int Cantidad;

public:

	Movimientos();


	int getnumTarjeta1();
	void setnumTarjeta1(int numTarjeta1);
	int getnumTarjeta2();
	void setnumTarjeta2 (int numTarjeta2);
	string getTipoMovimiento();
	void setTipoMovimiento(string TipoMovimiento);
	int getCantidad();
	void setCantidad (int Cantidad);

	~Movimientos();

};
}
#endif