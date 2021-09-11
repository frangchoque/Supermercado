#pragma once
#include <ctime>
#include "cListaItems.h"

class cTicket
{
public:
	cTicket();
	virtual ~cTicket();
	cListaItems* Items;

	void CrearArticulo();//¿Pasarle un articulo y la cantidad?
	void SacarArticulo();

private:
	bool Efectivo;
	tm FechayHora;
	unsigned int ID;
	float MontoTotal;
};

