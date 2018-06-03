#include <iostream>
#include <string>
#include <vector>

#include "Operaciones.h"
//#include "Usuarios.h"
//#include "Tarjeta.h"
//#include "Movimientos.h"
//#include "Transferencia.h"
#include "../LP/menu.h"
#include "../BD/DBConnector.h"

//#include "../BD/DBConnector.cpp"

#define rv 20

using namespace std;


//Alta usuario se encargará de registrar a los usuarios, recibirá un vector de usuarios y lo devolverá relleno por todos los de la bd + el nuevo
vector <Usuarios> Operaciones::AltaUsuario(vector <Usuarios> users)
{
	int existe;
	DBConnector db ("test.db");

	int leidos = db.leer_Usuarios(users);

	unsigned int DNI;
	unsigned int PIN;
	string nombre;
	string apellido;
	string email;

	cout <<" Has seleccionado registrar un nuevo usuario "<< endl;

	cout <<" Introduce el DNI: " <<endl;
	cin >> DNI;
	cout <<" Introduce el nombre: " <<endl;
	cin >> nombre;
	cout <<" Introduce el apellido: " <<endl;
	cin >> apellido;
	cout <<" Introduce el email: " <<endl;
	cin >>email;

	Usuarios usu  (DNI, nombre, apellido, email);

	existe = db.Usuario_existe(usu);

	if(existe == 0)
	{
		cout << " Se ha creado un usuario con DNI " << usu.getDNI() << endl;
		cout << " Tiene los siguientes datos personales: "<< endl;
		cout << " Nombre: "<< usu.getnombre() << endl;
		cout << " Apellido: "<< usu.getapellido() << endl;
		cout << " Correo electronico: "<< usu.getemail() << endl;

		if(users.size() < rv)
		{
			users.push_back(usu);
			db.insert_Usuario(usu);
		}else
		{
			cout <<" No se pueden añadir mas usuarios " << endl;
		}
	}else 
	{
		cout <<" El usuario ya existe " << endl;
	}		
	return users;
}

// Introducir usuarios se encarga de validar un usuario, cuando lo valide le dará acceso al menú tarjeta
void Operaciones::IntroducirUsuario(vector <Usuarios> users)
{
	DBConnector db ("test.db");

	db.leer_Usuarios(users);

	int DNI;
	int aux = 0;

	cout << " Desea iniciar sesion. Introduce el DNI de un usuario: " << endl;
	cin >> DNI;

	//Usuarios uIntroducido (DNI, PIN, uIntroducido.getnombre(), uIntroducido.getapellido(), uIntroducido.getemail());

	//uIntroducido.setDNI(DNI);
	//uIntroducido.setPIN(PIN);
	for (int i= 0; i< rv; i++)
	{
		if(users[i].getDNI() == DNI)
		{
			Usuarios uIntroducido (DNI, users[i].getnombre(), users[i].getapellido(), users[i].getemail());
			cout << " El usuario " << uIntroducido.getDNI() << " ha iniciado sesion!" << endl;
			
			menuTarjeta(uIntroducido);
			aux = 1;
		}
	}
	
	if(aux == 0)
	{	
		cout << " El usuario introducido no esta registrado! " << endl;
	}
}


//Alta tarjeta se encarga de registrar una nueva tarjeta, para ello recibe por parámetro un vector de tarjetas y lo devuelve relleno de las tarjetas de la base de datos + la nueva
vector <Tarjeta> Operaciones::AltaTarjeta (vector <Tarjeta> cards)
{
	int existe;
	DBConnector db ("test.db");

	int leidos = db.leer_Tarjetas(cards);

	unsigned int PIN;
	unsigned int numTarjeta;
	//NO SE SI SALDO SE DEBERIA PASAR POR PARAMETRO
	unsigned int saldo = 0;
	//unsigned int DNIUsuario = UsuarioIntroducido.getDNI();

	cout << " Registra el numero de tu nueva tarjeta " << endl;
	cin >> numTarjeta;
	cout << " Introduce el PIN de tu nueva tarjeta " << endl;
	cin >> PIN;

	Tarjeta card (numTarjeta, PIN, saldo); //DNIUsuario);

	existe = db.Tarjeta_existe(card);

	if (existe == 0)
	{
		cout << " Se ha creado una tarjeta con este numero: " << card.getnumTarjeta() << endl;
		
		if(cards.size() < rv)
		{
			cards.push_back(card);
			db.insert_Tarjeta(card);

		}
		else
		{
			cout <<" No se pueden añadir mas tarjetas " << endl;
		}

	}else 
	{
		cout <<" El numero de tarjeta ya existe " << endl;
	}	

	return cards;
}

