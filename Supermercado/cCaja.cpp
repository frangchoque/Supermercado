#define _CRT_SECURE_NO_WARNINGS
#include "cCaja.h"

cCaja::cCaja(float DineroCaja):ID(Contador)
{
	Fecha = { 0 };//No se le va a asignar una fecha hasta que habra la caja
	Abierto = false;
	DineroenCaja = DineroCaja;
	DineroRecaudado = 0;
	Tickets = new cListaTickets(); 
	Contador++;
	DineroTarjeta = 0;
}
unsigned int cCaja::Contador = 1;


cCaja::~cCaja() {
	delete Tickets;
}


void cCaja::Abrir() {
	time_t now = time(0);
	tm* time = localtime(&now);
	Fecha = time;
	Abierto = true;
}


void cCaja::CalcularGanancia() {
	for (int i = 0; i < Tickets->getCupo(); i++)
	{
		if ((*Tickets)[i]->getEfectivo())
		{
			DineroenCaja += (*Tickets)[i]->getMontoTotal();
		}
		else
		{
			DineroRecaudado += (*Tickets)[i]->getMontoTotal();
		}
	}
}


void cCaja::Cerrar() {
	Abierto = false;
	DineroenCaja = 0;
	DineroRecaudado = 0;
}


cTicket* cCaja::CrearTicket(bool efectivo) {
	if (!Abierto)
		throw new exception("La caja esta cerrada");
	cTicket* aux = new cTicket(efectivo);//la fecha y hora actual se generan automaticamente cuando se crea el ticket
	Tickets->AgregarTicket(aux);
	return aux ;
}

cTicket* cCaja::getTicketLista(unsigned int id)//Para que podamos trabajar con uno en particular
{ 
	//cTicket* aux=new cTicket;
	int pos = Tickets->BuscarID(id);//busca en la lista de tickets el ticket con ese ID y devuelve la posicion
	if (pos == -1)
		throw new exception("No se encontro el ticket");

	//aux = (*Tickets)[pos];//retorno el ticket en esa posicion
	return (*Tickets)[pos];
	
}


void cCaja::EmitirTicket(cTicket* ticket,bool metodopago) {
	if (!Abierto)
		throw new exception("La caja esta cerrada");
	if(Tickets->BuscarID(ticket->getID())==-1)
		throw new exception("El ticket no pertenece a la caja");
	if (ticket->getAbonado() == true)
	{
		throw new exception("El ticket ya esta pago, no se puede emitir");
	}
	else {
		float Monto_a_Pagar = ticket->getMontoTotal();
		if (metodopago == true) {// es efectivo
			DineroRecaudado += Monto_a_Pagar;
			ticket->setAbonado();
		}
		else {//es con tarjeta
			DineroTarjeta += Monto_a_Pagar;
			ticket->setAbonado();
		};
	}
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

float cCaja::getGanancia()
{
	return DineroenCaja+DineroRecaudado;
}

unsigned int cCaja::getCantTickets()
{
	return Tickets->getCupo();
}

float cCaja::getDineroTarjeta()
{
	return DineroTarjeta;
}

float cCaja::getDineroRecaudado()
{
	return DineroRecaudado;
}

void cCaja::setDineroRecaudado()
{
	DineroRecaudado = 0;
}

tm* cCaja::getFecha()
{
	return Fecha;
}



