#pragma once
#define N 50
#include "cItem.h"

class cListaItems
{
	cListaItems** Lista;
	unsigned int CA;
	unsigned int TAM;

public:
	cListaItems(unsigned int TAM = N);
	//ostream& operator <<(ostream& out,const cItem&i);
	cTicket* operator[](int pos);//tiene que estar en todas las listas
	int BuscarArt(cArticulo*art);//o string nombre de articulo 
	~cListaItems();


};

