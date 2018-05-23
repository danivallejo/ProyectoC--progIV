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
	void IntroducirTarjeta()
{
	unsinged int numeroTarjeta;
	int PIN;
	
	/* ABRIMOS LA BD
	result = dbConnector.showAllTarjetas();
  	if (result != SQLITE_OK) 
	{
    		std::cout << "Error al sacar las tarjetas" << std::endl;
    		return result;
  	}
	
	*/

	cout << "Introduce tu tarjeta" \n << endl
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
	void Tarjeta::ConsultarSaldo()
	{



	}




//}