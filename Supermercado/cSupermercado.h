#pragma once
#include <string>
#include "cListaCajas.h"
class cCaja;
using namespace std;


class cSupermercado
{
public:
	cSupermercado();
	~cSupermercado();

	cListaCajas* Lista_cajas;
	void Abrir();
	void AgregarCaja(cCaja* nueva);
	void BuscarCaja(unsigned int ID);
	void Cerrar();
	string MejorCajaGanancias(tm Fecha);
	string MejorCajaTickets(tm Fecha);
	void Recolectar();
	void SacarCaja(unsigned int ID);

private:
	bool Abierto;
	float DineroBanco;
	float DineroCajaFuerte;
};

