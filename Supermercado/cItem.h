#pragma once
#include "cArticulo.h"

class cItem
{

public:
	cItem();
	virtual ~cItem();
	cArticulo* articulo;

private:
	unsigned int Cantidad;
	float PrecioTotal;
};

