#pragma once
#include "cArticulo.h"
class cTicket;

class cItem
{
private:
	unsigned int Cantidad;
	float PrecioTotal;
	cArticulo* Articulo;
	friend class cTicket;

public:
	cItem(unsigned int Cantidad, cArticulo* articulo);
	cItem(cItem* copia);
	~cItem();
	string to_string();
	void Imprimir();
	unsigned int getArticuloID();
	void setCantidad(unsigned int cantidad);
	unsigned int getCantidad();
	float getPrecio();
	void setCantArticulo(unsigned int cant);
	cArticulo* getArticulo();

	cItem& operator++();
};

