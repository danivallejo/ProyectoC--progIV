#ifndef _OPERACIONES_H
#define _OPERACIONES_H

#include <iostream>
#include <string>
#include <vector>

#include "Tarjeta.h"
#include "Movimientos.h"
#include "Usuarios.h"
#include "Transferencia.h"

using namespace std;

//La clase Operaciones se encargará de ejecutar todas las opciones que tiene el usuario en el cajero: Alta Usuario, registrarse; Introducir Usuario, sería como iniciar sesión; 
//Alta Tarjeta, se crea una nueva tarjeta; Introducir Tarjeta, inicia sesión de esa tarjeta; Consultar Saldo, Devuelve un int con el dinero que hay en la tarjeta;
//Consultar Movimiento, devuelve los movimientos realizados desde esa tarjeta; Sacar Dinero, le permite al usuario retirar dinero; Meter Dinero, le permite al usuario
//introducir dinero en la tarjeta; Transferencia, permite al usuario mandar dinero a otra tarjeta; Consultar Transferencia, devuelve las transferencias realizadas y las recibidas
class Operaciones
{
	
public: 
	int menu(Usuarios usuarioIntroducido);
	vector <Usuarios> AltaUsuario(vector <Usuarios> users);
	void IntroducirUsuario(vector <Usuarios> users);
	vector <Tarjeta> AltaTarjeta (vector <Tarjeta> cards);
	void IntroducirTarjeta(vector <Tarjeta> cards);
	void ConsultarSaldo(Tarjeta cIntroducido);
	void Salir();

	void ConsultarMovimiento(Tarjeta cIntroducido, vector <Movimientos> moves);
	vector <Movimientos> SacarDinero(Tarjeta& cIntroducido, vector <Movimientos> moves);
	vector <Movimientos> MeterDinero(Tarjeta& cIntroducido, vector <Movimientos> moves);

	//vector <Transferencia> Transferencia(Tarjeta cIntroducido, vector <Transferencia> transfers, vector <Tarjeta> cards);
	void ConsultarTransferencias(Tarjeta cIntroducido, vector <Transferencia> transfers);
};

#endif


//}