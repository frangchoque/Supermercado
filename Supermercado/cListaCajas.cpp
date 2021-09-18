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

int cListaCajas::PosCaja(unsigned int id)
{
	for (int i = 0; i < Cupo; i++) {
		if (cajas[i]->getID() == id)return i;
	}
}

void cListaCajas::Eliminar(cCaja* caja){
	if (caja != NULL) {
		int pos = PosCaja(caja->getID());
		 cajas[pos]=NULL;
		cCaja* c = NULL;
		for (int i = pos; i < Cupo - 1; i++) {
			c = cajas[i];
			cajas[i] = cajas[i + 1];
			cajas[i + 1] = c;
		}
		Cupo--;
	}
}

void cListaCajas::AgregarCaja(cCaja*caja)
{
	if (caja != NULL) {

		if (Tam > Cupo) {
			cajas[Cupo + 1] = caja;
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
