#include <iostream>
#include "Tarjeta.h"

namespace Tarjeta
{

Tarjeta::Tarjeta()
{

}
int Tarjeta::AltaTarjeta ()
{

}
void Tarjeta::IntroducirTarjeta ()
{

}
void Tarjeta::ConsultarSaldo()
{

}
int Tarjeta::getnumTarjeta()
{
return numTarjeta;
}
void Tarjeta::setnumTarjeta(int numTarjeta)
{
this->numTarjeta=numTarjeta;
}
int Tarjeta::getPIN()
{
return PIN;
}
void Tarjeta::setPIN(int PIN)
{
this->PIN=PIN;
}
int Tarjeta::getsaldo()
{
return saldo;
}
void Tarjeta::setsaldo(int saldo)
{
this->saldo=saldo;	
}
Tarjeta::~Tarjeta()
{
//delete t;
}
}
