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
	float CalcularGanancia();
	void Cerrar();
	cTicket* CrearTicket();
	void EmitirTicket();
	string to_string();
	void Imprimir();
	unsigned int getID();

};

