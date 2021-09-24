#pragma once
#include <string>
#include "cListaCajas.h"
#include "Auxiliar.h"
using namespace std;


class cSupermercado
{
private:
	bool Abierto;
	float DineroBanco;//dinero de cuando pagan en efectivo
	float DineroCajaFuerte;//dinero de cuando pagan con tarjeta
	cListaCajas* Lista_cajas;

public:
	cSupermercado();
	~cSupermercado();

	void Abrir();
	void Cerrar();
	void AgregarCaja(cCaja* nueva);
	void Recolectar();//transfiero a las cuentas del supermercado todo lo ganado por las cajas
	void SacarCaja(unsigned int id);
	
	cCaja* BuscarCaja(unsigned int ID);
	string MejorCajaGanancias(cFecha* Fecha);//devuelve la caja con mejor ganancia en una fecha determinada
	string MejorCajaTickets(cFecha* Fecha);//devuelve la caja que haya emitido mas tickets
	string to_string();
	
	void Imprimir();
};
