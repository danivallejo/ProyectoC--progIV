#ifndef DBCONNECTOR_H
#define DBCONNECTOR_H
#include "sqlite3.h"
#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
#include "../LN/Usuarios.h"
#include "../LN/Movimientos.h"
#include "../LN/Tarjeta.h"
#include "../LN/Transferencia.h"

using namespace std;

class DBConnector
{
	private:
		sqlite3 *db = NULL;

	public:
	DBConnector(std::string dbFile);
	~DBConnector();

	// -----------------Usuario----------------
	int create_table_Usuarios ();
	int insert_Usuario (Usuarios usuarioInsertar);
	int leer_Usuarios(vector <Usuarios>& listaTodosUsuarios);
	int Usuario_existe(Usuarios user);

	//------------------Tarjeta-----------------

	int create_table_Tarjetas ();
	int Tarjeta_existe(Tarjeta card);
	int insert_Tarjeta (Tarjeta tarjetaInsertar);
	int update_Tarjeta(Tarjeta tarjetaModificar);
	int leer_Tarjetas(vector <Tarjeta>& listaTodasTarjetas);

	//----------------Movimientos---------------

	int create_table_Movimientos ();
	int insert_Movimientos (Movimientos movimientoInsertar);
	int leer_Movimientos(vector <Movimientos>& listaTodosMovimientos);

	//----------------Transferencias-------------

	int create_table_Transferencias ();
	int insert_Transferencia (Transferencia transferenciaInsertar);
	int leer_Transferencias(vector <Transferencia>& listaTodasTransferencias);

};

#endif