//Introducir tarjeta se encarga de validar la tarjeta que quiere introducir el usuario, para ello recibe un vector de tarjetas con el que comparar
//si la tarjeta introducida por el usuario existe, luego también le pide el PIN y si todo es correcto le lleva al menú operaciones
void Operaciones::IntroducirTarjeta(vector <Tarjeta> cards)
{
	DBConnector db ("test.db");

	db.leer_Tarjetas(cards);

	int numeroTarjeta;
	int PIN;
	int saldo;
	int aux;
	
	cout << " Introduce tu numero de tarjeta " << endl;
	cin >> numeroTarjeta;

	cout << " Introduce el PIN " << endl;
	cin >> PIN;

	aux =0;

	for (int i= 0; i< rv; i++)
	{
		if(cards[i].getnumTarjeta() == numeroTarjeta)
		{
			aux = 1;

			if(cards[i].getPIN() == PIN)
			{
				Tarjeta cIntroducido (numeroTarjeta, PIN, cards[i].getsaldo()/*, cards[i].getDNIUsuario()*/);
				cout << " El numero de tarjeta introducido es " << cIntroducido.getnumTarjeta()<< endl;

				menuOperaciones(cIntroducido, cards);
			}else
			{
				cout << " El PIN es incorrecto! " << endl;
			}
		}
	}
	if (aux == 0)
	{
		cout << " El numero de tarjeta introducido no esta registrado! " << endl;	
	}
}

//Consultar saldo saca por pantalla el saldo de la tarjeta, recibe por parametro la tarjeta introducida previamente
void Operaciones::ConsultarSaldo(Tarjeta cIntroducido/*, vector <movimientos> moves*/)
{	

	//DBConnector db ("test.db");
	int saldo;

	//db.leer_Movimientos(moves);

	saldo = cIntroducido.getsaldo();

	cout << " El saldo de la tarjeta es de: " << saldo << endl;
}

//Consultar moviemientos saca por pantalla los movimientos realizados por la tarjeta que se ha introducido previamente
//recibe como parámetros la tarjeta introducida y el vector movimientos, el cual rellenará usando la bd
void Operaciones::ConsultarMovimiento(Tarjeta cIntroducido, vector <Movimientos> moves)
{
	DBConnector db ("test.db");
	int numeroTarjeta;

	db.leer_Movimientos(moves);

	numeroTarjeta = cIntroducido.getnumTarjeta();

	for(int i = 0; i < moves.size() ; i++)
	{
		if(moves[i].getnumTarjeta() == numeroTarjeta)
		{
			Movimientos MRealizado (numeroTarjeta, moves[i].getTipoMovimiento(), moves[i].getCantidad());
			cout << "La tarjeta con numero: " << MRealizado.getnumTarjeta() << " ha realizado el movimiento: " << MRealizado.getTipoMovimiento() << " cuyo importe ha sido de: " << MRealizado.getCantidad() << endl;
		}
	}
}
vector <Transferencia> Operaciones::RealizarTransferencia(Tarjeta& cIntroducido, vector <Transferencia> transfers, vector <Tarjeta> cards)
{
	DBConnector db ("test.db");
	int numTarjeta2;
	int importe;
	int aux = 0;
	int saldoTarjeta;
	int saldoTarjeta2;

	db.leer_Tarjetas(cards);

	db.leer_Transferencias(transfers);

	saldoTarjeta = cIntroducido.getsaldo();

	if(saldoTarjeta <=0)
	{
		cout << "Lo sentimos, no puede realizar esta operacion, su saldo es 0 o negativo" << endl;
	}else
	{
		do
		{
			cout << " Seleccione el importe que desea transferir, por motivos de seguridad no se pueden transferir mas de 1000 euros " << endl;
			cin >> importe;

			if(importe > saldoTarjeta)
			{
				cout << " El importe que deseas transferir es mayor que el saldo disponible, te quedarías en negativo " << endl;
			}
		}while(importe > 1000||importe < 0);

		do
		{
			cout <<" Introduce el numero de tarjeta al que quieres hacerle la transferencia " << endl;
			cin >> numTarjeta2; 

			aux = 0;

			for(int i = 0; i < cards.size(); i++)
			{
				if(numTarjeta2 == cards[i].getnumTarjeta())
				{
					saldoTarjeta = saldoTarjeta - importe;
					saldoTarjeta2 = cards[i].getsaldo();

					Transferencia t (cIntroducido.getnumTarjeta(), numTarjeta2, importe);
					db.insert_Transferencia (t);
		
					cIntroducido.setsaldo(saldoTarjeta);
					db.update_Tarjeta(cIntroducido);

					saldoTarjeta2 = saldoTarjeta2 + importe;

					Tarjeta tar (numTarjeta2, cards[i].getPIN(), saldoTarjeta2);

					db.update_Tarjeta(tar);

					return transfers;

					aux = 0;
				}else
				{
					aux = 1;
				}
			}
		}while(aux == 1);
	}
	return transfers;
}


