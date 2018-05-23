#include <iostream>
#include <string>
#include <vector>

#include "Operaciones.h"
#include "../Usuarios/Usuarios.h"
#include "../Tarjeta/Tarjeta.h"
#include "../Movimientos/Movimientos.h"

//#include "../BD/DBConnector.cpp"

using namespace std;

//namespace Operaciones
//{

int menu(Usuarios usuarioIntroducido)
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
	int Operaciones::AltaUsuario()
	{
		unsigned int DNI;
		string nombre;
		string apellido;
		string email;

		cout <<"Introduce un nuevo usuario: "<< endl;
		

			//HACER QUE NO SE REPITA; CUANDO FUNCIONE BIEN LA BD

		cout <<"Introduce el DNI: "<<endl;
		cin >> DNI;
			//

		cout <<"Introduce el nombre: "<<endl;
		cin >> nombre;
		cout <<"Introduce el apellido: "<<endl;
		cin >> apellido;
		cout <<"Introduce el email: "<<endl;
		cin >>email;

		Usuarios usu  (DNI, nombre, apellido, email);
	}
	int Operaciones::AltaTarjeta ()
	{

		int PIN;
		int numTarjeta;
		int aux;


		do
		{
	
		cout << "Registra el numero de tu nueva tarjeta" << endl;
		cin >> numTarjeta;
	
		aux = 0;

		// hay que cambiar el aux del for por el tamaño del vector
			for (int i = 0; i < aux; i++)
 			{
 				//if(tarjetas.numTarjeta == tarjetas[i].numTarjeta)
 				//{
 					cout << "El numero de tarjeta ya esta registrado en el sistema" << endl;
 					aux = 1;
 				//}
 				if(numTarjeta == 0)
 				{
 					cout << "El numero de tarjeta no puede ser 0 \n" << endl;
 					aux = 1;
 					break;
 				}
			}
		}while(aux == 1);

	cout << "Introduce el PIN para completar el registro de tu nueva tarjeta" << endl;

	cin >> PIN;

	//Tarjeta -> setsaldo(0);

	}
	void Operaciones::IntroducirTarjeta()
	{


	int numeroTarjeta;
	int PIN;
	
	/* ABRIMOS LA BD
	result = dbConnector.showAllTarjetas();
  	if (result != SQLITE_OK) 
	{
    		std::cout << "Error al sacar las tarjetas" << std::endl;
    		return result;
  	}
	
	*/

	cout << "Introduce tu tarjeta" << endl;
	cin >> numeroTarjeta;

	//COMPROBAR SI LA TARJETA EXISTE NO SABEMOS COMO

	/*if(EXISTE)
	{
		cout << "Tu tarjeta está en los servidores, ahora introduce tu PIN \n<< endl
		cin >>PIN;
	
		if(PIN CORRECTO)
		{	
			cout << "¡Tarjeta introducida! \n" << endl;
		}else
		{
			cout << " PIN INCORRECTO \n << endl;
		}
	}else
	{
		cout << "Lo sentimos, su tarjeta no aparece en los servidores" << endl;

	*/

	}
	void Operaciones::IntroducirUsuario()
	{
	}	
	void Operaciones::ConsultarSaldo()
	{

	}
	void Operaciones::ConsultarMovimiento()
	{

	}
	void Operaciones::Transferencia()
	{

	}
	void Operaciones::SacarDinero()
	{

	}
	void Operaciones::MeterDinero()
	{

	}
	void Operaciones::Salir()
	{



	}
//}