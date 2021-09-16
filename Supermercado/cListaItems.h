#pragma once
#define N 50
#include "cItem.h"

class cListaItems
{
	cItem** Lista;
	unsigned int CA;
	unsigned int TAM;
	void Redimensionalizar();

public:
	cListaItems(unsigned int TAM = N);
	friend ostream& operator<<(ostream& out,const cItem& I);//Falta
	cItem* operator[](unsigned int pos);//tiene que estar en todas las listas
	int BuscarPos(unsigned int ID);//o string nombre de articulo
	void Agregar(cItem* Nuevo);//¿No permitir articulos repetidos o si?
	void Eliminar(unsigned int ID);
	cItem* Buscar(unsigned int ID);
	cItem* Quitar(unsigned int ID);
	~cListaItems();


};

