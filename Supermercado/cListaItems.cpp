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
	return this->Buscar_por_Pos(pos);
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

int cListaItems::BuscarPosItemCreado(unsigned int ID, unsigned int Cantidad)
{
	int pos = -1, i = 0;
	for (i = 0; i < TAM; i++)
	{
		if (this->Lista[i]->getArticuloID() == ID&&this->Lista[i]->getCantidad()==Cantidad)
		{
			pos = i;
			break;//Salgo apenas lo encuentro
		}
	}

	return pos;
}

void cListaItems::Agregar(cItem* Nuevo,int cantidad)
{
	if (Nuevo==NULL)
		throw new exception("Error");
	//int pos = BuscarPosItemCreado(Nuevo->getArticuloID(), Nuevo->getCantidad());
	//if (pos >= 0)
		//throw new exception("El item ya se encuentra en la lista");
	
	//Permito elementos repetidos porque puede suceder que compre repetidas veces el mismo producto con la misma cantidad
	//si, esta hecho abajo fijate si esta bien 
	if (Nuevo != NULL) {
		int encontro = 0;
		if (TAM > CA) {
			for (int i = 0; i < CA; i++) {
				if (Lista[i]->getArticuloID() == Nuevo->getArticuloID()) {
					Lista[i]->setCantArticulo(cantidad);
					//falta lo del monto
					encontro = 1;//el articulo ya esta en el ticket 
				}
			}
			if (encontro == 0) {
				//el articulo no esta en el ticket entonces lo agrego 
				Lista[CA + 1] = Nuevo;
				CA++;
			}
		}
		if (CA > TAM || CA == TAM) { throw exception("La lista esta llena"); }
	}



	if (CA == TAM)
		Redimensionalizar();
	Lista[CA++] = Nuevo;
	return;
}

void cListaItems::Eliminar(unsigned int ID, unsigned int Cantidad)
{
	cItem* aux = NULL;
	try {
		aux = Quitar(ID, Cantidad);
	}
	catch(exception* error){
		throw error;
	}
	delete aux;
	return;
}

cItem* cListaItems::Buscar(unsigned int ID, unsigned int Cantidad)
{
	int pos = BuscarPos(ID);
	if (pos == -1)
		return NULL;
	return Lista[pos];
}

cItem* cListaItems::Buscar_por_Pos(unsigned int pos)
{
	if (pos >= CA)
		throw new exception("No se encuentra en la lista");
	//Siempre va a ser >=0, entonces solo me fijo que el elemento exista en la lista
	return Lista[pos];
}

cItem* cListaItems::Quitar(unsigned int ID, unsigned int Cantidad)
{
	int pos = BuscarPosItemCreado(ID, Cantidad);
	cItem* aux = Buscar(ID, Cantidad);//No importa que este repetido, solo que borre el primero que encuentre
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

unsigned int cListaItems::getCA()
{
	return CA;
}

string cListaItems::to_string()
{
	string aux="\nItems: \n";
	for (int i = 0; i < CA; i++)
	{
		aux += Lista[i]->to_string();
	}

	return aux;
}

ostream& operator<<(ostream& out, const cItem& I)
{
	return out;
}
