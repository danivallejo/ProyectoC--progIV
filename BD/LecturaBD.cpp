#include "LecturaBD.h"
#include "../LN/Usuarios.h"
#include "../LN/Movimientos.h"
#include "../LN/Tarjeta.h"
#include "../LN/Transferencia.h"
#include "sqlite3.h"
#include <fstream>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <iostream>
#include <vector>

using namespace std;

vector <Usuarios> getUsuarios (sqlite3 *db)
{
	sqlite3_stmt *stmt;

	char sql[] = "SELECT DNI, NOMBRE, APELLIDO, EMAIL FROM USUARIOS";
	int result = sqlite3_prepare_v2 (db, sql, -1, &stmt, NULL);
	if (result != SQLITE_OK)
		cout << sqlite3_errmsg(db) << endl;

	vector <Usuarios> vectorUsuarios;
	int DNI;
	char str[100];

	do
	{
		result = sqlite3_step(stmt);
		if (result == SQLITE_ROW) 
		{
			DNI = sqlite3_column_int(stmt, 0);
			strcpy(str, (char *) sqlite3_column_text(stmt, 1));
			string nombre (str);
			strcpy(str, (char *) sqlite3_column_text(stmt, 2));
			string apellido (str);
			strcpy(str, (char *) sqlite3_column_text(stmt, 3));
			string email (str);

			Usuarios a (DNI,nombre,apellido,email);
			vectorUsuarios.push_back(a);
		}
	}while (result == SQLITE_ROW);

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) 
		cout << sqlite3_errmsg(db) << endl;

	return vectorUsuarios;
}

vector <Tarjeta> getTarjetas (sqlite3 *db)
{
	sqlite3_stmt *stmt;

	char sql[] = "SELECT NUMTARJETA, PIN, SALDO FROM TARJETAS";
	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) 
		cout << sqlite3_errmsg(db) << endl;

	vector <Tarjeta> vectorTarjetas;
	int numtarjeta, pin, saldo;

	do
	{
		result = sqlite3_step(stmt);
		if (result == SQLITE_ROW) 
		{
			numtarjeta = sqlite3_column_int(stmt, 0);
			pin = sqlite3_column_int(stmt, 1);
			saldo = sqlite3_column_int(stmt, 2);

			Tarjeta a (numtarjeta, pin, saldo);
			vectorTarjetas.push_back(a);
		}	
	}while (result == SQLITE_ROW);

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) 
		cout << sqlite3_errmsg(db) << endl;

	return vectorTarjetas;
}

vector <Movimientos> getMovimientos (sqlite3 *db)
{
	sqlite3_stmt *stmt;

	char sql[] = "SELECT NUMTARJETA1, TIPOMOVIMIENTO, CANTIDAD FROM MOVIMIENTOS";
	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	if (result != SQLITE_OK) 
		cout << sqlite3_errmsg(db) << endl;

	vector<Movimientos> vectorMovimientos;
	int numtarjeta1, cantidad;
	char str [100];

	do
	{
		result = sqlite3_step(stmt);
		if (result == SQLITE_ROW) 
		{
			numtarjeta1 = sqlite3_column_int (stmt, 0);
			strcpy(str, (char *) sqlite3_column_text(stmt, 1));
			string tipomovimiento (str);
			cantidad = sqlite3_column_int (stmt, 2);
			
			Movimientos a (numtarjeta1,tipomovimiento,cantidad);
			vectorMovimientos.push_back(a);
		}
	}while (result == SQLITE_ROW);

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) 
		cout << sqlite3_errmsg(db) << endl;

	return vectorMovimientos;
}

vector <Transferencia> getTransferencias (sqlite3 *db)
{
	sqlite3_stmt *stmt;

	char sql[] = "SELECT NUMTARJETA1, NUMTARJETA2, CANTIDAD FROM TRANSFERENCIA";
	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
	if (result != SQLITE_OK) 
		cout << sqlite3_errmsg(db) << endl;

	vector<Transferencia> vectorTransferencia;
	int numtarjeta1, numtarjeta2, cantidad;

	do
	{
		result = sqlite3_step(stmt);
		if (result == SQLITE_ROW) 
		{
			numtarjeta1 = sqlite3_column_int (stmt, 0);
			numtarjeta2 = sqlite3_column_int (stmt, 1);
			cantidad = sqlite3_column_int (stmt, 3);
			
			Transferencia a (numtarjeta1,numtarjeta2,cantidad);
			vectorTransferencia.push_back(a);
		}
	}while (result == SQLITE_ROW);

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) 
		cout << sqlite3_errmsg(db) << endl;

	return vectorTransferencia;
}

