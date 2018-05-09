class Usuario
{
	int DNI;
	String nombre;
	String apellido;

public:
	void Usuario();
	
	int getDNI();
	void setDNI(int DNI);
	String getnombre();
	void setnombre(String nombre);
	String getapellido();
	void setapellido(String apellido);

	~Usuario();

}
