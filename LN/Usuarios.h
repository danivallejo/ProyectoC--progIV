#ifndef _USUARIOS_H
#define _USUARIOS_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//namespace Usuario
//{

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