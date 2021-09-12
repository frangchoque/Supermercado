#pragma once
#include "cArticulo.h"

class cItem
{
private:
	unsigned int Cantidad;
	float PrecioTotal;
	cArticulo* Articulo;

public:
	cItem(unsigned int Cantidad, cArticulo* articulo);
	~cItem();

	string to_string();
	void Imprimir();


};

