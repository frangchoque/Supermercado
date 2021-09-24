//Falta agreagar Imprimir y to_string en las clases
#define _CRT_SECURE_NO_WARNINGS
#include "cSupermercado.h"
#include "cItem.h"
#include "cArticulo.h"
#include "cCaja.h"
#include "cTicket.h"
#include "cFecha.h"
#include <ctime>
#include <thread>
#include <chrono>
using std::this_thread::sleep_for;

int main() {
	/*time_t now = time(0);
	tm* time = localtime(&now);
	tm Fecha1 = *time;*/
	cFecha* hoy = new cFecha();
	cFecha* Nov18 = new cFecha(18, 11, 2020, 17, 30);
	cFecha* Marz7 = new cFecha(7, 3, 2021, 9, 0);

	cArticulo* Queso = new cArticulo("La paulina", "Queso rayado", 249.99);
	cItem* Compra = new cItem(2, Queso);
	cTicket* pCompra1 = NULL;
	cTicket* pCompra2 = NULL;
	cCaja* pCaja = new cCaja(Nov18,5000);
	cCaja* pCaja2 = new cCaja(Marz7,10000);//La agrego despues
	cSupermercado* Kiosko = new cSupermercado();
	

	++(*Compra);//Funciona sobracarga pre incremento

	try {
		Kiosko->AgregarCaja(NULL);//No va a funcionar
	}
	catch (exception* error)
	{
		cout << error->what() << endl;
		delete error;
	}
	try {
		Kiosko->AgregarCaja(pCaja);//Funciona
	}
	catch (exception* error)
	{
		cout << error->what() << endl;
		delete error;
	}
	Kiosko->Cerrar();
	try
	{
		pCompra1=pCaja->CrearTicket();//No debe funcionar
	}
	catch (exception* error)
	{
		cout << error->what() << endl;
		delete error;
	}
	try
	{
		pCaja->EmitirTicket(pCompra1,true);//No debe funcionar
	}
	catch (exception* error)
	{
		cout << error->what() << endl;
		delete error;
	}
	Kiosko->Abrir();
	pCaja->Abrir();//Abro la caja

	try
	{
		pCompra2=pCaja->CrearTicket();//Creo un ticket y lo asigno a pCompra2 para trabajar mas facil
	}
	catch (exception* error)
	{
		cout << error->what() << endl;
		delete error;
	}

	//pCompra2 = pCaja->getTicketLista(1);//Lo asigno a un puntero para que sea mas facil trabajar

	try {
		pCompra2->CrearItem(Compra, Compra->getCantidad());//Tiene que agregarlo
	}
	catch (exception* error)
	{
		cout << error->what() << endl;
		delete error;
	}

	pCompra1 = pCompra2;

	try {
		pCompra1->CrearItem(Compra, Compra->getCantidad());//Tiene que agregarlo
	}
	catch (exception* error)
	{
		cout << error->what() << endl;
		delete error;
	}
	try {
		pCompra1->SacarItem(20,0);//Tiene que tirar error
	}
	catch (exception* error)
	{
		cout << error->what() << endl;
		delete error;
	}
	delete Compra; //Borro el puntero
	Compra = NULL;
	Compra = new cItem(3, new cArticulo("ABC", "Cuaderno", 499.99));//Le asigno un nuevo item
	try {
		pCompra1->CrearItem(Compra, Compra->getCantidad());//Tiene que agregarlo
	}
	catch (exception* error)
	{
		cout << error->what() << endl;
		delete error;
	}
	try {
		pCompra1->SacarItem(Compra->getArticuloID(), Compra->getCantidad());//Funciona
	}//Cuando lo saco, lo elimino
	catch (exception* error)
	{
		cout << error->what() << endl;
		delete error;
	}

	delete Compra; //Borro el puntero
	Compra = NULL;
	//Creo otro item
	Compra = new cItem(3, new cArticulo("ABC", "Libro", 799.99));

	try {
		pCompra1->CrearItem(Compra, Compra->getCantidad());//Tiene que agregarlo
	}
	catch (exception* error)
	{
		cout << error->what() << endl;
		delete error;
	}

	try
	{//Revisar si pCaja tiene un puntero a ticket
		pCaja->EmitirTicket(pCompra1,false);//Funciona
	}
	catch (exception* error)
	{
		cout << error->what() << endl;
		delete error;
	}
	
	cout << *pCompra1 << endl;//Funciona sobrecarga <<
	cout << "\n\n" << endl;
	pCompra1->Imprimir();
	cout << "\n\n" << endl;
	Queso->Imprimir();
	cout << "\n\n" << endl;
	Compra->Imprimir();

	//Simulacion de pCaja2

	//sleep_for(2s);//Para que no coincidan las fechas
	//time = localtime(&now);
	//tm Fecha2 = *time;
	pCaja2->Abrir();//Abro la caja

	try
	{
		pCompra1 = pCaja2->CrearTicket();//Funciona
	}
	catch (exception* error)
	{
		cout << error->what() << endl;
		delete error;
	}

	delete Compra; //Borro el puntero
	Compra = NULL;
	//Creo otro item
	Compra = new cItem(5, new cArticulo("Black & Decker", "Podadora", 2799.99));

	try {
		pCompra1->CrearItem(Compra, Compra->getCantidad());//Tiene que agregarlo
	}
	catch (exception* error)
	{
		cout << error->what() << endl;
		delete error;
	}
	Kiosko->Imprimir();
	cout << Kiosko->MejorCajaGanancias(Nov18) << endl;
	cout << Kiosko->MejorCajaTickets(Nov18) << endl;
	cout << Kiosko->MejorCajaTickets(Marz7) << endl;
	cout << Kiosko->MejorCajaGanancias(Marz7) << endl;

	delete Compra;
//	delete Queso;
	delete Kiosko;
	return 0;
}