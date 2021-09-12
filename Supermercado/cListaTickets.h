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
	void AgregarTicket(cTicket* ticket);
	void ListarTickets();
	~cListaTickets();

};

