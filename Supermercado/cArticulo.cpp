#include "cArticulo.h"

cArticulo::cArticulo(string Marca, string Nombre, float PrecioUnitario):ID(Contador)
{
    this->Marca = Marca;
    this->Nombre = Nombre;
    this->PrecioUnitario = PrecioUnitario;
    Contador++;
}
cArticulo::cArticulo(cArticulo* copia): ID(copia->ID)
{
    Marca = copia->Marca;
    Nombre = copia->Nombre;
    PrecioUnitario = copia->PrecioUnitario;
}
unsigned int cArticulo::Contador = 1;


cArticulo::~cArticulo() {

}

string cArticulo::to_string()
{
    string aux = "\nNombre: " + this->Nombre + "\nMarca: " + this->Marca + "\nID: " + std::to_string(this->ID) + "\nPrecio unitario: " + std::to_string(this->PrecioUnitario);
    return aux;
}

void cArticulo::Imprimir()
{
    cout << to_string() << endl;
}
