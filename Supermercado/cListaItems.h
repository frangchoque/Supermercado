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
	~cListaItems();


};

