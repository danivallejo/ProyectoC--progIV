#include <iostream>
#include <string>

#include "Operaciones.h"
#include "../Usuarios/Usuarios.h"
//#include "../BD/DBConnector.cpp"

using namespace std;

//namespace Operaciones
//{
	AltaUsuario()
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




//}