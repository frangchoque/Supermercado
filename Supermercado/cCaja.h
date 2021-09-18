#pragma once
#include <string>
#include "cListaTickets.h"
using namespace std;
class cTicket;

class cCaja
{
private:
	bool Abierto;
	float DineroenCaja;
	float DineroRecaudado;
	const unsigned int ID;//Cambiar en el UML
	static unsigned int Contador;
	cListaTickets* Tickets;
public:
	cCaja(float DineroCaja = 1000);
	~cCaja();
	void Abrir();
	float CalcularGanancia();//La uso para calcular al final de la compra
	void Cerrar();
	void CrearTicket();
	cTicket* getTicketLista(unsigned int ID);
	void EmitirTicket();
	string to_string();
	void Imprimir();
	unsigned int getID();
	//Crear metodo para agregar items que controle que la caja esté abierta o cerrada y que el ticket no este abonado
	//Lo mismo con SacarArticulo
	//Modificar Cerrar para que no pueda hacerlo hast que el último ticket este abonado
};

