#include "Movimientos/Movimientos.h"
#include "Tarjeta/Tarjeta.h"
#include "Usuarios/Usuarios.h"
#include "BD/DBConnector.h"
#include <vector>

using namespace std;

int main() 
{

   
    vector<Usuarios> usuarios;
    

    int a;


    do 

	{
		cout << endl <<" Este es el menu principal. Seleccione que operación desea realizar:" << endl <<" 1. Registrar usuario. 2.Iniciar sesion . 3.Salir." << endl;

		cin >> a;

		switch (a)
		{
			case 1:
			AltaUsuario(vector<Usuarios> usuarios);
			break;
			case 2: 
			IntroducirUsuario(vector<Usuarios>usuarios);
			break;
			case 3:
			Salir();
			break;
		}
	}while(a != 3);

	


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