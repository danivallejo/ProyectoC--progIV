#ifndef _MOVIMIENTOS_H
#define _MOVIMIENTOS_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Movimientos

{
	int numTarjeta1;
	int numTarjeta2;
	string TipoMovimiento;
	int Cantidad;

	vector<Movimientos> movimientos;
public:

	Movimientos(unsigned int numtarjeta1, unsigned int numtarjeta2, string tipoMovimiento, int cantidad);

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

#endif