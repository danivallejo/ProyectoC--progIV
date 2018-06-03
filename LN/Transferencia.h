#ifndef _TRANSFERENCIA_H
#define _TRANSFERENCIA_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//La clase transferencia tendrá 3 atributos: numTarjeta1(int) tarjeta que realiza la transferencia, la que "manda" el dinero; numTarjeta2(int) tarjeta que recibe la transferencia
//Cantidad(int) Dinero que se manda en la transferencia.

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