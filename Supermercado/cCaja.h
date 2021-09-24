#pragma once
#include <string>
#include "cListaTickets.h"
#include "Auxiliar.h"
//#include "cFecha.h"
using namespace std;
class cTicket;

class cCaja
{
private:
	bool Abierto;
	float DineroenCaja;//Monto en caja inicial
	float DineroTarjeta;//Monto abonado con tarjeta
	float DineroRecaudado;//cuanto dinero recauda en un dia, solo efectivo
	const unsigned int ID;
	static unsigned int Contador;
	cFecha* Fecha;
	cListaTickets* Tickets;
public:
	cCaja(cFecha* fecha,float DineroCaja = 1000);
	~cCaja();
	
	void Abrir();
	void Cerrar();
	
	void CalcularGanancia();//La uso para calcular al final de la compra
	
	cTicket* CrearTicket(bool efectivo);// crea un ticket con fecha y hora actual, lo agrega a la lista y lo devuelve 
	cTicket* getTicketLista(unsigned int id);
	void EmitirTicket(cTicket* ticket);
	void AgregarItem(cTicket* ticket, cItem* Nuevo, unsigned int Cantidad);
	void SacarItem(cTicket* ticket, cItem* Eliminado, unsigned int Cantidad);
	
	string to_string();
	void Imprimir();
	
	unsigned int getID();
	float getGanancia();
	unsigned int getCantTickets();
	float getDineroTarjeta();
	float getDineroRecaudado();
	void setDineroRecaudado();
	void setDineroTarjeta();
	cFecha* getFecha();
};

