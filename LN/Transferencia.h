#ifndef _TRANSFERENCIA_H
#define _TRANSFERENCIA_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Transferencia
{
	int numTarjeta1;
	int numTarjeta2;
	int Cantidad;
public:

	Transferencia(unsigned int numtarjeta1, unsigned int numtarjeta2, int cantidad);

	int getnumTarjeta1();
	void setnumTarjeta1(int numTarjeta1);
	int getnumTarjeta2();
	void setnumTarjeta2 (int numTarjeta2);
	int getCantidad();
	void setCantidad (int Cantidad);

	~Transferencia();
};
#endif