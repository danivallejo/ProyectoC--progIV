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
    //int result = sqlite3_open("test.sqlite", &db);
    int result = sqlite3_open(dbFile.c_str(), &db);
    //Si la BD no se ha podido abrir, muestra un mensaje
    if (result != SQLITE_OK)
    {
      // cout << "Error opening database" << endl;
    }
  }

 DBConnector::~DBConnector() 
  {
    int result = sqlite3_close(db);
    if (result != SQLITE_OK)
    {
       // cout << "Error closing database" <<  endl;
       // cout << sqlite3_errmsg(db) <<  endl;
    }	
  }

  //CREATE TABLE:
  int DBConnector::create_table_Usuarios () 
  {
  	char existe[] = "SELECT name FROM sqlite_master WHERE type='table' AND  name = 'Usuarios'"; //SELECT para que solo cree la tabla si no existía
  	sqlite3_stmt *stmt_ex; 
  	int result;
  	int creada = sqlite3_prepare_v2(db, existe, -1, &stmt_ex, NULL);
  	creada = sqlite3_step(stmt_ex);//no va
  	
  	if(creada != 100)//Da 100 cuando la tabla existe y 101 cuando no (en realidad no sé por qué, pero funciona)
  	{
	  	 sqlite3_stmt *stmt; 
	  	 char sql[] = "CREATE TABLE Usuarios("
	  	 				"DNI int primary key not null,"
	  	 				"NOMBRE text not null,"
	  	 				"APELLIDO text not null,"
	  	 				"EMAIL text not null);";

	  	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	  	if (result != SQLITE_OK)//Para continuar, el resultado debe ser SQLITE_OK, cualquier otro resultado será un error por no haberse procesado la select
	    {
	       // cout << "Error Creating table Jugadores" <<  endl;   
	      sqlite3_finalize(stmt);   
	       // cout << sqlite3_errmsg(db) <<  endl; //Devuelve el error interno de la BBDD (db) como resultado de la última operación sobre ella.
	    }
		
		result = sqlite3_step(stmt);
	    
	    result = sqlite3_finalize(stmt);
	    if (result != SQLITE_OK) 
	    {
	       // cout << "Error finalizing statement (CREATE)" <<  endl;
	       // cout << sqlite3_errmsg(db) <<  endl;
	    }
	}
	else
	{
		 // cout << "LA TABLA EXISTE, creada = " << creada <<  endl;
		result = SQLITE_OK;
	}
	//--Finalizar el statement stmt_ex
  	result = sqlite3_finalize(stmt_ex);
    if (result != SQLITE_OK) 
    {
       // cout << "Error finalizing statement" <<  endl;
       // cout << sqlite3_errmsg(db) <<  endl;
    }
    //---
	return result;
  }

 int DBConnector::create_table_Tarjetas () 
  {
  	char existe[] = "SELECT name FROM sqlite_master WHERE type='table' AND  name = 'Tarjetas'"; //SELECT para que solo cree la tabla si no existía
  	sqlite3_stmt *stmt_ex; 
  	int result;
  	int creada = sqlite3_prepare_v2(db, existe, -1, &stmt_ex, NULL);
  	creada = sqlite3_step(stmt_ex);//no va
  	
  	if(creada != 100)//Da 100 cuando la tabla existe y 101 cuando no (en realidad no sé por qué, pero funciona)
  	{
	  	 sqlite3_stmt *stmt; 
	  	 char sql[] = "CREATE TABLE Tarjetas("
	  	 				"NUMEROTARJETA int primary key not null,"
	  	 				"PIN int not null,"
	  	 				"SALDO int not null);";

	  	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	  	if (result != SQLITE_OK)//Para continuar, el resultado debe ser SQLITE_OK, cualquier otro resultado será un error por no haberse procesado la select
	    {
	       // cout << "Error Creating table Jugadores" <<  endl;   
	      sqlite3_finalize(stmt);   
	       // cout << sqlite3_errmsg(db) <<  endl; //Devuelve el error interno de la BBDD (db) como resultado de la última operación sobre ella.
	    }
		
		result = sqlite3_step(stmt);
	    
	    result = sqlite3_finalize(stmt);
	    if (result != SQLITE_OK) 
	    {
	       // cout << "Error finalizing statement (CREATE)" <<  endl;
	       // cout << sqlite3_errmsg(db) <<  endl;
	    }
	}
	else
	{
		 // cout << "LA TABLA EXISTE, creada = " << creada <<  endl;
		result = SQLITE_OK;
	}
	//--Finalizar el statement stmt_ex
  	result = sqlite3_finalize(stmt_ex);
    if (result != SQLITE_OK) 
    {
       // cout << "Error finalizing statement" <<  endl;
       // cout << sqlite3_errmsg(db) <<  endl;
    }
    //---
	return result;
  }

 int DBConnector::create_table_Movimientos () 
  {
  	char existe[] = "SELECT name FROM sqlite_master WHERE type='table' AND  name = 'Movimientos'"; //SELECT para que solo cree la tabla si no existía
  	sqlite3_stmt *stmt_ex; 
  	int result;
  	int creada = sqlite3_prepare_v2(db, existe, -1, &stmt_ex, NULL);
  	creada = sqlite3_step(stmt_ex);//no va
  	
  	if(creada != 100)//Da 100 cuando la tabla existe y 101 cuando no (en realidad no sé por qué, pero funciona)
  	{
	  	 sqlite3_stmt *stmt; 
	  	 char sql[] = "CREATE TABLE Movimientos("
	  	 				"NUMEROTARJETA int primary key not null,"
	  	 				"TIPOMOVIMIENTO text not null,"
	  	 				"CANTIDAD int not null);";

	  	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	  	if (result != SQLITE_OK)//Para continuar, el resultado debe ser SQLITE_OK, cualquier otro resultado será un error por no haberse procesado la select
	    {
	       // cout << "Error Creating table Jugadores" <<  endl;   
	      sqlite3_finalize(stmt);   
	       // cout << sqlite3_errmsg(db) <<  endl; //Devuelve el error interno de la BBDD (db) como resultado de la última operación sobre ella.
	    }
		
		result = sqlite3_step(stmt);
	    
	    result = sqlite3_finalize(stmt);
	    if (result != SQLITE_OK) 
	    {
	       // cout << "Error finalizing statement (CREATE)" <<  endl;
	       // cout << sqlite3_errmsg(db) <<  endl;
	    }
	}
	else
	{
		 // cout << "LA TABLA EXISTE, creada = " << creada <<  endl;
		result = SQLITE_OK;
	}
	//--Finalizar el statement stmt_ex
  	result = sqlite3_finalize(stmt_ex);
    if (result != SQLITE_OK) 
    {
       // cout << "Error finalizing statement" <<  endl;
       // cout << sqlite3_errmsg(db) <<  endl;
    }
    //---
	return result;
  }

