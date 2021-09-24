#pragma once
#include <ctime>
#include "cListaItems.h"
//#include "Auxiliar.h"
#include "cFecha.h"
class cTicket
{
	private:
	bool Efectivo;
	cFecha* FechayHora;
	const unsigned int ID;
	float MontoTotal;//cuanto hay que abonar de la compra
	cListaItems* Items;
	bool Abonado;//Controlar que en lista no permita modificaciones si Abonado==true
	static unsigned int Contador;
	
	public:
	cTicket(cFecha*fyh,bool efectivo=true);
	~cTicket();
	
	void CrearItem(cItem* Nuevo, unsigned int Cantidad);//Le paso un item y una cantidad para crearlo
	void SacarItem(unsigned int id, unsigned int cantidad);//le cambie el nombre porque era confuso, ya que agregas un item y no un articulo
	string to_string();
	void Imprimir();
	
	int getID();
	bool getAbonado();
	void setAbonado();
	bool getEfectivo();

	void CalcularMontoTotal(bool Agrego, float Monto);
	float getMontoTotal();
	
	friend ostream& operator<<(ostream& out, cTicket& T);
	void operator+(cItem* otro);
};

