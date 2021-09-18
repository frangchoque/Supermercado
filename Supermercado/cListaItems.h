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
	int BuscarPosItemCreado(unsigned int ID, unsigned int Cantidad);
	void Agregar(cItem* Nuevo);//¿No permitir articulos repetidos o si?
	void Eliminar(unsigned int ID, unsigned int Cantidad);// Modificar para que elimine con cantidad y permitir articulos repetidos
	cItem* Buscar(unsigned int ID, unsigned int Cantidad);
	cItem* Buscar_por_Pos(unsigned int pos);
	cItem* Quitar(unsigned int ID, unsigned int Cantidad);
	~cListaItems();
	unsigned int getCA();

};

