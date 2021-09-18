#include "cTicket.h"

cTicket::cTicket(bool efectivo):ID(Contador)
{
    time_t now = time(0);
    tm* time = localtime(&now);
    FechayHora = *time;//Asigno la fecha en el instante que creo el ticket
    MontoTotal = 0;
    Efectivo = efectivo;
    Items = new cListaItems();
    Abonado = false;
    Contador++;
}
unsigned int cTicket::Contador = 1;


cTicket::~cTicket() {
    delete Items;
}


void cTicket::CrearArticulo(cItem* Nuevo, unsigned int Cantidad) {
    Items->Agregar(Nuevo);
    (*Items)[Items->getCA() - 1]->setCantidad(Cantidad);
}


void cTicket::SacarArticulo(unsigned int id, unsigned int cantidad) {
    Items->Eliminar(id, cantidad);
}

string cTicket::to_string()
{
    return string();
}

void cTicket::Imprimir()
{
}

int cTicket::getID()
{
    return ID;
}
