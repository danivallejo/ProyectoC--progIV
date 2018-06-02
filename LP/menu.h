#ifndef _MENU_H
#define _MENU_H

//#include "../LN/Usuarios.h"

class menu
{


public:
	menu();
	void menuUsuario();
	void menuTarjeta(Usuarios uIntroducido);
	void menuOperaciones(Tarjeta cIntroducida);
	~menu();
};

#endif