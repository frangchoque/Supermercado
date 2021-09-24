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
	if (aux == NULL) { throw exception("\nNo se encontro la caja"); }
	return aux;
}


void cSupermercado::Cerrar() {

	if (Abierto == true)
		Abierto = false;
	Recolectar();//junto las ganancias de las cajas
	for (int i = 0; i < Lista_cajas->getCupo(); i++)
	{
		(*Lista_cajas)[i]->Cerrar();//Cierro todas las cajas
	}
}


string cSupermercado::MejorCajaGanancias(cFecha* Fecha) {
	cCaja* aux = NULL;
	float maximo = 0;
	
	for (int i = 0; i < Lista_cajas->getCupo(); i++)
	{
		if (maximo < (*Lista_cajas)[i]->getGanancia() && Fecha == ((*Lista_cajas)[i]->getFecha()))
		{
			aux = (*Lista_cajas)[i];
			maximo = (*Lista_cajas)[i]->getGanancia();
		}
	}
	
	if (aux == NULL)
		return "\nNo se encontro ninguna caja";
	else
		return aux->to_string();//imprimo la mejor caja
}


string cSupermercado::MejorCajaTickets(cFecha* Fecha) {
	cCaja* aux = NULL;
	unsigned int maximo = 0;
	
	for (int i = 0; i< Lista_cajas->getCupo(); i++)
	{
		if (maximo < (*Lista_cajas)[i]->getCantTickets() && Fecha == ((*Lista_cajas)[i]->getFecha()))
		{
			aux = (*Lista_cajas)[i];
			maximo = (*Lista_cajas)[i]->getCantTickets();
		}
	}
	if (aux == NULL)
		return "\nNo se encontro ninguna caja";
	else
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

void cSupermercado::SacarCaja(unsigned int id) {
	
	try {//No reviso que sea NULL porque lo va a hacer en Eliminar
		Lista_cajas->Eliminar(id);
	}
	catch (exception* error)
	{
		throw error;//Relanzo la excepcion
	}
}

string cSupermercado::to_string()
{
	return "\n Dinero en el banco: " +std::to_string(DineroBanco)+"$" +"\n Dinero en la caja fuerte: "+std::to_string(DineroCajaFuerte)+"$";
}

void cSupermercado::Imprimir()
{
	cout << to_string() << endl;
}