int DBConnector::create_table_Transferencias () 
  {
  	char existe[] = "SELECT name FROM sqlite_master WHERE type='table' AND  name = 'Transferencias'"; //SELECT para que solo cree la tabla si no existía
  	sqlite3_stmt *stmt_ex; 
  	int result;
  	int creada = sqlite3_prepare_v2(db, existe, -1, &stmt_ex, NULL);
  	creada = sqlite3_step(stmt_ex);//no va
  	
  	if(creada != 100)//Da 100 cuando la tabla existe y 101 cuando no (en realidad no sé por qué, pero funciona)
  	{
	  	 sqlite3_stmt *stmt; 
	  	 char sql[] = "CREATE TABLE Transferencias("
	  	 				"NUMEROTARJETA1 int primary key not null,"
	  	 				"NUMEROTARJETA2 int primary key not null,"
	  	 				"CANTIDAD int not null);";

	  	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	  	if (result != SQLITE_OK)//Para continuar, el resultado debe ser SQLITE_OK, cualquier otro resultado será un error por no haberse procesado la select
	    {
	       // cout << "Error Creating table Jugadores" <<  endl;   
	      sqlite3_finalize(stmt);   
	       // cout << sqlite3_errmsg(db) <<  endl; //Devuelve el error interno de la BBDD (db) como resultado de la última operación sobre ella.
	    }
		
		result = sqlite3_step(stmt);
	    
	    result = sqlite3_finalize(stmt);
	    if (result != SQLITE_OK) 
	    {
	       // cout << "Error finalizing statement (CREATE)" <<  endl;
	       // cout << sqlite3_errmsg(db) <<  endl;
	    }
	}
	else
	{
		 // cout << "LA TABLA EXISTE, creada = " << creada <<  endl;
		result = SQLITE_OK;
	}
	//--Finalizar el statement stmt_ex
  	result = sqlite3_finalize(stmt_ex);
    if (result != SQLITE_OK) 
    {
       // cout << "Error finalizing statement" <<  endl;
       // cout << sqlite3_errmsg(db) <<  endl;
    }
    //---
	return result;
  }
  
