#include <iostream>

namespace Usuarios
{

class Usuarios
{
	int DNI;
	std::string nombre;
	std::string apellido;

public:
	Usuarios();

	int getDNI();
	void setDNI(int DNI);
	std::string getnombre();
	void setnombre(std::string nombre);
	std::string getapellido();
	void setapellido(std::string apellido);

	~Usuarios();

};
}