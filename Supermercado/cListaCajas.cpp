#include "cListaCajas.h"

cListaCajas::cListaCajas(int tam)
{
	this->Tam = tam;
	Cupo = 0;
	cajas = new cCaja*[tam];
	for (int i = 0; i < tam; i++) { cajas[i] = NULL; }
}

cCaja* cListaCajas::operator[](int pos)
{
	if (pos <= Cupo) { return cajas[pos]; }
	else return NULL;

}

cListaCajas::~cListaCajas()
{
	if (cajas != NULL)
	{
		for (int i = 0; i < Cupo; i++)
		{
			if (cajas[i] != NULL)
				delete cajas[i];
		}
		delete[] cajas;
	}
}

void cListaCajas::AgregarCaja(cCaja*caja)
{
	if (cajas != NULL) {

		if (Tam > Cupo) {
			cajas[Cupo + 1] = *cajas;
			Cupo++;
		}
		if (Cupo > Tam || Cupo == Tam) { throw exception("La lista esta llena"); }
	}

}



cCaja* cListaCajas::BuscarIDcaja(unsigned int id)
{
	for (int i = 0; i < Cupo; i++) {
		if (cajas[i]->getID() == id) { return cajas[i]; }
		else return NULL;//no se encontro 
	}
}
