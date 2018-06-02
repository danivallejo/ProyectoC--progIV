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
	vector <Usuarios> AltaUsuario(vector <Usuarios> users);
	void IntroducirUsuario(vector <Usuarios> users);
	vector <Tarjeta> AltaTarjeta (Usuarios usuarioIntroducido);
	void IntroducirTarjeta(vector <Tarjeta> cards);
	void ConsultarSaldo(Tarjeta cIntroducido);
	void Salir();

	void ConsultarMovimiento(Tarjeta cIntroducido, vector <Movimientos> moves);
	void Transferencia(Tarjeta cIntroducido, vector <Transferencia> transferencias, vector <Tarjeta> cards);
	void SacarDinero(Tarjeta cIntroducido, vector <Movimientos> moves);
	void MeterDinero(Tarjeta cIntroducido, vector <Movimientos> moves);

};

#endif


//}