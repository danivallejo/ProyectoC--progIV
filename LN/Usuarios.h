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
	unsigned int PIN;
	string nombre;
	string apellido;
	string email;

	//vector<Usuarios> usuarios;

public:
	Usuarios(unsigned int dni, unsigned int pin, string nombre, string apellido, string email);
	//Usuarios(const Usuarios&);

	int getDNI();
	void setDNI(int DNI);
	int getPIN();
	void setPIN(int PIN);
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