//Para INSERT, UPDATE y DELETE, ver si el jugador existe:

int DBConnector::Usuario_existe(Usuarios user)
  {
  	vector<Usuarios> Usuarios;

  	leer_Usuarios(Usuarios);

  	for(int i=0; i<Usuarios.size(); i++)
  	{
  		if(user.getDNI() == Usuarios[i].getDNI())
  			return 1;
  	}

  	return 0;
  }

int DBConnector::Tarjeta_existe(Tarjeta card)
  {
  	vector<Tarjeta> Tarjetas;

  	leer_Tarjetas(Tarjeta);

  	for(int i=0; i<Tarjetas.size(); i++)
  	{
  		if(card.getNumTarjeta() == Usuarios[i].getNumTarjeta())
  			return 1;
  	}

  	return 0;
  }

  //INSERT:
  int DBConnector::insert_Usuario (Usuarios usuarioInsertar)
  {
  	if(Usuario_existe(usuarioInsertar) == 0)
  	{ //el jugador no existe, lo podemos insertar
	  	sqlite3_stmt *stmt;
	  	char sql[] = "insert into Usuarios (DNI, NOMBRE, APELLIDO, EMAIL) values (?, ?, ?, ?)";
	    
	    int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
	    if (result != SQLITE_OK) 
	    {
	       // cout << "Error preparing statement (INSERT)" <<  endl;
	       // cout << sqlite3_errmsg(db) <<  endl;
	      return result;
	    }


	   	int DNI = usuarioInsertar.getDNI();

	   	result = sqlite3_bind_int(stmt, 1, DNI);

	   	if​ (result != SQLITE_OK)
	   	{
	   		cout << "Error binding parameters" << endl;
	   		cout << sqlite3_errmsg(db) << endl;
	   		sqlite3_finalize(stmt);
	   		return​ result;
	   	}

	    string nombre= usuarioInsertar.getNombre();
	    //Le pasamos el nick al statement
	    result = sqlite3_bind_text(stmt, 2, nick.c_str(), nick.length(), SQLITE_STATIC);

	    if (result != SQLITE_OK)
	    {
	       // cout << "Error binding parameters" <<  endl;
	       // cout << sqlite3_errmsg(db) <<  endl;
	      sqlite3_finalize(stmt);
	      return result;
	    }

	    string apellido= usuarioInsertar.getApellido();
	    //Le pasamos el nick al statement
	    result = sqlite3_bind_text(stmt, 1, nick.c_str(), nick.length(), SQLITE_STATIC);

	    if (result != SQLITE_OK)
	    {
	       // cout << "Error binding parameters" <<  endl;
	       // cout << sqlite3_errmsg(db) <<  endl;
	      sqlite3_finalize(stmt);
	      return result;
	    }


	    string email= usuarioInsertar.getEmail();
	    //Le pasamos el nick al statement
	    result = sqlite3_bind_text(stmt, 1, nick.c_str(), nick.length(), SQLITE_STATIC);

	    if (result != SQLITE_OK)
	    {
	       // cout << "Error binding parameters" <<  endl;
	       // cout << sqlite3_errmsg(db) <<  endl;
	      sqlite3_finalize(stmt);
	      return result;
	    }
	    //Ejecutamos el INSERT
	    result = sqlite3_step(stmt);
	    if (result != SQLITE_DONE) 
	    {
	       // cout << "Error inserting new data into Jugadores table" <<  endl;
	      sqlite3_finalize(stmt);
	      return result;
	    }

	    result = sqlite3_finalize(stmt);
	    if (result != SQLITE_OK) 
	    {
	       // cout << "Error finalizing statement (INSERT)" <<  endl;
	       // cout << sqlite3_errmsg(db) <<  endl;
	    }
		return result;
	}
	else
	{
		 // cout << "El jugador ya existe - si quieres cambiar algo, UPDATE" <<  endl;	
		return 0;	
	}
}

  int DBConnector::insert_Tarjeta (Tarjeta tarjetaInsertar)
  {
  	if(Tarjeta_existe(tarjetaInsertar) == 0)
  	{ //el jugador no existe, lo podemos insertar
	  	sqlite3_stmt *stmt;
	  	char sql[] = "insert into Tarjetas (NUMEROTARJETA, PIN, SALDO) values (?, ?, 0)";
	    
	    int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
	    if (result != SQLITE_OK) 
	    {
	       // cout << "Error preparing statement (INSERT)" <<  endl;
	       // cout << sqlite3_errmsg(db) <<  endl;
	      return result;
	    }

	   	int NUMEROTARJETA = tarjetaInsertar.getNumTarjeta();

	   	result = sqlite3_bind_int(stmt, 1, NUMEROTARJETA);

	   	if​ (result != SQLITE_OK)
	   	{
	   		cout << "Error binding parameters" << endl;
	   		cout << sqlite3_errmsg(db) << endl;
			sqlite3_finalize(stmt);
	   		return​ result;
	   	}

		int PIN = tarjetaInsertar.getPIN();

	   	result = sqlite3_bind_int(stmt, 2, PIN);

	   	if​ (result != SQLITE_OK)
	   	{
	   		cout << "Error binding parameters" << endl;
	   		cout << sqlite3_errmsg(db) << endl;
	   		sqlite3_finalize(stmt);
	   		return​ result;
	   	}

	    //Ejecutamos el INSERT
	    result = sqlite3_step(stmt);
	    if (result != SQLITE_DONE) 
	    {
	       // cout << "Error inserting new data into Jugadores table" <<  endl;
	      sqlite3_finalize(stmt);
	      return result;
	    }

	    result = sqlite3_finalize(stmt);
	    if (result != SQLITE_OK) 
	    {
	       // cout << "Error finalizing statement (INSERT)" <<  endl;
	       // cout << sqlite3_errmsg(db) <<  endl;
	    }
		return result;
	}
	else
	{
		 // cout << "El jugador ya existe - si quieres cambiar algo, UPDATE" <<  endl;	
		return 0;	
	}
}

