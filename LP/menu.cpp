#include "../LN/Operaciones.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <fstream>
#include <stdlib.h>
#include "menu.h"
#include <vector>

using namespace std;

#define rv 20

menu::menu()
{

}
void menu::menuUsuario()
{
	int a;
	Operaciones o;
	vector <Usuarios> users;
	users.reserve(rv);

  	do 

	{
		cout << endl <<" Este es el menu principal. Seleccione que operación desea realizar:" << endl <<" 1. Registrar usuario. 2.Iniciar sesion . 3.Salir." << endl;

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
void menu::menuTarjeta(Usuarios uIntroducido)
{
	Operaciones o;
	int a;
	vector <Tarjeta> cards;
	cards.reserve(rv);

	do
	{
	
	cout << "Este es el menu principal. Seleccione la operacion que desee:  \n 1. Sacar Dinero \n 2. Ingresar Dinero \n 3. Consultar Saldo \n 4. Consultar Movimientos \n 5. Transferencia \n 6. Salir \n"<< endl;

	cin >> a; 

	switch(a)	
	{
	case 1:
	o.AltaTarjeta(uIntroducido);
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
void menu::menuOperaciones(Tarjeta cIntroducida)
{
	Operaciones o;
	int a;
	vector <Movimientos> moves;
	vector <Transferencia> transfers;
	vector <Tarjeta> cards;
	moves.reserve(rv);

	do
	{
	
	cout << "Este es el menu principal. Seleccione la operacion que desee:  \n 1. Sacar Dinero \n 2. Ingresar Dinero \n 3. Consultar Saldo \n 4. Consultar Movimientos \n 5. Transferencia \n 6. Consultar Transferencias \n 7. Salir \n"<< endl;

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
	o.ConsultarSaldo(cIntroducida);
	break;
	case 4:
	o.ConsultarMovimiento(cIntroducida, moves);
	break;
	case 5:
	o.Transferencia(cIntroducida, transfers, cards);
	break;
	case 6:
	o.ConsultarTransferencias(cIntroducida, transfers);
	case 7:
	o.Salir();
	break;	
	}
	}while(a!=7);
}





menu::~menu()
{

}	



