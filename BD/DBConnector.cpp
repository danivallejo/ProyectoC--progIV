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

  //Creacion de la tabla Usuarios; atributos: DNI, NOMBRE, APELLIDO, EMAIL

  int DBConnector::create_table_Usuarios () 
  {
  	char existe[] = "SELECT name FROM sqlite_master WHERE type='table' AND  name = 'Usuarios'"; //SELECT para que solo cree la tabla si no existía
  	sqlite3_stmt *stmt_ex; 
  	int result;
  	int creada = sqlite3_prepare_v2(db, existe, -1, &stmt_ex, NULL);
  	creada = sqlite3_step(stmt_ex);
  	
  	if(creada != 100)
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
	    	//cout << "Error Creating table Usuarios" <<  endl;
	    	sqlite3_finalize(stmt);
	    	//cout << sqlite3_errmsg(db) <<  endl;
	    }
		
		result = sqlite3_step(stmt);
	    
	    result = sqlite3_finalize(stmt);
	    if (result != SQLITE_OK) 
	    {
	    	//cout << "Error finalizing statement (CREATE)" <<  endl;
	    	//cout << sqlite3_errmsg(db) <<  endl;
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

  //Creación de la tabla Tarjetas; atributos: NUMERO TARJETA, PIN Y SALDO

 int DBConnector::create_table_Tarjetas () 
  {
  	char existe[] = "SELECT name FROM sqlite_master WHERE type='table' AND  name = 'Tarjetas'";
  	sqlite3_stmt *stmt_ex; 
  	int result;
  	int creada = sqlite3_prepare_v2(db, existe, -1, &stmt_ex, NULL);
  	creada = sqlite3_step(stmt_ex);
  	
  	if(creada != 100)
  	{
	  	 sqlite3_stmt *stmt; 
	  	 char sql[] = "CREATE TABLE Tarjetas("
	  	 				"NUMEROTARJETA int primary key not null,"
	  	 				"PIN int not null,"
	  	 				"SALDO int not null );";

	  	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	  	if (result != SQLITE_OK)//Para continuar, el resultado debe ser SQLITE_OK, cualquier otro resultado será un error por no haberse procesado la select
	    {
	       // cout << "Error Creating table Tarjetas" <<  endl;   
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

  //Creacion de la tabla Movimientos; atributos: NUMERO TARJETA, TIPO MOVIMIENTO Y CANTIDAD
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

//Creacion de la tabla Transferencias; atributos: NUMERO TARJETA 1, NUMERO TARJETA 2 Y CANTIDAD 
int DBConnector::create_table_Transferencias () 
  {
  	char existe[] = "SELECT name FROM sqlite_master WHERE type='table' AND  name = 'Transferencias'";
  	sqlite3_stmt *stmt_ex; 
  	int result;
  	int creada = sqlite3_prepare_v2(db, existe, -1, &stmt_ex, NULL);
  	creada = sqlite3_step(stmt_ex);
  	
  	if(creada != 100)
  	{
	  	 sqlite3_stmt *stmt; 
	  	 char sql[] = "CREATE TABLE Transferencias("
	  	 				"NUMEROTARJETA1 int not null,"
	  	 				"NUMEROTARJETA2 int not null,"
	  	 				"CANTIDAD int not null,"
	  	 				"primary key (NUMEROTARJETA1, NUMEROTARJETA2));";

	  	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	  	if (result != SQLITE_OK)//Para continuar, el resultado debe ser SQLITE_OK, cualquier otro resultado será un error por no haberse procesado la select
	    {
	       // cout << "Error Creating table Transferencias" <<  endl;   
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
  
//Para INSERT y UPDATE ver si el usuario existe:

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

  //Para INSERT y UPDATE ver si la tarjeta existe

int DBConnector::Tarjeta_existe(Tarjeta card)
  {
  	vector<Tarjeta> Tarjetas;

  	leer_Tarjetas(Tarjetas);

  	for(int i=0; i<Tarjetas.size(); i++)
  	{
  		if(card.getnumTarjeta() == Tarjetas[i].getnumTarjeta())
  			return 1;
  	}

  	return 0;
  }

  //INSERT de usuario

  int DBConnector::insert_Usuario (Usuarios usuarioInsertar)
  {
  	if(Usuario_existe(usuarioInsertar) == 0)
  	{
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

	   	if(result != SQLITE_OK)
	   	{
	   		cout << "Error binding parameters" << endl;
	   		cout << sqlite3_errmsg(db) << endl;
	   		sqlite3_finalize(stmt);

	   		return result;

	   	}
	   	string nombre= usuarioInsertar.getnombre();
	    result = sqlite3_bind_text(stmt, 2, nombre.c_str(), nombre.length(), SQLITE_STATIC);

	    if (result != SQLITE_OK)
	    {
	        cout << "Error binding parameters" <<  endl;
	        cout << sqlite3_errmsg(db) <<  endl;
	      sqlite3_finalize(stmt);
	      return result;
	    }

	    string apellido= usuarioInsertar.getapellido();
	    result = sqlite3_bind_text(stmt, 3, apellido.c_str(), apellido.length(), SQLITE_STATIC);

	    if (result != SQLITE_OK)
	    {
	        cout << "Error binding parameters" <<  endl;
	        cout << sqlite3_errmsg(db) <<  endl;
	      sqlite3_finalize(stmt);
	      return result;
	    }


	    string email= usuarioInsertar.getemail();
	    result = sqlite3_bind_text(stmt, 4, email.c_str(), email.length(), SQLITE_STATIC);

	    if (result != SQLITE_OK)
	    {
	        cout << "Error binding parameters" <<  endl;
	        cout << sqlite3_errmsg(db) <<  endl;
	      sqlite3_finalize(stmt);
	      return result;
	    }
	    //Ejecutamos el INSERT
	    result = sqlite3_step(stmt);
	    if (result != SQLITE_DONE) 
	    {
	       // cout << "Error inserting new data into Usuarios table" <<  endl;
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
		 // cout << "El usuario ya existe - si quieres cambiar algo, UPDATE" <<  endl;	
		return 0;	
	}
}

// INSERT Tarjeta
  int DBConnector::insert_Tarjeta (Tarjeta tarjetaInsertar)
  {
  	if(Tarjeta_existe(tarjetaInsertar) == 0)
  	{ //la tarjeta no existe, la podemos insertar
	  	sqlite3_stmt *stmt;
	  	char sql[] = "insert into Tarjetas (NUMEROTARJETA, PIN, SALDO) values (?, ?, 0)";
	    
	    int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
	    if (result != SQLITE_OK) 
	    {
	       // cout << "Error preparing statement (INSERT)" <<  endl;
	       // cout << sqlite3_errmsg(db) <<  endl;
	      return result;
	    }
	   	int NUMEROTARJETA = tarjetaInsertar.getnumTarjeta();

	   	result = sqlite3_bind_int(stmt, 1, NUMEROTARJETA);
	   	if(result != SQLITE_OK)
	   	{
	   		cout << "Error binding parameters" << endl;
	   		cout << sqlite3_errmsg(db) << endl;
	   		sqlite3_finalize(stmt);
	   		
	   		return result;
	   	}
		int PIN = tarjetaInsertar.getPIN();

	   	result = sqlite3_bind_int(stmt, 2, PIN);

	   	if(result != SQLITE_OK)
	   	{
	   		cout << "Error binding parameters" << endl;
	   		cout << sqlite3_errmsg(db) << endl;
	   		sqlite3_finalize(stmt);
			return result;
	   	}
	   	/*
		int DNI = tarjetaInsertar.getDNIUsuario();

	   	result = sqlite3_bind_int(stmt, 4, DNI);

	   	if(result != SQLITE_OK)
	   	{
	   		cout << "Error binding parameters" << endl;
	   		cout << sqlite3_errmsg(db) << endl;
	   		sqlite3_finalize(stmt);
			return result;
	   	}
	   	*/
	    //Ejecutamos el INSERT
	    result = sqlite3_step(stmt);
	    if (result != SQLITE_DONE) 
	    {
	      cout << "Error inserting new data into Tarjetas table" <<  endl;
	      sqlite3_finalize(stmt);
	      return result;
	    }

	    result = sqlite3_finalize(stmt);
	    if (result != SQLITE_OK) 
	    {
	        cout << "Error finalizing statement (INSERT)" <<  endl;
	       	cout << sqlite3_errmsg(db) <<  endl;
	    }
		return result;
	}
	else
	{
		 // cout << "La tarjeta ya existe - si quieres cambiar algo, UPDATE" <<  endl;	
		return 0;	
	}
}

// INSERT Movimientos
int DBConnector::insert_Movimientos (Movimientos movimientoInsertar)
{
  	sqlite3_stmt *stmt;
	char sql[] = "insert into Movimientos (NUMEROTARJETA, TIPOMOVIMIENTO, CANTIDAD) values (?, ?, ?)";

 	int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
	if (result != SQLITE_OK) 
	{
		return result;
	}

	int NUMEROTARJETA = movimientoInsertar.getnumTarjeta();

	result = sqlite3_bind_int(stmt, 1, NUMEROTARJETA);

	if (result != SQLITE_OK) 
	{

		cout << "Error binding parameters" << endl;
		cout << sqlite3_errmsg(db) << endl;
		sqlite3_finalize(stmt);
		
		return result;
	}

	string TIPOMOVIMIENTO= movimientoInsertar.getTipoMovimiento();
	result = sqlite3_bind_text(stmt, 2, TIPOMOVIMIENTO.c_str(), TIPOMOVIMIENTO.length(), SQLITE_STATIC);

	if (result != SQLITE_OK)
	{
	// cout << "Error binding parameters" <<  endl;
	// cout << sqlite3_errmsg(db) <<  endl;
	sqlite3_finalize(stmt);
	return result;
	}
		
	int CANTIDAD = movimientoInsertar.getCantidad();

	result = sqlite3_bind_int(stmt, 3, CANTIDAD);

	if (result != SQLITE_OK) 
	{
		cout << "Error binding parameters" << endl;
		cout << sqlite3_errmsg(db) << endl;
		sqlite3_finalize(stmt);
	
		return result;
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

// INSERT Transferencias
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

	int NUMEROTARJETA1 = transferenciaInsertar.getnumTarjeta1();

	result = sqlite3_bind_int(stmt, 1, NUMEROTARJETA1);
	
	if (result != SQLITE_OK) 
	{
		cout << "Error binding parameters" << endl;
		cout << sqlite3_errmsg(db) << endl;
		sqlite3_finalize(stmt);

		return result;
	}

	int NUMEROTARJETA2 = transferenciaInsertar.getnumTarjeta2();

	result = sqlite3_bind_int(stmt, 2, NUMEROTARJETA2);
	
	if (result != SQLITE_OK) 
	{
		cout << "Error binding parameters" << endl;
		cout << sqlite3_errmsg(db) << endl;
		sqlite3_finalize(stmt);

		return result;
	} 

	int CANTIDAD = transferenciaInsertar.getCantidad();

	result = sqlite3_bind_int(stmt, 3, CANTIDAD);

	if (result != SQLITE_OK) 
	{
		cout << "Error binding parameters" << endl;
		cout << sqlite3_errmsg(db) << endl;
		sqlite3_finalize(stmt);

		return result;
	}

	//Ejecutamos el INSERT
	result = sqlite3_step(stmt);
	if (result != SQLITE_DONE) 
	{
	// cout << "Error inserting new data into Transferencias table" <<  endl;
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

//UPDATE Tarjeta, solo actualizamos el saldo de la tarjeta

int DBConnector::update_Tarjeta(Tarjeta tarjetaModificar)
{
	sqlite3_stmt *stmt;
	char sql[] = "update Tarjetas set SALDO = ? where NUMEROTARJETA = ?";
	int numeroTarjeta = tarjetaModificar.getnumTarjeta();
	int saldo = tarjetaModificar.getsaldo();
	//Preparar el statement:
	int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
	if (result != SQLITE_OK) 
	{
		// cout << "Error preparing statement (INSERT)" <<  endl;
		// cout << sqlite3_errmsg(db) <<  endl;
		return result;
	}

	//Juntar los parámetros con el statement
	//Le pasamos el saldo al statement
	result = sqlite3_bind_int(stmt, 1, saldo);
    if (result != SQLITE_OK)
	{
		// cout << "Error binding parameters" <<  endl;
		sqlite3_finalize(stmt);
		// cout << sqlite3_errmsg(db) <<  endl;
		return result;
	}
	//Le pasamos el numero de tarjeta al statement
	result = sqlite3_bind_int(stmt, 2, numeroTarjeta);

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
		// cout << "Error inserting new data into Tarjeta table" <<  endl;
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

//SELECT Usuarios
int DBConnector::leer_Usuarios(vector <Usuarios>& listaTodosUsuarios)
{
	//int cont = 0;
	sqlite3_stmt *stmt; 
	char sql[] = "select DNI, NOMBRE, APELLIDO, EMAIL from Usuarios";
   
    int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
    if (result != SQLITE_OK)
    {
      return result;
    }

    //Variables en las que recogeremos los atributos de cada Usuario
    int DNI;
  	char nombre[200];
  	char apellido[200];
  	char email[200];

    do
    {
      result = sqlite3_step(stmt);
      if (result == SQLITE_ROW) 
      {
      	//Leer el DNI, el nombre, el apellido y el email de la linea del SELECT
      	DNI = sqlite3_column_int(stmt, 0);
      	strcpy(nombre, (char*)sqlite3_column_text(stmt, 1));
      	strcpy(apellido, (char*)sqlite3_column_text(stmt, 2));
      	strcpy(email, (char*)sqlite3_column_text(stmt, 3));
  
      	//Crear un usuario con esos atributos
      	Usuarios user (DNI, nombre, apellido, email);
    	
    	listaTodosUsuarios.push_back (user);
      }
    } while (result == SQLITE_ROW);

    result = sqlite3_finalize(stmt);
    if (result != SQLITE_OK) 
    {
      return result;
    }
    return SQLITE_OK;
}

//SELECT Tarjetas

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

    //Variables en las que recogeremos los atributos de cada tarjeta
    int numeroTarjeta;
  	int PIN;
  	int Saldo;

    do
    {
      result = sqlite3_step(stmt);
      if (result == SQLITE_ROW) 
      {
      	//Leer el numero de tarjeta, el PIN y el saldo de la linea del SELECT
      	numeroTarjeta = sqlite3_column_int(stmt, 0);
      	PIN = sqlite3_column_int(stmt, 1);
      	Saldo = sqlite3_column_int(stmt, 2);
  
      	//Crear una tarjeta con esos atributos
      	Tarjeta card (numeroTarjeta, PIN, Saldo);
    	
    	listaTodasTarjetas.push_back (card);
      }
    } while (result == SQLITE_ROW);

    result = sqlite3_finalize(stmt);
    if (result != SQLITE_OK) 
    {
      return result;
    }
    return SQLITE_OK;
}

//SELECT Movimientos

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

    //Variables en las que recogeremos los atributos de cada movimiento
    int numeroTarjeta;
  	char tipoMovimiento[200];
  	int Cantidad;

    do
    {
      result = sqlite3_step(stmt);
      if (result == SQLITE_ROW) 
      {
      	//Leer el numero de tarjeta, el tipo de movimiento y la cantidad de la linea del SELECT
      	numeroTarjeta = sqlite3_column_int(stmt, 0);
      	strcpy(tipoMovimiento, (char*)sqlite3_column_text(stmt, 1));
    	Cantidad = sqlite3_column_int(stmt, 2);
  
      	//Crear un movimiento con esos atributos
      	Movimientos mov (numeroTarjeta, tipoMovimiento, Cantidad);
    	
    	listaTodosMovimientos.push_back (mov);
      }
    } while (result == SQLITE_ROW);

    result = sqlite3_finalize(stmt);
    if (result != SQLITE_OK) 
    {
      return result;
    }
    return SQLITE_OK;
}

//SELECT Transferencias

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

    //Variables en las que recogeremos los atributos de cada Transferencia
    int numeroTarjeta1;
  	int numeroTarjeta2;
  	int Cantidad;

    do
    {
      result = sqlite3_step(stmt);
      if (result == SQLITE_ROW) 
      {
      	//Leer el numero de tarjeta 1, el numero de tarjeta 2 y la cantidad de la linea del SELECT
      	numeroTarjeta1 = sqlite3_column_int(stmt, 0);
      	numeroTarjeta2 = sqlite3_column_int(stmt, 1);
      	Cantidad = sqlite3_column_int(stmt, 2);
  
      	//Crear una transferencia con esos atributos
      	Transferencia transfer (numeroTarjeta1, numeroTarjeta2, Cantidad);
    	
    	listaTodasTransferencias.push_back (transfer);
      }
    } while (result == SQLITE_ROW);

    result = sqlite3_finalize(stmt);
    if (result != SQLITE_OK) 
    {
      return result;
    }
    return SQLITE_OK;
}