int DBConnector::insert_Movimientos (Movimiento movimientoInsertar)
{
  	sqlite3_stmt *stmt;
	char sql[] = "insert into Movimientos (NUMEROTARJETA, TIPOMOVIMIENTO, CANTIDAD) values (?, ?, ?)";

 	int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
	if (result != SQLITE_OK) 
	{
		return result;
	}

	int NUMEROTARJETA = movimientoInsertar.getNumTarjeta();

	result = sqlite3_bind_int(stmt, 1, NUMEROTARJETA);
	
	if​ (result != SQLITE_OK)
	{
		cout << "Error binding parameters" << endl;
		cout << sqlite3_errmsg(db) << endl;
		sqlite3_finalize(stmt);
		return​ result;
	}

	string TIPOMOVIMIENTO= movimientoInsertar.getTIPOMOVIMIENTO();
	//Le pasamos el nick al statement
	result = sqlite3_bind_text(stmt, 1, nick.c_str(), nick.length(), SQLITE_STATIC);

	if (result != SQLITE_OK)
	{
	// cout << "Error binding parameters" <<  endl;
	// cout << sqlite3_errmsg(db) <<  endl;
	sqlite3_finalize(stmt);
	return result;
	}
		
	int CANTIDAD = movimientoInsertar.getCantidad();

	result = sqlite3_bind_int(stmt, 3, PIN);

	if​ (result != SQLITE_OK)
	{
		cout << "Error binding parameters" << endl;
		cout << sqlite3_errmsg(db) << endl;
		sqlite3_finalize(stmt);
		return​ result;
	}
	
	//Ejecutamos el INSERT
	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) 
	{
		sqlite3_finalize(stmt);
		return result;
	}
	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) 
	{
	// cout << "Error finalizing statement (INSERT)" <<  endl;
	// cout << sqlite3_errmsg(db) <<  endl;
	}
	return result;
}

