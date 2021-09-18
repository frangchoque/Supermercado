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
	delete Tickets;
}


void cCaja::Abrir() {
	Abierto = true;
}


float cCaja::CalcularGanancia() {

	return 0;//¿Como? si solo tenemos dinero recaudado
}


void cCaja::Cerrar() {
	Abierto = false;
}


void cCaja::CrearTicket() {
	if (!Abierto)
		throw new exception("La caja esta cerrada");
	cTicket* aux = new cTicket();
	Tickets->AgregarTicket(aux);
	return;
}

cTicket* cCaja::getTicketLista(unsigned int ID)//Para que podamos trabajar con uno en particular
{
	return Tickets[Tickets->getCupo()-1];//Revisar la sobrecarga
}


void cCaja::EmitirTicket() {
	if (!Abierto)
		throw new exception("La caja esta cerrada");

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

void cCaja::AgregarItem(cItem* Nuevo, unsigned int Cantidad)
{
	if (!Abierto)
		throw new exception("\nLa caja esta cerrada");
	if()
	//la caja esté abierta o cerrada y que el ticket no este abonado
}
