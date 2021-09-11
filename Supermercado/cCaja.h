#pragma once

class cTicket;

class cCaja
{
public:
	cCaja();
	virtual ~cCaja();
	

	void Abrir();
	float CalcularGanancia();
	void Cerrar();
	cTicket* CrearTicket();
	void EmitirTicket();

private:
	bool Abierto;
	float DineroenCaja;
	float DineroRecaudado;
	const unsigned int ID;

};

