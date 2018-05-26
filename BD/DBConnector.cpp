#include "sqlite3.h"
#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
#include "../LN/Usuarios.h"
#include "../LN/Movimientos.h"
#include "../LN/Tarjeta.h"
#include "../LN/Transferencia.h"

#include "DBConnector.h"

using namespace std;

DBConnector::DBConnector(string dbFile)
{
	int​ result = sqlite3_open(dbFile.c_str(), &db);
	if​ (result != SQLITE_OK)
	{
		cout << "Error opening database" << endl;
	}
}

DBConnector::~DBConnector()

{
	int​ result = sqlite3_close(db);
	if​ (result != SQLITE_OK)
	{
		cout << "Error closing database" << endl;
		cout << sqlite3_errmsg(db) << endl;
	}
}

//CREATE TABLE:

int​ DBConnector::altaUsuario (sqlite3 *db, int DNI, string nombre, string apellido, string email)
{
	char​ existe[] = "SELECT name FROM sqlite_master WHERE type='table' AND
	name = '----NOM_TABLA----'"; //SELECT para que solo cree la tabla si no existía
	sqlite3_stmt *stmt_ex;
	int​ result;
	int​ creada = sqlite3_prepare_v2(db, existe, -1, &stmt_ex, NULL);
	creada = sqlite3_step(stmt_ex);//no va
	if​(creada != 100)//Da 100 cuando la tabla existe y 101 cuando no (en realidad no sé por qué, pero funciona)
	{
		sqlite3_stmt *stmt;
		char​ sql[] = "CREATE TABLE ----NOM_TABLA----("

		"----Atributo1---- text primary key not

		null,"

"----Atributo2----- int not null);";

//Cambiar esto según el objeto
int​ result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
if​ (result != SQLITE_OK)//Para continuar, el resultado debe ser
SQLITE_OK, cualquier otro resultado será un error por no haberse procesado la
select
{
cout << "Error Creating table ----NOM_TABLA----" << endl;
sqlite3_finalize(stmt);

cout << sqlite3_errmsg(db) << endl; //Devuelve el error interno de

la BBDD (db) como resultado de la última operación sobre ella.

}
result = sqlite3_step(stmt);
result = sqlite3_finalize(stmt);
if​ (result != SQLITE_OK)
{
cout << "Error finalizing statement (CREATE)" << endl;
cout << sqlite3_errmsg(db) << endl;
}
}
else
{
//LA TABLA EXISTE
result = SQLITE_OK;
}
//--Finalizar el statement stmt_ex
result = sqlite3_finalize(stmt_ex);
if​ (result != SQLITE_OK)
{
cout << "Error finalizing statement" << endl;
cout << sqlite3_errmsg(db) << endl;
}
//---
return​ result;
}