int DBConnector::insert_Transferencia (Transferencia transferenciaInsertar)
{
	sqlite3_stmt *stmt;
	char sql[] = "insert into Transferencias (NUMEROTARJETA1, NUMEROTARJETA2, CANTIDAD) values (?, ?, ?)";
	
	int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
	if (result != SQLITE_OK) 
	{
		// cout << "Error preparing statement (INSERT)" <<  endl;
		// cout << sqlite3_errmsg(db) <<  endl;
		return result;
	}

	int NUMEROTARJETA1 = transferenciaInsertar.getNumTarjeta1();

	result = sqlite3_bind_int(stmt, 1, NUMEROTARJETA1);

	if​ (result != SQLITE_OK)
	{
		cout << "Error binding parameters" << endl;
		cout << sqlite3_errmsg(db) << endl;
		sqlite3_finalize(stmt);
		return​ result;
	}

	int NUMEROTARJETA2 = transferenciaInsertar.getNumTarjeta2();

	result = sqlite3_bind_int(stmt, 2, NUMEROTARJETA2);

	if​ (result != SQLITE_OK)
	{
		cout << "Error binding parameters" << endl;
		cout << sqlite3_errmsg(db) << endl;
		sqlite3_finalize(stmt);
		return​ result;
	}


	int CANTIDAD = tarjetaInsertar.getCantidad();

	result = sqlite3_bind_int(stmt, 3, Cantidad);

	if​ (result != SQLITE_OK)
	{
		cout << "Error binding parameters" << endl;
		cout << sqlite3_errmsg(db) << endl;
		sqlite3_finalize(stmt);
		return​ result;
	}
	
	//Ejecutamos el INSERT
	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) 
	{
	// cout << "Error inserting new data into Jugadores table" <<  endl;
	sqlite3_finalize(stmt);
	return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) 
	{
		// cout << "Error finalizing statement (INSERT)" <<  endl;
		// cout << sqlite3_errmsg(db) <<  endl;
	}
	return result;
}
//UPDATE:
int DBConnector::update_Tarjeta(tarjeta tarjetaModificar)//Pasar el jugador completo
{
	sqlite3_stmt *stmt;
	char sql[] = "update Tarjetas set SALDO = ? where NUMEROTARJETA = ?";
	int numeroTarjeta = tarjetaModificar.getNumTarjeta();
	int saldo = tarjetaModificar.getSaldo();
	//Preparar el statement:
	int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
	if (result != SQLITE_OK) 
	{
		// cout << "Error preparing statement (INSERT)" <<  endl;
		// cout << sqlite3_errmsg(db) <<  endl;
		return result;
	}

	//Juntar los parámetros con el statement
	//Le pasamos el puntuacion al statement
	result = sqlite3_bind_int(stmt, 1, saldo);
    if (result != SQLITE_OK)
	{
		// cout << "Error binding parameters" <<  endl;
		sqlite3_finalize(stmt);
		// cout << sqlite3_errmsg(db) <<  endl;
		return result;
	}
	//Le pasamos el nick al statement
	result = sqlite3_bind_int(stmt, 2, numeroTarjeta)

	if (result != SQLITE_OK)
	{
    	// cout << "Error binding parameters" <<  endl;
		sqlite3_finalize(stmt);
		// cout << sqlite3_errmsg(db) <<  endl;
		return result;
	}

	//Ejecutamos el UPDATE
	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) 
	{
		// cout << "Error inserting new data into Jufgadores table" <<  endl;
		sqlite3_finalize(stmt);
		return result;
	}

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) 
	{
		// cout << "Error finalizing statement (UPDATE)" <<  endl;
		// cout << sqlite3_errmsg(db) <<  endl;
	}
		return result;
	}

//SELECT
int DBConnector::leer_Usuarios(vector <Usuario>& listaTodosUsuarios)
{
	//int cont = 0;
	sqlite3_stmt *stmt; 
	char sql[] = "select DNI, NOMBRE, APELLIDO, EMAIL from Usuarios";
   
    int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
    if (result != SQLITE_OK)
    {
      return result;
    }

    //Variables en las que recogeremos los atributos de cada jugador
    int DNI;
  	char nombre[200];
  	char apellido[200];
  	char email[200];

    do
    {
      result = sqlite3_step(stmt);
      if (result == SQLITE_ROW) 
      {
      	//Leer el nick y la puntuacion de la linea del SELECT
      	DNI = sqlite3_column_int(stmt, 0);
      	strcpy(nombre, (char*)sqlite3_column_text(stmt, 1));
      	strcpy(apellido, (char*)sqlite3_column_text(stmt, 2));
      	strcpy(email, (char*)sqlite3_column_text(stmt, 3));
  
      	//Crear un jugador con esos atributos
      	Usuario user (DNI, nombre, apellido, email);
    	
    	listaTodosUsuarios.push_back (user);
      	// listaTodosJugadores[cont] = jugador;
      	// cont++;
      }
    } while (result == SQLITE_ROW);

    result = sqlite3_finalize(stmt);
    if (result != SQLITE_OK) 
    {
      return result;
    }
    return SQLITE_OK;
}

