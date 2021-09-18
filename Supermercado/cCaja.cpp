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

cTicket* cCaja::getTicketLista(cTicket*ticket)//Para que podamos trabajar con uno en particular
{ 
	cTicket* aux=new cTicket;
	int pos = Tickets->BuscarID(ticket->getID());//busca en la lista de tickets el ticket con ese ID y devuelve la posicion
	aux = Tickets->operator[](pos);//retorno el ticket en esa posicion
	return aux;
	// eso querias hacer??
	//return Tickets[Tickets->getCupo()-1];//Revisar la sobrecarga
	
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

void cCaja::AgregarItem(cTicket* ticket,cItem* Nuevo, unsigned int Cantidad)
{
	if (!Abierto)
		throw new exception("\nLa caja esta cerrada");
	if (ticket != NULL) {
		int pos = Tickets->BuscarID(ticket->getID());
		
		if (Nuevo != NULL) { 
			cTicket* aux= new cTicket;
			aux = Tickets->operator[](pos);
			if (aux->getAbonado() != true) {
				aux->CrearItem(Nuevo, Cantidad);
			}
		}
	}
}
