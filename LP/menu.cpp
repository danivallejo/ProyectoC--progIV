#include "../LN/Operaciones.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <fstream>
#include <stdlib.h>

using namespace std;

void menuUsuario()
{
	int a;
	Operaciones o;
  	do 

	{
		cout << endl <<" Este es el menu principal. Seleccione que operación desea realizar:" << endl <<" 1. Registrar usuario. 2.Iniciar sesion . 3.Salir." << endl;

		cin >> a;

		switch (a)
		{
			case 1:
			o.AltaUsuario();
			break;
			case 2: 
			o.IntroducirUsuario();
			break;
			case 3:
			o.Salir();
			break;
		}
	}while(a != 3);
}
void menuOperaciones()
{
	Operaciones o;
	int a;
	do
	{

	printf("\nEste es el menu principal. Seleccione la operacion que desee:  \n 1. Sacar Dinero \n 2. Ingresar Dinero \n 3. Consultar Saldo \n 4. Consultar Movimientos \n 5. Transferencia \n 6. Salir \n");

	scanf("%i", &a);

	switch(a)	
	{
	case 1:
	o.AltaTarjeta();
	break;
	case 2:
	o.IntroducirTarjeta();
	break;
	case 3:
	o.SacarDinero();
	break;
	case 4:
	o.MeterDinero();
	break;
	case 5:
	o.ConsultarSaldo();
	break;
	case 6:
	o.ConsultarMovimiento();
	break;
	case 7:
	o.Transferencia();
	case 8:
	o.Salir();
	break;
	}
	}while(a!=8);
}	