int DBConnector::leer_Tarjetas(vector <Tarjeta>& listaTodasTarjetas)
{
	//int cont = 0;
	sqlite3_stmt *stmt; 
	char sql[] = "select NUMEROTARJETA, PIN, SALDO from Tarjetas";
   
    int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
    if (result != SQLITE_OK)
    {
      return result;
    }

    //Variables en las que recogeremos los atributos de cada jugador
    int numeroTarjeta;
  	int PIN;
  	int Saldo;

    do
    {
      result = sqlite3_step(stmt);
      if (result == SQLITE_ROW) 
      {
      	//Leer el nick y la puntuacion de la linea del SELECT
      	numeroTarjeta = sqlite3_column_int(stmt, 0);
      	PIN = sqlite3_column_int(stmt, 1);
      	Saldo = sqlite3_column_int(stmt, 2);
  
      	//Crear un jugador con esos atributos
      	Tarjeta card (numeroTarjeta, PIN, Saldo);
    	
    	listaTodasTarjetas.push_back (card);
      	// listaTodosJugadores[cont] = jugador;
      	// cont++;
      }
    } while (result == SQLITE_ROW);

    result = sqlite3_finalize(stmt);
    if (result != SQLITE_OK) 
    {
      return result;
    }
    return SQLITE_OK;
}

int DBConnector::leer_Movimientos(vector <Movimientos>& listaTodosMovimientos)
{
	//int cont = 0;
	sqlite3_stmt *stmt; 
	char sql[] = "select NUMEROTARJETA, TIPOMOVIMIENTO, CANTIDAD from Movimientos";
   
    int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
    if (result != SQLITE_OK)
    {
      return result;
    }

    //Variables en las que recogeremos los atributos de cada jugador
    int numeroTarjeta;
  	char[200] tipoMovimiento;
  	int Cantidad;

    do
    {
      result = sqlite3_step(stmt);
      if (result == SQLITE_ROW) 
      {
      	//Leer el nick y la puntuacion de la linea del SELECT
      	numeroTarjeta = sqlite3_column_int(stmt, 0);
      	strcpy(tipoMovimiento, (char*)sqlite3_column_text(stmt, 1));
    	Cantidad = sqlite3_column_int(stmt, 2);
  
      	//Crear un jugador con esos atributos
      	Movimiento mov (numeroTarjeta, tipoMovimiento, Cantidad);
    	
    	listaTodosMovimientos.push_back (mov);
      	// listaTodosJugadores[cont] = jugador;
      	// cont++;
      }
    } while (result == SQLITE_ROW);

    result = sqlite3_finalize(stmt);
    if (result != SQLITE_OK) 
    {
      return result;
    }
    return SQLITE_OK;
}

int DBConnector::leer_Transferencias(vector <Transferencia>& listaTodasTransferencias)
{
	//int cont = 0;
	sqlite3_stmt *stmt; 
	char sql[] = "select NUMEROTARJETA1, NUMEROTARJETA2, CANTIDAD from Transferencias";
   
    int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
    if (result != SQLITE_OK)
    {
      return result;
    }

    //Variables en las que recogeremos los atributos de cada jugador
    int numeroTarjeta1;
  	int numeroTarjeta2;
  	int Cantidad;

    do
    {
      result = sqlite3_step(stmt);
      if (result == SQLITE_ROW) 
      {
      	//Leer el nick y la puntuacion de la linea del SELECT
      	numeroTarjeta1 = sqlite3_column_int(stmt, 0);
      	numeroTarjeta2 = sqlite3_column_int(stmt, 1);
      	Cantidad = sqlite3_column_int(stmt, 2);
  
      	//Crear un jugador con esos atributos
      	Transferencia transfer (numeroTarjeta1, numeroTarjeta2, Cantidad);
    	
    	listaTodasTransferencias.push_back (transfer);
      	// listaTodosJugadores[cont] = jugador;
      	// cont++;
      }
    } while (result == SQLITE_ROW);

    result = sqlite3_finalize(stmt);
    if (result != SQLITE_OK) 
    {
      return result;
    }
    return SQLITE_OK;
}

