#pragma once
#include <string>
#include "cListaTickets.h"
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
	cListaTickets* Tickets;
public:
	cCaja(float DineroCaja = 1000);
	~cCaja();
	void Abrir();
	void CalcularGanancia();//La uso para calcular al final de la compra
	void Cerrar();
	cTicket* CrearTicket(bool efectivo=true);// crea un ticket con fecha y hora actual, lo agrega a la lista y lo devuelve 
	cTicket* getTicketLista(unsigned int id);
	void EmitirTicket(cTicket* ticket,bool metodopago);
	string to_string();
	void Imprimir();
	unsigned int getID();
	void AgregarItem(cTicket* ticket,cItem* Nuevo, unsigned int Cantidad);
	void SacarItem(cTicket* ticket, cItem* Eliminado, unsigned int Cantidad);
	float getGanancia();
	unsigned int getCantTickets();
	float getDineroTarjeta();
	float getDineroRecaudado();
	void setDineroRecaudado();
	//Crear metodo para agregar items que controle que la caja esté abierta o cerrada y que el ticket no este abonado
	//Lo mismo con SacarArticulo
	//Modificar Cerrar para que no pueda hacerlo hasta que el último ticket este abonado
};

