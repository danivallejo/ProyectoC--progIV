#include <iostream>
#include <string>
#include <vector>

#include "Operaciones.h"
#include "../Usuarios/Usuarios.h"
//#include "../BD/DBConnector.cpp"

using namespace std;

//namespace Operaciones
//{
	void AltaUsuario()
	{
		vector<Usuarios> usuarios;

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
	int Tarjeta::AltaTarjeta ()
	{

		vector<Tarjetas> tarjetas;

		do
		{
	
		cout << "Registra el numero de tu nueva tarjeta" << endl;
		cin >> Tarjeta --> numTarjeta;
	
		aux = 0;

		
			for (i = 0; i < CantidadTarjetas; i++)
 			{
 				if(tarjeta.numTarjeta == tarjetas[i].numTarjeta)
 				{
 					cout << "El numero de tarjeta ya esta registrado en el sistema" << endl;
 					aux = 1;
 				}
 				if(tarjeta.numTarjeta == 0)
 				{
 					cout << "El numero de tarjeta no puede ser 0 \n" << endl;
 					aux = 1;
 					break;
 				}
			}
		}while(aux == 1);

	cout << "Introduce el PIN para completar el registro de tu nueva tarjeta" << endl;

	scanf ("%i", &tarjeta.Password);

	tarjeta.Saldo = 0;

	}
	void Tarjeta::IntroducirTarjeta ()
	{



	}
	void Tarjeta::ConsultarSaldo()
	{



	}




//}