#ifndef _MOVIMIENTOS_H
#define _MOVIMIENTOS_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;


//Clase Movimientos: Se encargará de llevar un registro de las transacciones que hace un usuario con una tarjeta, como atributos tiene un numero de tarjeta (int),
//TipoMovimiento(String) se encarga de decir que movimiento se ha realizado y Cantidad (int) dinero que se ha movido en la operación. 
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