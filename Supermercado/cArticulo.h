#pragma once
#include <string>
using namespace std;

class cArticulo
{

public:
	cArticulo();
	virtual ~cArticulo();

private:
	const unsigned int ID;
	string Marca;
	string Nombre;
	float PrecioUnitario;
};

