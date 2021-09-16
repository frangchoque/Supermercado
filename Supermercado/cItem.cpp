#include "cItem.h"

cItem::cItem(unsigned int Cantidad, cArticulo* articulo) {
    this->Cantidad = Cantidad;
    Articulo = articulo;//¿Preguntar si es NULL y en caso positivo lanzar excepcion o confiar en que nunca van a pasar puntero NULL?
    this->PrecioTotal = Cantidad * articulo->PrecioUnitario;
}



cItem::~cItem() {

}

string cItem::to_string()
{
    string aux = Articulo->to_string() + "\nPrecio total: " + std::to_string(PrecioTotal) + "\nCantidad: " + std::to_string(Cantidad);
    return string();
}

void cItem::Imprimir()
{
    cout << to_string() << endl;
}

unsigned int cItem::getArticuloID()
{
    return this->Articulo->ID;
}
