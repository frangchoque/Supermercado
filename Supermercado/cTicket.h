#pragma once
#include <ctime>
#include "cListaItems.h"

class cTicket
{
	private:
	bool Efectivo;
	tm FechayHora;
	const unsigned int ID;
	float MontoTotal;//Aca guardo lo de CalcularGanancia en cCaja
	cListaItems* Items;
	bool Abonado;//Controlar que en lista no permita modificaciones si Abonado==true
	static unsigned int Contador;
	
	public:
	cTicket(bool efectivo=true);
	~cTicket();
	void CrearArticulo(cItem* Nuevo, unsigned int Cantidad);//¿Pasarle un articulo y la cantidad?, creo que le pasas un item (e item busca en una lista de articulos pero no se) y la cantidad
	void SacarArticulo(unsigned int id, unsigned int cantidad);
	string to_string();
	void Imprimir();
	int getID();

};

