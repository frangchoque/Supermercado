#pragma once
#include <string>
#include "cCaja.h"

using namespace std;

class cListaCajas
{
	friend class cSupermercado;
	int Tam, Cupo;
	cCaja** cajas;

public:
	cListaCajas(int tam);
	cCaja* operator[](int pos);
	cCaja* BuscarIDcaja(unsigned int id);
	int PosCaja(unsigned int  id);
	//unsigned int IDcajas(cCaja*caja);
	void AgregarCaja(cCaja*caja);
	void Eliminar(cCaja*caja);
	~cListaCajas();
};

