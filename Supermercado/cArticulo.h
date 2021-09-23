#pragma once
#include <string>
#include <iostream>
class cItem;
using namespace std;

class cArticulo
{

public:
	cArticulo(string Marca, string Nombre, float PrecioUnitario);
	cArticulo(cArticulo* copia);
	~cArticulo();
	string to_string();
	void Imprimir();

private:
	static unsigned int Contador;//Modificacion con respecto al UML
	const unsigned int ID;
	string Marca;
	string Nombre;
	float PrecioUnitario;
	friend class cItem;//Clase friend
};

