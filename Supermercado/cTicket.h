#pragma once
#include <ctime>
#include "cListaItems.h"

class cTicket
{
	private:
	bool Efectivo;
	tm FechayHora;
	unsigned int ID;
	float MontoTotal;
	cListaItems* Items;
	
	public:
	cTicket();
	~cTicket();
	void CrearArticulo();//¿Pasarle un articulo y la cantidad?
	void SacarArticulo();
	string to_string();
	void Imprimir();
	int getID();

};

