#include "sqlite3.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include "EscrituraBD.h"
#include <ctype.h>
#include <fstream>
#include <sstream>

using namespace std;

void iniciarBD (sqlite3 *db)
{
	char *err_message=0;
	int rc;

	const char *sql_query = "CREATE TABLE USUARIOS (DNI INT PRIMARY KEY NOT NULL, NOMBRE TEXT, APELLIDO TEXT, EMAIL TEXT)";
	rc = sqlite3_exec (db, sql_query, 0, 0, &err_message);
	if (rc != SQLITE_OK)
		cout << sqlite3_errmsg(db);

	const char *sql_query2 = "CREATE TABLE TARJETAS (NUMEROTARJETA INT PRIMARY KEY NOT NULL, PIN INT NOT NULL, SALDO INT NOT NULL)";
	rc = sqlite3_exec (db, sql_query2, 0, 0, &err_message);
	if (rc != SQLITE_OK)
		cout << sqlite3_errmsg(db);

	const char *sql_query3 = "CREATE TABLE MOVIMIENTOS (NUMEROTARJETA1 INT PRIMARY KEY NOT NULL, NUMEROTARJETA2 INT, TIPOMOVIMIENTO TEXT NOT NULL, CANTIDAD INT NOT NULL)";
	rc = sqlite3_exec (db, sql_query3, 0, 0, &err_message);
	if (rc != SQLITE_OK)
		cout << sqlite3_errmsg(db);

	//HACER TABLA TRANSFERENCIAS
}

int altaUsuario (sqlite3 *db, int DNI, string nombre, string apellido, string email)
{
	sqlite3_stmt *stmt;

	stringstream ss;
	ss << "INSERT INTO USUARIOS (dni, nombre, apellido, email) values (" << DNI << ",'" << nombre <<",'" << apellido << ",'" << email << ")";
	string ssql = ss.str();
	char* sql = new char [ssql.length () +1];
	strcpy(sql, ssql.c_str());

	int result = sqlite3_prepare_v2(db,sql,-1,&stmt, NULL);
	if (result != SQLITE_OK)
	{
		cout << sqlite3_errmsg(db) << endl;
		return result;
	} 

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE)
	{
		cout << "ERROR. El DNI ya se ha registrado" << endl;
		return result;
	}
	
	result = sqlite3_finalize (stmt);
	if(result != SQLITE_OK)
	{
		cout << sqlite3_errmsg(db) << endl;
		return result;
	}
	return SQLITE_OK;
}

int altaTarjeta (sqlite3 *db, int numeroTarjeta, int PIN, int saldo)
{
	sqlite3_stmt *stmt;

	stringstream ss;
	ss << "INSERT INTO TARJETAS (numeroTarjeta, PIN, saldo) values (" << numeroTarjeta << ",'" << PIN << ",'" << saldo <<")";
	string ssql = ss.str();
	char* sql = new char [ssql.length () +1];
	strcpy(sql, ssql.c_str());

	int result = sqlite3_prepare_v2(db,sql,-1,&stmt, NULL);
	if (result != SQLITE_OK)
	{
		cout << sqlite3_errmsg(db) << endl;
		return result;
	} 
	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE)
	{
		cout << "ERROR. El numero de tarjeta ya se ha registrado" << endl;
		return result;
	}
	result = sqlite3_finalize (stmt);
	if(result != SQLITE_OK)
	{
		cout << sqlite3_errmsg(db) << endl;
		return result;
	}
	return SQLITE_OK;
}

//COMO HACER VALIDACION DE PIN; ¿SE HARÍA AQUÍ?

int altaMovimiento (sqlite3 *db, int numeroTarjeta1, int numeroTarjeta2, string tipoMovimiento, int cantidad)
{
	sqlite3_stmt *stmt;

	stringstream ss;
	ss << "INSERT INTO MOVIMIENTOS (numeroTarjeta1, numeroTarjeta2, tipoMovimiento, cantidad) values (" << numeroTarjeta1 << ",'" << numeroTarjeta2 << ",'" << tipoMovimiento << ",'" << cantidad << ")";
	string ssql = ss.str();
	char* sql = new char [ssql.length() +1];
	strcpy(sql, ssql.c_str());

	/*CREO QUE EN ESTE CASO NO HAY QUE HACER NINGUNA COMPROBACIÓN, POR LO QUE ESTO SOBRA
	int result = sqlite3_prepare_v2(db,sql,-1,&stmt, NULL);
	if (result != SQLITE_OK)
	{
		cout << sqlite3_errmsg(db) << endl;
		return result;
	} 

	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE)
	{
		cout << "ERROR. El DNI ya se ha registrado" endl;
		return result;
	}
	
	result = sqlite3_finalize (stmt);
	if(result != SQLITE_OK)
	{
		cout << sqlite3_errmsg(db) << endl;
		return result;
	}
	return SQLITE_OK;
	*/
}


