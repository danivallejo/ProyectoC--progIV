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
	vector <Tarjeta> Operaciones::AltaTarjeta (Usuario UsuarioIntroducido)
	{
		int existe;
		DBConnector db ("test.db");
		vector <Tarjeta> cards;

		cards.reserve(rv);

		unsigned int PIN;
		unsigned int numTarjeta;
		//NO SE SI SALDO SE DEBERIA PASAR POR PARAMETRO
		unsigned int saldo = 0;
		unsigned int aux;
		unsigned int DNIUsuario = UsuarioIntroducido.getDNI();


		do
		{
			cout << "Registra el numero de tu nueva tarjeta" << endl;
			cin >> numTarjeta;
			cout << "Introduce el PIN de tu nueva tarjeta" << endl;
			cin >> PIN;


	
			Tarjeta card (numTarjeta, PIN, saldo, DNIUsuario);
			aux = 0;

			existe = db.Tarjeta_existe(card);

			if (existe == 0)
			{
				cout << "Se ha creado una tarjeta con este numero: " card.getnumTarjeta() << endl;
			}

			if(cards.size() < rv)
			{
				cards.push_back(card);
				cout << cards.size() << endl;

				db.inser_Tarjeta(card);
			}
			else
			{
				cout <<"No se pueden añadir mas tarjetas" << endl;
			}
			

		}
		else 
		{
			cout <<"El numero de tarjeta ya existe" << endl;
		}		
	return cards;
	}
	void Operaciones::IntroducirTarjeta(vector <Tarjeta> cards)
	{
		DBConnector db ("test.db");

		db.leer_Tarjetas(cards);

		int numeroTarjeta;
		int PIN;
		int saldo;
	
	cout << "Introduce tu numero de tarjeta" << endl;
	cin >> numeroTarjeta;

	cout << "Introduce el PIN" << endl;
	

	cout << "Introduce tu tarjeta" << endl;
	cin >> numeroTarjeta;

	for (int i= 0; i< rv; i++)
		{
			if(cards[i].getnumTarjeta() == numeroTarjeta)
			{
				if(cards[i].getPIN() == PIN)
				{
					Tarjeta cIntroducido (numeroTarjeta, PIN, cards[i].getsaldo);
					cout << "El numero de tarjeta introducido es " << cIntroducido.getnumTarjeta()<< endl;
					//menuOperaciones(uIntroducido);
				}
				else
				{
					cout << "El PIN es incorrecto!" << endl;
				}
			}
			else
			{
				cout << "El numero de tarjeta introducido no esta registrado!" << endl;
			}
	
		}	

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