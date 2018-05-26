#ifndef _MOVIMIENTOS_H
#define _MOVIMIENTOS_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Movimientos

{
	int numTarjeta;
	string TipoMovimiento;
	int Cantidad;

	vector<Movimientos> movimientos;
public:

	Movimientos(unsigned int numtarjeta, string tipoMovimiento, int cantidad);

	int getnumTarjeta();
	void setnumTarjeta(int numTarjeta);
	string getTipoMovimiento();
	void setTipoMovimiento(string TipoMovimiento);
	int getCantidad();
	void setCantidad (int Cantidad);

	~Movimientos();

};

#endif