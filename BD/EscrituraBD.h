#ifndef _ESCRITURABD_H
#define _ESCRITURABD_H

#include <string.h>
#include <iostream>
#include "sqlite3.h"

using namespace std;

class EscrituraBD
{
sqlite3 *db;

public:
	void iniciarBD(sqlite3 *db);
	int altaUsuario (sqlite3 *db, int DNI, string nombre, string apellido, string email);
	int altaTarjeta (sqlite3 *db, int numtarjeta, int PIN, int saldo);
	int altaMovimiento (sqlite3 *db, int numTarjeta, string tipoMovimiento, int cantidad);
	int altaTransferencia (sqlite3 *db, int numTarjeta1, int numTarjeta2, int cantidad);
};
#endif
