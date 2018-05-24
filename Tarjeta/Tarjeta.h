#ifndef _TARJETA_H
#define _TARJETA_H

#include <iostream>
#include <vector>

using namespace std;

class Tarjeta
{
	int numTarjeta;
	int PIN;
	int saldo;

	vector<Tarjeta> tarjetas; 

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

#endif