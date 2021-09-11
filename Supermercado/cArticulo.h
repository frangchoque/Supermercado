#pragma once
#include <string>
#include <iostream>
using namespace std;

class cArticulo
{

public:
	cArticulo(string Marca, string Nombre, float PrecioUnitario);
	~cArticulo();
	string to_string();
	void Imprimir();

private:
	static unsigned int ID;//Modificacion con respecto al UML
	string Marca;
	string Nombre;
	float PrecioUnitario;
};

