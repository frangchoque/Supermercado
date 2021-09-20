#include "cTicket.h"
#define _CRT_SECURE_NO_WARNINGS

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


void cTicket::CrearItem(cItem* Nuevo, unsigned int Cantidad) {
    Items->Agregar(Nuevo,Cantidad);
    (*Items)[Items->getCA() - 1]->setCantidad(Cantidad);//Si es una nueva cantidad
    CalcularMontoTotal(true, (*Items)[Items->getCA() - 1]->getPrecio());
}


void cTicket::SacarItem(unsigned int id, unsigned int cantidad) {
    Items->Eliminar(id, cantidad);
    CalcularMontoTotal(false, (*Items)[Items->getCA() - 1]->getPrecio());
}

string cTicket::to_string()
{
    string aux = tm_to_string(FechayHora) + "Efectivo: " + bool_to_string(Efectivo) + "\nTarjeta: " + bool_to_string(!Efectivo) + "\nId: " + std::to_string(ID) +
        "\nMonto total: " + std::to_string(MontoTotal) + Items->to_string() + "\nAbonado: " + std::to_string(Abonado);
    return aux;
}

void cTicket::Imprimir()
{
    cout << this->to_string() << endl;
}

int cTicket::getID()
{
    return ID;
}

void cTicket::CalcularMontoTotal(bool Agrego, float Monto)
{
    //MontoTotal esta inicializado en 0, entonces puedo hacer
    if (Agrego)
        MontoTotal += Monto;
    if (!Agrego)
        MontoTotal -= Monto;
}

float cTicket::getMontoTotal()
{
    return MontoTotal;
}

bool cTicket::getAbonado()
{
    return Abonado;
}
