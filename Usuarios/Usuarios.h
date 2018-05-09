class Usuarios
{
	int DNI;
	String nombre;
	String apellido;

public:
	Usuarios();

	int getDNI();
	void setDNI(int DNI);
	String getnombre();
	void setnombre(String nombre);
	String getapellido();
	void setapellido(String apellido);

	~Usuario();

};
