#include "LN/Movimientos.h"
#include "LN/Tarjeta.h"
#include "LN/Usuarios.h"
#include "LN/Operaciones.h"
#include "LP/menu.h"
#include "BD/sqlite3.h"
#include "BD/DBConnector.h"
//#include <vector>

using namespace std;

int main() 
{

  Operaciones o;
  sqlite3 *db;
  string dbFile = "test.db";
  DBConnector db1(dbFile);
  
  int result;

  result = sqlite3_open(dbFile.c_str(), &db);
  if(result != SQLITE_OK)
  {
    cout << "Error opening database" << endl;
    return result;
  }

  db1.create_table_Usuarios();
  db1.create_table_Tarjetas();
  db1.create_table_Movimientos();
  db1.create_table_Transferencias();


  menuUsuario();

  //iniciarBD(db);





  

	
/*

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


*/

  return 0;
}