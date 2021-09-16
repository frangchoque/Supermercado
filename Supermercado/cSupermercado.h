#pragma once
#include <string>
#include "cListaCajas.h"
//#include "cCaja.h"
//class cCaja;
using namespace std;


class cSupermercado
{
private:
	bool Abierto;
	float DineroBanco;
	float DineroCajaFuerte;
	cListaCajas Lista_cajas;

public:
	cSupermercado();
	~cSupermercado();

	void Abrir();
	void AgregarCaja(cCaja* nueva);
	cCaja*BuscarCaja(unsigned int ID);
	void Cerrar();
	string MejorCajaGanancias(tm Fecha);
	string MejorCajaTickets(tm Fecha);
	void Recolectar();
	void SacarCaja(cCaja*caja);
	string to_string();
	void Imprimir();


};

