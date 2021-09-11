#pragma once
#include <ctime>
#include "cListaItems.h"

class cTicket
{
public:
	cTicket();
	~cTicket();
	cListaItems* Items;

	void CrearArticulo();//¿Pasarle un articulo y la cantidad?
	void SacarArticulo();
	string to_string();
	void Imprimir();

private:
	bool Efectivo;
	tm FechayHora;
	unsigned int ID;
	float MontoTotal;
};

