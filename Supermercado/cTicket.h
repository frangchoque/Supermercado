#pragma once
#include <ctime>
#include "cListaItems.h"
#include "Auxiliar.h"

class cTicket
{
	private:
	bool Efectivo;
	tm FechayHora;
	const unsigned int ID;
	float MontoTotal;//Me equivoque. Se usa para calcular ganancia total
	cListaItems* Items;
	bool Abonado;//Controlar que en lista no permita modificaciones si Abonado==true
	static unsigned int Contador;
	
	public:
	cTicket(bool efectivo=true);
	~cTicket();
	void CrearItem(cItem* Nuevo, unsigned int Cantidad);//Le paso un item y una cantidad para crearlo
	void SacarItem(unsigned int id, unsigned int cantidad);//le cambie el nombre porque era confuso, ya que agregas un item y no un articulo
	string to_string();
	void Imprimir();
	int getID();
	bool getAbonado();

	void CalcularMontoTotal(bool Agrego, float Monto);
	float getMontoTotal();
	
};

