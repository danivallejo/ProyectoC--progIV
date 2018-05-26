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
	int altaUsuario (sqlite3 *db, int DNI, string nombre, string apellido, string email);
	int altaTarjeta (sqlite3 *db, int numtarjeta, int PIN, int saldo);
	int altaMovimiento (sqlite3 *db, int numTarjeta, string tipoMovimiento, int cantidad);
	int altaTransferencia (sqlite3 *db, int numTarjeta1, int numTarjeta2, int cantidad);
	int actualizacionTarjeta (sqlite3 *db, int numtarjeta, int nuevosaldo);
	int getUsuarios (vector<Usuarios>);
	int getTarjetas (vector<Usuarios>);
	int getMovimientos (vector<Usuarios>);
	int getTransferencia (vector<Usuarios>);
};