//Sacar Dinero permite al usuario retirar dinero de su tarjeta, para ello le mandamos como parámetro la tarjeta introducida y un vector de movimientos
//la tarjeta introducida la actualizamos con el dinero que queda en la tarjeta y el vector de movimientos lo rellenamos con los movimientos realizados + el nuevo movimiento
vector <Movimientos> Operaciones::SacarDinero(Tarjeta& cIntroducido, vector <Movimientos> moves)
{
	DBConnector db ("test.db");
	int importe;
	int saldoTarjeta;

	db.leer_Movimientos(moves);

	saldoTarjeta = cIntroducido.getsaldo();

	if(saldoTarjeta <=0)
	{
		cout << " Lo sentimos, no puede realizar esta operacion, su saldo es 0 o negativo " << endl;
	}else
	{
		do
		{
			cout << " Seleccione el importe que desea retirar: Por motivos de seguridad no se pueden sacar mas de mil euros " << endl;
			cin >> importe;

			if(importe > saldoTarjeta)
			{
				cout << " El importe que deseas sacar es mayor que el saldo disponible " << endl;
			}

		}while(importe > 1000||importe < 0);

		Movimientos m (cIntroducido.getnumTarjeta(), " Sacar dinero ", importe);

		saldoTarjeta = saldoTarjeta - importe;

		cIntroducido.setsaldo(saldoTarjeta);

		db.insert_Movimientos(m);
		db.update_Tarjeta(cIntroducido);
	}
	return moves;
}

//Meter dinero permite al usuario ingresar dinero de su tarjeta, para ello le mandamos como parámetro la tarjeta introducida y un vector de movimientos
//la tarjeta introducida la actualizamos con el dinero que queda en la tarjeta y el vector de movimientos lo rellenamos con los movimientos realizados + el nuevo movimiento
vector <Movimientos> Operaciones::MeterDinero(Tarjeta& cIntroducido, vector <Movimientos> moves)
{
	DBConnector db ("test.db");
	int importe;
	int saldoTarjeta;
	int i;

	db.leer_Movimientos(moves);

	cout << " Cuanto dinero deseas ingresar " << endl;

	cin >> importe;

	saldoTarjeta = cIntroducido.getsaldo();

	Movimientos m (cIntroducido.getnumTarjeta(), " Ingresar dinero ", importe);

	saldoTarjeta = saldoTarjeta + importe;

	cIntroducido.setsaldo(saldoTarjeta);

	db.insert_Movimientos (m);
	db.update_Tarjeta(cIntroducido);

	return moves;
}

//Consultar trasnferencias nos permite ver las transferencias realizadas por nuestra tarjeta y también las recibidas, le mandamos la tarjeta introducida como parámetro
//y un vector transferencias que rellenamos desde la bd para luego sacar las transferencias que necesitemos por pantalla
void Operaciones::ConsultarTransferencias(Tarjeta cIntroducido, vector <Transferencia> transfers)
{
	DBConnector db ("test.db");
	int numeroTarjeta;

	db.leer_Transferencias(transfers);

	numeroTarjeta = cIntroducido.getnumTarjeta();

	for(int i = 0; i < transfers.size(); i++)
	{
		if(transfers[i].getnumTarjeta1() == numeroTarjeta)
		{
			Transferencia TRealizada(numeroTarjeta, transfers[i].getnumTarjeta2(), transfers[i].getCantidad());
			cout << " La tarjeta con numero: " << TRealizada.getnumTarjeta1() << " ha realizado una transferencia a la tarjeta: " << TRealizada.getnumTarjeta2() << " de " << TRealizada.getCantidad() << " euros " << endl;
		}
		else if (transfers[i].getnumTarjeta2() == numeroTarjeta)
		{
			Transferencia TRecibida(transfers[i].getnumTarjeta1(), numeroTarjeta, transfers[i].getCantidad());
			cout <<" La tarjeta con numero: " << TRecibida.getnumTarjeta2() << " ha recibido una transferencia de la tarjeta: " << TRecibida.getnumTarjeta1() << " de " << TRecibida.getCantidad() << " euros " << endl;
		}
	}
}
void Operaciones::Salir()
{


}
//}