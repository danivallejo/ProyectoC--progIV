#ifndef _TARJETA_H
#define _TARJETA_H

#include <iostream>
#include <vector>

using namespace std;

//La clase Tarjeta te´ndrá tres atributos: numTarjeta(int) será el numero de la tarjeta, PIN(int) clave secreta de la tarjera, Saldo (int) dinero que tiene la tarjeta
class Tarjeta
{
	unsigned int numTarjeta;
	unsigned int PIN;
	int saldo;

	//vector<Tarjeta> tarjetas; 

public:
	Tarjeta(unsigned int numtarjeta, unsigned int pin, int Saldo); //unsigned int dniUsuario);
	
	
	int getnumTarjeta();
	void setnumTarjeta(int numTarjeta);
	int getPIN();
	void setPIN(int PIN);
	int getsaldo();
	void setsaldo(int saldo);
	//int getDNIUsuario();
	//void setDNIUsuario(int DNIUsuario);

	~Tarjeta();
};

#endif