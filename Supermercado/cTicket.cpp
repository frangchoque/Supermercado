#define _CRT_SECURE_NO_WARNINGS
#include "cTicket.h"


cTicket::cTicket(bool efectivo):ID(Contador)
{
    time_t now = time(0);
    tm* time = localtime(&now);
    FechayHora = *time;//Asigno la fecha en el instante que creo el ticket
    MontoTotal = 0;
    Efectivo = true;//false es tarjeta
    Items = new cListaItems();
    Abonado = false;
    Contador++;
}
unsigned int cTicket::Contador = 1;


cTicket::~cTicket() {
    delete Items;
}


void cTicket::CrearItem(cItem* Nuevo, unsigned int Cantidad) {
    try {
        Items->Agregar(Nuevo, Cantidad);
    }
    catch (exception* error)
    {
        throw error;
    }
    CalcularMontoTotal(true, (*Items)[Items->getCA() - 1]->getPrecio());//Agrego el monto solo si no surge ningun error
}


void cTicket::SacarItem(unsigned int id, unsigned int cantidad) {
    if(Items->BuscarPosItemCreado(id,cantidad)!=-1)//Reviso que este para poder quitar el monto
        CalcularMontoTotal(false, (*Items)[Items->getCA() - 1]->getPrecio());
    Items->Eliminar(id, cantidad);
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

void cTicket::operator+(cItem* otro)
{
    this->CrearItem(otro, otro->Cantidad);   
}

bool cTicket::getAbonado()
{
    return Abonado;
}

void cTicket::setAbonado()
{
    Abonado = true;
}

bool cTicket::getEfectivo()
{
    return Efectivo;
}

ostream& operator<<(ostream& out, cTicket& T)
{
    out << "\nAbonado: " << bool_to_string(T.Abonado) << tm_to_string(T.FechayHora) << "ID: " << T.ID << "\nPago en efectivo: " << bool_to_string(T.Efectivo) << "\nMonto total: " << T.MontoTotal << endl;
    return out;
}
