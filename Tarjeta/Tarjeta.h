#ifndef _TARJETA_H
#define _TARJETA_H

#include <iostream>

namespace Tarjeta
{
class Tarjeta
{
	int numTarjeta;
	int PIN;
	int saldo;

public:
	Tarjeta();
	
	
	int getnumTarjeta();
	void setnumTarjeta(int numTarjeta);
	int getPIN();
	void setPIN(int PIN);
	int getsaldo();
	void setsaldo(int saldo);

	~Tarjeta();
};
}

#endif