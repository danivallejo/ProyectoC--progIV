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
	vector <Tarjeta> AltaTarjeta (Usuarios usuarioIntroducido, vector <Tarjeta> cards);
	void IntroducirTarjeta(vector <Tarjeta> cards);
	void ConsultarSaldo(Tarjeta cIntroducido);
	void Salir();

	void ConsultarMovimiento(Tarjeta cIntroducido, vector <Movimientos> moves);
	void SacarDinero(Tarjeta cIntroducido, vector <Movimientos> moves);
	void MeterDinero(Tarjeta cIntroducido, vector <Movimientos> moves);

	//vector <Transferencia> Transferencia(Tarjeta cIntroducido, vector <Transferencia> transfers, vector <Tarjeta> cards);
	void ConsultarTransferencias(Tarjeta cIntroducido, vector <Transferencia> transfers);
};

#endif


//}