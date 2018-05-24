#ifndef _LECTURABD_H
#define _LECTURABD_H

#include "sqlite3.h"
#include <vector>
#include "../Usuarios/Usuarios.h"
#include "../Movimientos/Movimientos.h"
#include "../Tarjeta/Tarjeta.h"

using namespace std;

class LecturaBD
{
sqlite3 *db; 

public:
	vector<Usuarios> getUsuarios (sqlite3 *db);
	vector<Tarjeta> getTarjetas (sqlite3 *db);
	vector<Movimientos> getMovimientos (sqlite3 *db);
};
#endif