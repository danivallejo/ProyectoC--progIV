#include "../LN/Operaciones.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <fstream>
#include "menu.h"
#include "../LN/Usuarios.h"
#include "../LN/Tarjeta.h"
#include "../LN/Transferencia.h"
#include "../LN/Movimientos.h"
#include <vector>

using namespace std;

#define rv 20


//Esta clase tendrá 3 menus diferentes: el de usuario, el de tarjetas y el de operaciones.

//menuUsuario es el primer menú que aparece en la aplicación le permite al usuario 3 opciones: registrarse, iniciar sesión o salir.
void menuUsuario()
{
	int a;
	Operaciones o;
	vector <Usuarios> users;
	users.reserve(rv);

  	do 

	{
		cout << endl <<" Este es el menu principal. Seleccione que operacion desea realizar:" << endl <<" 1. Registrar usuario. 2.Iniciar sesion . 3.Salir." << endl;

		cin >> a;

		switch (a)
		{
			case 1:
			o.AltaUsuario(users);
			break;
			case 2: 
			o.IntroducirUsuario(users);
			break;
			case 3:
			o.Salir();
			break;
		}
	}while(a != 3);
}

//menuTarjeta es el segundo de los menús, le llamamos en el momento en el que el usuario ha iniciado sesión. Desde aquí puede registrar una nueva tarjeta,
// introducir tarjeta o salir.
void menuTarjeta(Usuarios uIntroducido)
{
	Operaciones o;
	int a;
	vector <Tarjeta> cards;

	cards.reserve(rv);

	do
	{
	
	cout << " Has iniciado sesion correctamente. Seleccione la operacion que desee: "<< endl << "1. Registrar tarjeta" << endl << "2. Introducir Tarjeta" << endl << "3. Salir" << endl;

	cin >> a; 

	switch(a)	
	{
	case 1:
	o.AltaTarjeta(cards);
	break;
	case 2:
	o.IntroducirTarjeta(cards);
	break;
	case 3:
	o.Salir();
	break;
	}
	}while(a!=3);
}

//menuoperaciones es el tercer menú, aparece cuando el usuario ha introducido una tarjeta. Es el menú real de la aplicación 
//el cual le da al usuario distintas opciones para operar con su tarjeta
void menuOperaciones(Tarjeta cIntroducida, vector <Tarjeta> cards)
{
	Operaciones o;
	int a;
	vector <Movimientos> moves;
	vector <Transferencia> transfers;

	moves.reserve(rv);
	transfers.reserve(rv);

	do
	{
	
	cout << "Este es el menu principal. Seleccione la operacion que desee: " << endl << " 1. Sacar Dinero " << endl << " 2. Ingresar Dinero " << endl <<
	" 3. Consultar Saldo " << endl << " 4. Consultar Movimientos " << endl << " 5. Transferencia " << endl << " 6. Consultar Transferencias " << endl << " 7. Salir "<< endl;

	cin >> a; 

	switch(a)	
	{
	case 1:	
	o.SacarDinero(cIntroducida, moves);
	break;
	case 2:
	o.MeterDinero(cIntroducida, moves);
	break;
	case 3:
	o.ConsultarSaldo(cIntroducida/*, moves*/);
	break;
	case 4:
	o.ConsultarMovimiento(cIntroducida, moves);
	break;
	case 5:
	o.RealizarTransferencia(cIntroducida, transfers, cards);
	break;
	case 6:
	o.ConsultarTransferencias(cIntroducida, transfers);
	case 7:
	o.Salir();
	break;	
	}
	}while(a!=7);
}




