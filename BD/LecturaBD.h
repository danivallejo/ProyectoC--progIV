#ifndef _LECTURABD_H
#define _LECTURABD_H

#include "sqlite3.h"
#include <vector>
#include "../LN/Usuarios.h"
#include "../LN/Movimientos.h"
#include "../LN/Tarjeta.h"
#include "../LN/Transferencia.h"

using namespace std;

class LecturaBD
{
sqlite3 *db; 

public:
	vector<Usuarios> getUsuarios (sqlite3 *db);
	vector<Tarjeta> getTarjetas (sqlite3 *db);
	vector<Movimientos> getMovimientos (sqlite3 *db);
	vector<Transferencia> getTransferencia (sqlite3 *db);
};
#endif