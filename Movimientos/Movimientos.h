#include <iostream>

namespace Movimientos
{
class Movimientos

{
	int numTarjeta1;
	int numTarjeta2;
	std::string TipoMovimiento;
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
	std::string getTipoMovimiento();
	void setTipoMovimiento(std::string TipoMovimiento);
	int getCantidad();
	void setCantidad (int Cantidad);

	~Movimientos();

};
}