#include "cCaja.h"

cCaja::cCaja(float DineroCaja):ID(Contador)
{
	Abierto = false;
	DineroenCaja = DineroCaja;
	DineroRecaudado = 0;
	Tickets = new cListaTickets(); 
	Contador++;
}
unsigned int cCaja::Contador = 1;


cCaja::~cCaja() {
	//delete Tickets;
}


void cCaja::Abrir() {
	Abierto = true;
}


float cCaja::CalcularGanancia() {

	return 0;
}


void cCaja::Cerrar() {
	Abierto = false;
}


cTicket* cCaja::CrearTicket() {

	return  NULL;
}


void cCaja::EmitirTicket() {

}

string cCaja::to_string()
{
	return string();
}

void cCaja::Imprimir()
{
}

unsigned int cCaja::getID()
{
	return ID;
}
