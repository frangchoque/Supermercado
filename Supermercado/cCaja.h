#pragma once
#include <string>
using namespace std;
class cTicket;

class cCaja
{
public:
	cCaja();
	~cCaja();
	

	void Abrir();
	float CalcularGanancia();
	void Cerrar();
	cTicket* CrearTicket();
	void EmitirTicket();
	string to_string();
	void Imprimir();

private:
	bool Abierto;
	float DineroenCaja;
	float DineroRecaudado;
	const unsigned int ID;

};

