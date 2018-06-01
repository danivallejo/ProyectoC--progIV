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

//namespace Operaciones
//{
class Operaciones
{
	
public: 
	int menu(Usuarios usuarioIntroducido);
	vector <Usuarios> AltaUsuario();
	void IntroducirUsuario(vector <Usuarios> users);
	int AltaTarjeta ();
	void IntroducirTarjeta();
	void ConsultarSaldo();
	void Salir();

	void ConsultarMovimiento();
	void Transferencia();
	void SacarDinero();
	void MeterDinero();

};

#endif


//}