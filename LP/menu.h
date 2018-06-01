#ifndef _MENU_H
#define _MENU_H

#include "../LN/Usuarios.h"

class menu
{


public:
	menu();
	void menuUsuario();
	void menuOperaciones(Usuarios uIntroducido);
	~menu();
};

#endif