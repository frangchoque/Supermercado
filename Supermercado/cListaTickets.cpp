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

		int pos = BuscarID(id);
		if (pos != -1)
		{
			ticket[pos] = NULL;
			for (int i = pos; i < Cupo; i++) {
				ticket[i] = ticket[i + 1];
				
			}
			Cupo--;
		}
		if (pos == -1) throw exception("No se encontro");
	}


}

cTicket* cListaTickets::operator[](int pos)
{
	if (pos < Cupo)
	{
		return ticket[pos];
	}
	else return NULL;
}

int cListaTickets::BuscarID(int id)
{
	for (int i = 0; i < Cupo; i++)
	{
		if (ticket[i]->getID() == id) {
			return i;
		}
		else return -1;// no se encontro 
	}
}

void cListaTickets::AgregarTicket(cTicket* ticket)
{
	if (ticket != NULL) {
	
		if (Tam > Cupo) {
			ticket[Cupo + 1] = *ticket;
			Cupo++;
		}
		if (Cupo > Tam || Cupo == Tam) { throw exception("La lista esta llena"); }
	}


}

void cListaTickets::ListarTickets()
{
	for (int i = 0; i < Cupo; i++)
	{
		cout << ticket[i] << endl;
	}
}

cListaTickets::~cListaTickets()
{
}
