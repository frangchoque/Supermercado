#include "cListaItems.h"

void cListaItems::Redimensionalizar()
{
	cItem** aux=new cItem*[2*TAM];
	TAM = 2 * TAM;
	for (int i = 0; i < TAM; i++)
	{
		if (i < CA)
		{
			aux[i] = Lista[i];
		}
		else
		{
			aux[i] = NULL;
		}
	}
	delete[] Lista;
	Lista = aux;
}

cListaItems::cListaItems(unsigned int TAM)
{
	this->TAM = TAM;
	CA = 0;
	Lista = new cItem * [TAM];
	for (int i = 0; i < TAM; i++)
	{
		Lista[i] = NULL;
	}
}

cItem* cListaItems::operator[](unsigned int pos)
{
	return this->Buscar(pos);
}

int cListaItems::BuscarPos(unsigned int ID)
{
	int pos=-1, i=0;
	for (i = 0; i < TAM; i++)
	{
		if (this->Lista[i]->getArticuloID() == ID)
		{
			pos = i;
			break;//Salgo apenas lo encuentro
		}
	}

	return pos;
}

void cListaItems::Agregar(cItem* Nuevo)
{
	int pos = BuscarPos(Nuevo->getArticuloID());
	if (pos >= 0)
		throw new exception("El item ya se encuentra en la lista");
	if (CA == TAM)
		Redimensionalizar();
	Lista[CA++] = Nuevo;
	return;
}

void cListaItems::Eliminar(unsigned int ID)
{
	cItem* aux = NULL;
	try {
		aux = Quitar(ID);
	}
	catch(exception* error){
		throw error;
	}
	delete aux;
	return;
}

cItem* cListaItems::Buscar(unsigned int ID)
{
	int pos = BuscarPos(ID);
	if (pos == -1)
		return NULL;
	return Lista[pos];
}

cItem* cListaItems::Quitar(unsigned int ID)
{
	int pos = BuscarPos(ID);
	cItem* aux = Buscar(ID);
	if (aux == NULL)
		throw new exception("El elemento no se encuentra en la lista");
	//Si o si tiene que estar
	for (int i = pos; i < CA - 1; i++)
		Lista[i] = Lista[i + 1];
	CA--;
	return aux;
}

cListaItems::~cListaItems()
{
	if (Lista != NULL)
	{
		for (int i = 0; i < CA; i++)
		{
			if (Lista[i] != NULL)
				delete Lista[i];
		}
		delete[] Lista;
	}
}

ostream& operator<<(ostream& out, const cItem& I)
{
	
}
