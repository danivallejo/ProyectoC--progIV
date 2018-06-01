#include <iostream>
#include <string>
#include <vector>

#include "Operaciones.h"
#include "Usuarios.h"
#include "Tarjeta.h"
#include "Movimientos.h"
#include "Transferencia.h"
#include "../LP/menu.h"
#include "../BD/DBConnector.h"

//#include "../BD/DBConnector.cpp"

#define rv 20

using namespace std;


//namespace Operaciones
//
	vector <Usuarios> Operaciones::AltaUsuario()
	{
		int existe;
		DBConnector db ("test.db");
		vector <Usuarios> users;

		users.reserve(rv);

		unsigned int DNI;
		unsigned int PIN;
		string nombre;
		string apellido;
		string email;

		cout <<"Introduce un nuevo usuario: "<< endl;
		

			//HACER QUE NO SE REPITA; CUANDO FUNCIONE BIEN LA BD

		cout <<"Introduce el DNI: "<<endl;
		cin >> DNI;
			//



		cout <<"Introduce el PIN: "<<endl;
		cin >> PIN;
		cout <<"Introduce el nombre: "<<endl;
		cin >> nombre;
		cout <<"Introduce el apellido: "<<endl;
		cin >> apellido;
		cout <<"Introduce el email: "<<endl;
		cin >>email;

		Usuarios usu  (DNI, PIN, nombre, apellido, email);

			//LLAMAR AL METODO USUARIO EXISTE
		existe = db.Usuario_existe(usu);

		if(existe == 0)
		{
			cout << "Se ha creado un usuario con DNI " << usu.getDNI() << "y PIN " << usu.getPIN() << endl;
			cout << "Tiene los siguientes datos personales: "<< endl;
			cout << "Nombre: "<< usu.getnombre() << endl;
			cout << "Apellido: "<< usu.getapellido() << endl;
			cout << "Correo electronico: "<< usu.getemail() << endl;

			if(users.size() < rv)
			{
				users.push_back(usu);
				cout << users.size() << endl;

				db.insert_Usuario(usu);
			}
			else
			{
				cout <<"No se pueden añadir mas usuarios" << endl;
			}
			

		}
		else 
		{
			cout <<"El usuario ya existe" << endl;
		}		
	return users;
	}
	void Operaciones::IntroducirUsuario(vector <Usuarios> users)
	{
		DBConnector db ("test.db");

		db.leer_Usuarios(users);

		int DNI;
		int PIN;
		

		cout << "Desea iniciar sesión. Introduce el DNI de un usuario: " << endl;
		cin >> DNI;
		
		cout << "Introduce el PIN de este usuario: " << endl;
		cin >> PIN;

		//Usuarios uIntroducido (DNI, PIN, uIntroducido.getnombre(), uIntroducido.getapellido(), uIntroducido.getemail());

		//uIntroducido.setDNI(DNI);
		//uIntroducido.setPIN(PIN);
		for (int i= 0; i< rv; i++)
		{
			if(users[i].getDNI() == DNI)
			{
				if(users[i].getPIN() == PIN)
				{
					Usuarios uIntroducido (DNI, PIN, users[i].getnombre(), users[i].getapellido(), users[i].getemail());
					cout << "El usuario " << uIntroducido.getDNI() << " de nombre " << uIntroducido.getnombre() <<" ha iniciado sesión!" << endl;
					//menuOperaciones(uIntroducido);
				}
				else
				{
					cout << "El PIN es incorrecto!" << endl;
				}
			}
			else
			{
				cout << "El usuario introducido no esta registrado!" << endl;
			}
	
		}	
		//cout << uIntroducido.getDNI << endl <<uIntroducido.getPIN << endl;


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