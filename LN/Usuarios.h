#ifndef _USUARIOS_H
#define _USUARIOS_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//La clase usuarios tiene 4 atributos: DNI(int) es el DNI del usuario, el identificador; nombre(String) nombre del usuario; apellido (String) apellido del usuario
// email(String) email del usuario  
class Usuarios
{
	unsigned int DNI;
	string nombre;
	string apellido;
	string email;

	//vector<Usuarios> usuarios;

public:
	Usuarios(unsigned int dni, string nombre, string apellido, string email);
	//Usuarios(const Usuarios&);

	int getDNI();
	void setDNI(int DNI);
	string getnombre();
	void setnombre(string nombre);
	string getapellido();
	void setapellido(string apellido);
	string getemail();
	void setemail(string email);

	~Usuarios();

};
//}
#endif