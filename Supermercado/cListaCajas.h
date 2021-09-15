#pragma once
#include "cCaja.h"
#include <string>
using namespace std;

class cListaCajas
{
	int Tam = 5,Cupo=0;
	cListaCajas* cajas;

public:
	cListaCajas();
	cListaCajas* operator[](int pos);
	~cListaCajas();
};

