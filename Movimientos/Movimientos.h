class Movimientos

{
	int numTarjeta1;
	int numTarjeta2;
	String TipoMovimiento;
	int Cantidad;

public:

	Movimientos();
	void ConsultarMovimiento();
	void Transferencia();
	void SacarDinero();
	void MeterDinero();

	int getnumTarjeta1();
	void setnumTarjeta1(int numTarjeta1);
	int getnumTarjeta2();
	void setnumTarjeta2 (int numTarjeta2);
	String TipoMovimiento();
	void setTipoMovimiento(String TipoMovimiento);
	int getCantidad();
	void setCantidad (int Cantidad);

}