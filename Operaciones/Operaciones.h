#ifndef _OPERACIONES_H
#define _OPERACIONES_H

#include <iostream>
#include <string>
#include <vector>
#include "../Tarjeta/Tarjeta.h"
#include "../Movimientos/Movimientos.h"
#include "../Usuarios/Usuarios.h"

using namespace std;

//namespace Operaciones
//{
class Operaciones
{
	
public: 
	int menu(Usuarios usuarioIntroducido);
	int AltaUsuario();
	void IntroducirUsuario();
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