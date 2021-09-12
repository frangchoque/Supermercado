#include "cListaTickets.h"

cListaTickets::cListaTickets(int Tam)
{
	ticket = new cTicket * [Tam];
	for (unsigned int i = 0; i < Tam; i++)
	{
		ticket[i] = NULL;
	}

	this->Tam = Tam;
	Cupo = 0;
}

void cListaTickets::EliminarTicket(int id)
{
	if (ticket != NULL) {
		for (int i = 0; i < Cupo; i++)
		{
			if (ticket[i]->getID() == id)
			{
				ticket[i] = NULL;
				Cupo--;
				ticket[i] = ticket[i + 1];
			}
	
		}

	}


}

cListaTickets::~cListaTickets()
{
}
