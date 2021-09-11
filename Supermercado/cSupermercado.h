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

	void Abrir();
	void AgregarCaja(cCaja* nueva);
	void BuscarCaja(unsigned int ID);
	void Cerrar();
	string MejorCajaGanancias(tm Fecha);
	string MejorCajaTickets(tm Fecha);
	void Recolectar();
	void SacarCaja(unsigned int ID);
	string to_string();
	void Imprimir();

private:
	bool Abierto;
	float DineroBanco;
	float DineroCajaFuerte;
	cListaCajas* Lista_cajas;
};

