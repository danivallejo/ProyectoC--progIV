#include <iostream>
#include <string>

#include "Usuarios.h"

using namespace std;

//namespace Usuario
//{


Usuarios::Usuarios(unsigned int dni, string nombre, string apellido, string email)
{
	this -> DNI = dni;
	this -> nombre = nombre;
	this -> apellido = apellido;
	this -> email = email;
}
/*int Usuarios::AltaUsuario()
{
cout <<"Introduce un nuevo usuario: "<< endl;
cout <<"Introduce el DNI: "<<endl;
cin >> DNI;
cout <<"Introduce el nombre: "<<endl;
cin >> nombre;
cout <<"Introduce el apellido: "<<endl;
cin >> apellido;
cout <<"Introduce el email: "<<endl;
cin >>email;
}*/
int Usuarios::getDNI()
{
return DNI;
}
void Usuarios::setDNI(int DNI)
{
this->DNI=DNI;
}
string Usuarios::getnombre()
{
return nombre;
}
void Usuarios::setnombre(string nombre)
{
this->nombre=nombre;
}
string Usuarios::getapellido()
{
return apellido;
}
void Usuarios::setapellido(string apellido)
{
this->apellido = apellido;
}
string Usuarios::getemail()
{
return email;
}
void Usuarios::setemail(string email)
{
this->email = email;
}
Usuarios::~Usuarios()
{
//delete u;
}
//}