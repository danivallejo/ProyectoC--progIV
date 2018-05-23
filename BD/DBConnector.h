#ifndef _DBCONNECTOR_H
#define _DBCONNECTOR_H


#include <iostream>
#include <string.h>
#include "sqlite3.h"

using namespace std;

class DBConnector
{
	
	sqlite3 *db = NULL;

public:

	int createUsers();
	
	int showAllUsers();

	int deleteAllUsers();
	
	int insertNewUsers(int DNI);

	int insertNewUsersID(int DNI, string nombre, string apellido, string email);

	DBConnector(string dbFile);

	~DBConnector(); 
};

#endif

