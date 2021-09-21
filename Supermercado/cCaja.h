#pragma once
#include <string>
#include "cListaTickets.h"
using namespace std;
class cTicket;

class cCaja
{
private:
	bool Abierto;
	float DineroenCaja;//Monto en caja
	float DineroRecaudado;//Con tarjeta
	const unsigned int ID;//Cambiar en el UML
	static unsigned int Contador;
	cListaTickets* Tickets;//¿Hago que solo pueda trabajar con un ticket a la vez?Si es así, entonces solo puedo trabajar con el último ¿no?
public:
	cCaja(float DineroCaja = 1000);
	~cCaja();
	void Abrir();
	void CalcularGanancia();//La uso para calcular al final de la compra
	void Cerrar();
	void CrearTicket(bool Efectivo);
	cTicket* getTicketLista(unsigned int id);
	void EmitirTicket(cTicket* ticket);
	string to_string();
	void Imprimir();
	unsigned int getID();
	void AgregarItem(cTicket* ticket,cItem* Nuevo, unsigned int Cantidad);
	void SacarItem(cTicket* ticket, cItem* Eliminado, unsigned int Cantidad);
	float getGanancia();
	unsigned int getCantTickets();

	//Crear metodo para agregar items que controle que la caja esté abierta o cerrada y que el ticket no este abonado
	//Lo mismo con SacarArticulo
	//Modificar Cerrar para que no pueda hacerlo hasta que el último ticket este abonado
};

