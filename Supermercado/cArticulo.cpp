#include "cArticulo.h"

cArticulo::cArticulo(string Marca, string Nombre, float PrecioUnitario)
{
    this->Marca = Marca;
    this->Nombre = Nombre;
    this->PrecioUnitario = PrecioUnitario;
    ID++;
}
unsigned int cArticulo::ID = 1;


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
