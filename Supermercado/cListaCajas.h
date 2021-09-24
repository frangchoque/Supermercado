#pragma once
#include <string>
#include "cCaja.h"
#define N 20

using namespace std;

class cListaCajas
{
	friend class cSupermercado;
	unsigned int Tam, Cupo;
	cCaja** cajas;

public:
	cListaCajas(int tam=N);
	cCaja* operator[](unsigned int pos);
	cCaja* Buscar_por_Pos(unsigned int pos);
	cCaja* BuscarIDcaja(unsigned int id);
	int PosCaja(unsigned int  id);
	//unsigned int IDcajas(cCaja*caja);
	void AgregarCaja(cCaja* caja);
	cCaja* Quitar(unsigned id);
	void Eliminar(unsigned int ID);
	~cListaCajas();
	unsigned int getCupo();
	float getDineroTarjeta(int pos);
	float getDineroEfectivo(int pos);
};

