#ifndef _TARJETA_H
#define _TARJETA_H

#include <iostream>
#include <vector>

using namespace std;

class Tarjeta
{
	unsigned int numTarjeta;
	unsigned int PIN;
	int saldo;

	vector<Tarjeta> tarjetas; 

public:
	Tarjeta(unsigned int numtarjeta, unsigned int pin, int Saldo);
	
	
	int getnumTarjeta();
	void setnumTarjeta(int numTarjeta);
	int getPIN();
	void setPIN(int PIN);
	int getsaldo();
	void setsaldo(int saldo);

	~Tarjeta();
};

#endif