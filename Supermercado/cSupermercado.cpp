#include "cSupermercado.h"

cSupermercado::cSupermercado() {
	this->Abierto = true;
	this->DineroBanco = 1000;
	this->DineroCajaFuerte = 5000;
	Lista_cajas = new cListaCajas();
}



cSupermercado::~cSupermercado() {
	delete Lista_cajas;
}





void cSupermercado::Abrir() {
	if (Abierto == false)
		Abierto = true;
}


void cSupermercado::AgregarCaja(cCaja* nueva) {
	if (nueva == NULL)
		throw new exception("Error. Puntero cCaja NULL");
	//Busco la caja
	cCaja* aux = this->Lista_cajas->BuscarIDcaja(nueva->getID());

	if (aux != NULL)//Si la encuentro
		throw new exception("La caja ya existe en la lista");
	try {
		Lista_cajas->AgregarCaja(nueva);//Controlo la excepcion cuando Cupo>=tam
	}
	catch (exception* error)
	{
		throw error;
	}

}


cCaja* cSupermercado::BuscarCaja(unsigned int ID) {
	 
	cCaja* aux = NULL;
	aux=Lista_cajas->BuscarIDcaja(ID);
	if (aux == NULL) { throw exception("no se encontro la caja"); }
	return aux;
}


void cSupermercado::Cerrar() {

	if (Abierto == true)
		Abierto = false;
}


string cSupermercado::MejorCajaGanancias(tm Fecha) {//Revisar por que le paso una fecha
	cCaja* aux = (*Lista_cajas)[0];
	float maximo = (*Lista_cajas)[0]->getGanancia();
	for (int i = 1; i < Lista_cajas->getCupo(); i++)
	{
		if (maximo < (*Lista_cajas)[i]->getGanancia())
		{
			aux = (*Lista_cajas)[i];
			maximo = (*Lista_cajas)[i]->getGanancia();
		}
	}
	return aux->to_string();
}


string cSupermercado::MejorCajaTickets(tm Fecha) {
	cCaja* aux = (*Lista_cajas)[0];
	unsigned int maximo = (*Lista_cajas)[0]->getCantTickets();
	for (int i = 1; i < Lista_cajas->getCupo(); i++)
	{
		if (maximo < (*Lista_cajas)[i]->getCantTickets())
		{
			aux = (*Lista_cajas)[i];
			maximo = (*Lista_cajas)[i]->getCantTickets();
		}
	}
	return aux->to_string();
	
}

void cSupermercado::Recolectar()
{
	int aux=Lista_cajas->getCupo();
	for (int i = 0; i < aux; i++) {
		DineroCajaFuerte+=Lista_cajas->getDineroEfectivo(i);
		DineroBanco += Lista_cajas->getDineroTarjeta(i);
	}
}





void cSupermercado::SacarCaja(cCaja*caja) {
	
	try {//No reviso que sea NULL porque lo va a hacer en Eliminar
		Lista_cajas->Eliminar(caja);
	}
	catch (exception* error)
	{
		throw error;//Relanzo la excepcion
	}
}

string cSupermercado::to_string()
{
	return string();
}

void cSupermercado::Imprimir()
{
	cout << to_string() << endl;
}
