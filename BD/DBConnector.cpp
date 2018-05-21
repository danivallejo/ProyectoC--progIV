#include "sqlite3.h"
#include <iostream>
#include <stdio.h>
#include <string.h>

class DBConnector {

private:
  sqlite3 *db = NULL;

public:
 int createUsers() {
    sqlite3_stmt *stmt;

    char sql[] = "create table users (DNI int primary key, nombre varchar(20), apellido varchar(30), email varchar(40))";

    //Hay que crear la tabla bien!!!!!!!!!

    int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
    if (result != SQLITE_OK) {
      std::cout << "Error preparing statement (CREATE TABLE)" << std::endl;      
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    std::cout << "SQL query prepared (CREATE TABLE)" << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;

    result = sqlite3_finalize(stmt);
    if (result != SQLITE_OK) {
      std::cout << "Error finalizing statement (CREATE TABLE)" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    std::cout << "Prepared statement finalized (CREATE TABLE)" << std::endl;

    return SQLITE_OK;
  }


  int showAllUsers() {
    sqlite3_stmt *stmt;

    char sql[] = "select DNI, nombre, apellido, email from users";

    int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
    if (result != SQLITE_OK) {
      std::cout << "Error preparing statement (SELECT)" << std::endl;      
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    std::cout << "SQL query prepared (SELECT)" << std::endl;

    int DNI;
    char * nombre;
    char * apellido;
    char * email;

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Showing users" << std::endl;

    do {
      result = sqlite3_step(stmt);
      if (result == SQLITE_ROW) {
	DNI = sqlite3_column_int(stmt, 0);
	strcpy(nombre, (char *) sqlite3_column_text(stmt, 1));
  strcpy(apellido, (char *) sqlite3_column_text(stmt, 2));
  strcpy(email, (char *) sqlite3_column_text(stmt, 3));
	std::cout << "DNI: " << DNI << " nombre: " << nombre << " apellido: " << apellido << " email: " << email << std::endl;
      }
    } while (result == SQLITE_ROW);

    std::cout << std::endl;
    std::cout << std::endl;

    result = sqlite3_finalize(stmt);
    if (result != SQLITE_OK) {
      std::cout << "Error finalizing statement (SELECT)" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    std::cout << "Prepared statement finalized (SELECT)" << std::endl;

    return SQLITE_OK;
  }

  int deleteAllUsers() {
    sqlite3_stmt *stmt;

    char sql[] = "delete from users";

    int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
    if (result != SQLITE_OK) {
      std::cout << "Error preparing statement (DELETE)" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    std::cout << "SQL query prepared (DELETE)" << std::endl;

    result = sqlite3_step(stmt);
    if (result != SQLITE_DONE) {
      std::cout << "Error deleting data (DELETE)" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    result = sqlite3_finalize(stmt);
    if (result != SQLITE_OK) {
      std::cout << "Error finalizing statement (DELETE)" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    std::cout << "Prepared statement finalized (DELETE)" << std::endl;

    return SQLITE_OK;
  }

  int insertNewUsers(int DNI) {
    sqlite3_stmt *stmt;

    char sql[] = "insert into users (DNI, nombre, apellido, email) values (?, ?, ?, ?)";
    int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
    if (result != SQLITE_OK) {
      std::cout << "Error preparing statement (INSERT)" << std::endl;
      std::cout <<  sqlite3_errmsg(db) << std::endl;
      return result;
    }

    std::cout << "SQL query prepared (INSERT)" << std::endl;

    result = sqlite3_bind_int(stmt, 1, DNI);
    if (result != SQLITE_OK) {
      std::cout << "Error binding parameters" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    result = sqlite3_step(stmt);
    if (result != SQLITE_DONE) {
      std::cout << "Error inserting new data into users table" << std::endl;
      return result;
    }

    result = sqlite3_finalize(stmt);
    if (result != SQLITE_OK) {
      std::cout << "Error finalizing statement (INSERT)" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    std::cout << "Prepared statement finalized (INSERT)" << std::endl;

    return SQLITE_OK;
  }

  int insertNewUsersID(int DNI, std::string nombre, std::string apellido, std::string email) {
    sqlite3_stmt *stmt;

    char sql[] = "insert into users (DNI , nombre, apellido, email) values (?, ?, ?, ?)";
    int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
    if (result != SQLITE_OK) {
      std::cout << "Error preparing statement (INSERT)" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    std::cout << "SQL query prepared (INSERT)" << std::endl;

    result = sqlite3_bind_int(stmt, 1, DNI);
    if (result != SQLITE_OK) {
      std::cout << "Error binding parameters" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    result = sqlite3_bind_text(stmt, 2, nombre.c_str(), nombre.length(), SQLITE_STATIC);
    if (result != SQLITE_OK) {
      std::cout << "Error binding parameters" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    result = sqlite3_bind_text(stmt, 3, apellido.c_str(), apellido.length(), SQLITE_STATIC);
    if (result != SQLITE_OK) {
      std::cout << "Error binding parameters" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    result = sqlite3_bind_text(stmt, 4, email.c_str(), email.length(), SQLITE_STATIC);
    if (result != SQLITE_OK) {
      std::cout << "Error binding parameters" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }
    result = sqlite3_step(stmt);
    if (result != SQLITE_DONE) {
      std::cout << "Error inserting new data into users table" << std::endl;
      return result;
    }

    result = sqlite3_finalize(stmt);
    if (result != SQLITE_OK) {
      std::cout << "Error finalizing statement (INSERT)" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
      return result;
    }

    std::cout << "Prepared statement finalized (INSERT)" << std::endl;

    return SQLITE_OK;
  }

  DBConnector(std::string dbFile) {
    //int result = sqlite3_open("test.sqlite", &db);
    int result = sqlite3_open(dbFile.c_str(), &db);
    if (result != SQLITE_OK) {
      std::cout << "Error opening database" << std::endl;

    }
  }

  ~DBConnector() {
    int result = sqlite3_close(db);
    if (result != SQLITE_OK) {
      std::cout << "Error opening database" << std::endl;
      std::cout << sqlite3_errmsg(db) << std::endl;
    }	
  }
};

int main() {
  DBConnector dbConnector("test.sqlite");

  int result;

  result = dbConnector.createUsers();
  if (result != SQLITE_OK) {
    std::cout << "Error creating table users" << std::endl;
    return result;
  }
   result = dbConnector.insertNewUsersID(72606542, "Dani", "Vallejo", "danivallejo@opendeusto.es");
  if (result != SQLITE_OK) {
    std::cout << "Error inserting new data with DNI 72606542G. Already exists" << std::endl;
    return result;
  }
  result = dbConnector.insertNewUsers(72606542);
  if (result != SQLITE_OK) {
    std::cout << "Error inserting new data" << std::endl;
    return result;
  }
  result = dbConnector.showAllUsers();
  if (result != SQLITE_OK) {
    std::cout << "Error getting all users" << std::endl;
    return result;
  }

   result = dbConnector.deleteAllUsers();
  if (result != SQLITE_OK) {
    std::cout << "Error deleting all users" << std::endl;
    return result;
  }


  return 0;
}
