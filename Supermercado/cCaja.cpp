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
	//cTicket* aux=new cTicket;
	int pos = Tickets->BuscarID(ticket->getID());//busca en la lista de tickets el ticket con ese ID y devuelve la posicion
	if (pos == -1)
		throw new exception("No se encontro el ticket");

	//aux = (*Tickets)[pos];//retorno el ticket en esa posicion
	return (*Tickets)[pos];
	// Algo como esto
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
	if (ticket == NULL) {//Reemplaza a ticket!=NULL
		throw new exception("Error. Ticket NULL");
	}
	if (Nuevo == NULL)//Reemplaza a Nuevo!=NULL
	{
		throw new exception("Error. Item NULL");
	}
	if (ticket->getAbonado())
		throw new exception("Ticket ya abonado");


	//if (ticket != NULL) {
	int pos = Tickets->BuscarID(ticket->getID());
	if (pos == -1)//No se encuentra en la lista
		throw new exception("El ticket no corresponde a esta caja");
	
	(*Tickets)[pos]->CrearItem(Nuevo, Cantidad);//Si llego hasta aca, debe funcionar
		

	//if (Nuevo != NULL) { 
			//cTicket* aux= new cTicket;
			//aux = (*Tickets)[pos];
			//if (aux->getAbonado() != true) {
				//aux->CrearItem(Nuevo, Cantidad);
			//}
	//}
	//}
}

void cCaja::SacarItem(cTicket* ticket, cItem* Eliminado, unsigned int Cantidad)
{
	if (!Abierto)
		throw new exception("\nLa caja esta cerrada");
	if (ticket == NULL) {//Reemplaza a ticket!=NULL
		throw new exception("Error. Ticket NULL");
	}
	if (Eliminado == NULL)//Reemplaza a Nuevo!=NULL
	{
		throw new exception("Error. Item NULL");
	}
	if (ticket->getAbonado())
		throw new exception("Ticket ya abonado");

	int pos = Tickets->BuscarID(ticket->getID());
	if (pos == -1)//No se encuentra en la lista
		throw new exception("El ticket no corresponde a esta caja");

	(*Tickets)[pos]->SacarItem(Eliminado->getArticuloID(), Cantidad);//Si llego hasta aca, debe funcionar
}
