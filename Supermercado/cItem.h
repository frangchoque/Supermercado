#pragma once
#include "cArticulo.h"

class cItem
{

public:
	cItem();
	~cItem();
	cArticulo* articulo;

	string to_string();
	void Imprimir();

private:
	unsigned int Cantidad;
	float PrecioTotal;
};

