#pragma once
#include "cTicket.h"
#define N 10

class cListaTickets
{
	cTicket** ticket;
	int Cupo = 0, Tam = N;

public:
	cListaTickets(int Tam=N);
	void EliminarTicket(int  id);
	cTicket* operator[](int pos);
	int BuscarID(int id);
	void AgregarTicket(cTicket* Ticket);
	void ListarTickets();
	~cListaTickets();
	const int getCupo();
};