//INSERT:
int​ DBConnector::insert_XX (tipo insertar)
{

sqlite3_stmt *stmt;
char​ sql[] = "insert into ----NOM_TABLA---- (Nom_atributos) values

(?, ?,....)";
//char sql[] = "insert into Jugadores (NICK, PUNTUACION) values (?, 0)";

int​ result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;

if​ (result != SQLITE_OK)
{
cout << "Error preparing statement (INSERT)" << endl;
cout << sqlite3_errmsg(db) << endl;
return​ result;
}

//SI HAY QUE INSERTAR STRING
string texto= insertar.getXX();
// string nick= jugadorInsertar.getNick();
//Le pasamos el nick al statement
result = sqlite3_bind_text(stmt, 1, texto.c_str(), texto.length(), SQLITE_STATIC);
// result = sqlite3_bind_text(stmt, 1, nick.c_str(), nick.length(), SQLITE_STATIC);

if​ (result != SQLITE_OK)
{
cout << "Error binding parameters" << endl;
cout << sqlite3_errmsg(db) << endl;
sqlite3_finalize(stmt);
return​ result;
}
//SI HAY QUE INSERTAR INT​:
int​ num= insertar.getXX();
//Le pasamos el nick al statement
result = sqlite3_bind_int(stmt, 2, num);
if​ (result != SQLITE_OK)
{
cout << "Error binding parameters" << endl;
cout << sqlite3_errmsg(db) << endl;
sqlite3_finalize(stmt);
return​ result;
}
if​ (result != SQLITE_OK)
{
cout << "Error binding parameters" << endl;
cout << sqlite3_errmsg(db) << endl;
sqlite3_finalize(stmt);
return​ result;
}
//Ejecutamos el INSERT
result = sqlite3_step(stmt);
if​ (result != SQLITE_DONE)
{
cout << "Error inserting new data into ----NOM_TABLA---- table" << endl;

sqlite3_finalize(stmt);
return​ result;

}
result = sqlite3_finalize(stmt);
if​ (result != SQLITE_OK)
{
cout << "Error finalizing statement (INSERT)" << endl;
cout << sqlite3_errmsg(db) << endl;
}
return​ result;

}
//UPDATE:
int​ DBConnector::update_XX(tipo modificar)
{

sqlite3_stmt *stmt;
char​ sql[] = "update ----NOM_TABLA---- set --atributo_cambiar-- = ? where --atributo_primario-- = ?";

string atributo_primario = modificar.getXX();
int​ num = modificar.getXX();

//char sql[] = "update Jugadores set PUNTUACION = ? where NICK = ?";

string nick = jugadorModificar.getNick();
int puntuacion = jugadorModificar.getPuntuacion();
//Preparar el statement:
int​ result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;

if​ (result != SQLITE_OK)
{
cout << "Error preparing statement (INSERT)" << endl;
cout << sqlite3_errmsg(db) << endl;
return​ result;
}
result = sqlite3_bind_int(stmt, 1, num);
if​ (result != SQLITE_OK)
{
cout << "Error binding parameters" << endl;
sqlite3_finalize(stmt);
cout << sqlite3_errmsg(db) << endl;
return​ result;
}
//Le pasamos el nick al statement
result = sqlite3_bind_text(stmt, 2, atributo_primario.c_str(),

atributo_primario.length(), SQLITE_STATIC);
if​ (result != SQLITE_OK)
{

cout << "Error binding parameters" << endl;
sqlite3_finalize(stmt);
cout << sqlite3_errmsg(db) << endl;
return​ result;
}
//Ejecutamos el UPDATE
result = sqlite3_step(stmt);
if​ (result != SQLITE_DONE)
{
cout << "Error inserting new data" << endl;
sqlite3_finalize(stmt);
return​ result;
}
result = sqlite3_finalize(stmt);
if​ (result != SQLITE_OK)
{
cout << "Error finalizing statement (UPDATE)" << endl;
cout << sqlite3_errmsg(db) << endl;
}
return​ result;

}
//DELETE:
int​ DBConnector::delete_XX(tipo borrar)
{

sqlite3_stmt *stmt;
char​ sql[] = "DELETE from ---NOM_TABLA--- where atributo_primario =

?";

string atributo_primario = borrar.getXX();
//Preparar el statement:
int​ result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;

if​ (result != SQLITE_OK)
{
cout << "Error preparing statement (INSERT)" << endl;
cout << sqlite3_errmsg(db) << endl;
return​ result;
}
//Juntar los parámetros con el statement
//Le pasamos el nick al statement
result = sqlite3_bind_text(stmt, 1, atributo_primario.c_str(),

atributo_primario.length(), SQLITE_STATIC);
if​ (result != SQLITE_OK)
{
cout << "Error binding parameters" << endl;
sqlite3_finalize(stmt);

cout << sqlite3_errmsg(db) << endl;
return​ result;
}
//Ejecutamos el DELETE
result = sqlite3_step(stmt);
if​ (result != SQLITE_DONE)
{
cout << "Error DELETING " << nick << endl;
sqlite3_finalize(stmt);
return​ result;
}
result = sqlite3_finalize(stmt);
if​ (result != SQLITE_OK)
{
cout << "Error finalizing statement (UPDATE)" << endl;
cout << sqlite3_errmsg(db) << endl;
}
return​ result;

}
//SELECT
int​ DBConnector::leer_XX(vector <tipo>& lista)
{
//int cont = 0;
sqlite3_stmt *stmt;
char​ sql[] = "select ---atributo1---, ----atributo2--- from
---NOM_TABLA---";
int​ result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
if​ (result != SQLITE_OK)
{
cout << "Error preparing statement (SELECT)" << endl;
cout << sqlite3_errmsg(db) << endl;
return​ result;
}
//Variables en las que recogeremos los atributos de cada jugador
int​ num;
char​ texto[200];
do
{
result = sqlite3_step(stmt);
if​ (result == SQLITE_ROW)
{
strcpy(texto, (char​*)sqlite3_column_text(stmt, 0));
num = sqlite3_column_int(stmt, 1);
//Crear un jugador con esos atributos

tipo t (texto, num);
listaTodosJugadores.push_back (jug);
// listaTodosJugadores[cont] = jugador;
// cont++;
}
} while​ (result == SQLITE_ROW);
result = sqlite3_finalize(stmt);
if​ (result != SQLITE_OK)
{
cout << "Error finalizing statement (SELECT)" << endl;
cout << sqlite3_errmsg(db) << endl;
return​ result;
}
return​ SQLITE_OK;
}
//DROP TABLE:
int​ DBConnector::drop_XX ()
{
sqlite3_stmt *stmt;
char​ sql[] = "DROP TABLE if exists ---NOM_TABLA";
int​ result = sqlite3_exec(db, sql, NULL, NULL, NULL);
if​ (result != SQLITE_DONE)
{
cout << "Error DROPING "<< endl;
sqlite3_finalize(stmt);
return​ result;
}
return​ result;
}
