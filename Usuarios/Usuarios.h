#include <iostream>
#include <string>

using namespace std;

//namespace Usuario
//{

class Usuarios
{
	unsigned int DNI;
	string nombre;
	string apellido;
	string email;

public:
	Usuarios(unsigned int dni, string nombre, string apellido, string email);

	int AltaUsuario();
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