#include "cSupermercado.h"

cSupermercado::cSupermercado() {
	this->Abierto = true;
	this->DineroBanco = 1000;
	this->DineroCajaFuerte = 5000;
	//Lista_cajas = cListaCajas(Lista_cajas.Tam);
}



cSupermercado::~cSupermercado() {





}





void cSupermercado::Abrir() {
	if (Abierto == false)
		Abierto = true;
}


void cSupermercado::AgregarCaja(cCaja* nueva) {
	if (nueva != NULL) {
		cCaja* aux = NULL;
		aux= Lista_cajas.BuscarIDcaja(nueva->getID());
		if (aux != NULL) { throw exception("la caja ya existe"); }
		Lista_cajas.AgregarCaja(nueva);
		
	}
}


cCaja* cSupermercado::BuscarCaja(unsigned int ID) {
	 
	cCaja* aux = NULL;
	aux=Lista_cajas.BuscarIDcaja(ID);
	if (aux == NULL) { throw exception("no se encontro la caja"); }
	return aux;
}


void cSupermercado::Cerrar() {

	if (Abierto == true)Abierto = false;
}


string cSupermercado::MejorCajaGanancias(tm Fecha) {

	
}


string cSupermercado::MejorCajaTickets(tm Fecha) {

	
}


void cSupermercado::Recolectar() {

}


void cSupermercado::SacarCaja(cCaja*caja) {
	
	if(caja!=NULL)
		Lista_cajas.Eliminar(caja);

}

string cSupermercado::to_string()
{
	return string();
}

void cSupermercado::Imprimir()
{
}
