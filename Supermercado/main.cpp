//Falta agreagar Imprimir y to_string en las clases
#define _CRT_SECURE_NO_WARNINGS
#include "cSupermercado.h"
#include "cItem.h"
#include "cArticulo.h"
#include "cCaja.h"
#include "cTicket.h"

int main() {
	cArticulo* Queso = new cArticulo("La paulina", "Queso rayado", 249.99);
	cItem* Compra = new cItem(2, Queso);
	cTicket* pCompra = NULL;
	cCaja* pCaja = new cCaja(5000);
	cSupermercado* Kiosko = new cSupermercado();

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
		pCaja->CrearTicket(true);//No debe funcionar
	}
	catch (exception* error)
	{
		cout << error->what() << endl;
		delete error;
	}
	try
	{
		pCaja->EmitirTicket(pCompra);//No debe funcionar
	}
	catch (exception* error)
	{
		cout << error->what() << endl;
		delete error;
	}
	
	pCaja->Abrir();//Abro la caja

	try
	{
		pCaja->CrearTicket(true);//Creo un ticket
	}
	catch (exception* error)
	{
		cout << error->what() << endl;
		delete error;
	}

	pCompra = pCaja->getTicketLista(1);//Lo asigno a un puntero para que sea mas facil trabajar

	try {
		pCompra->CrearItem(Compra, Compra->getCantidad());//Tiene que agregarlo
	}
	catch (exception* error)
	{
		cout << error->what() << endl;
		delete error;
	}

	Compra = NULL;

	try {
		pCompra->CrearItem(Compra, Compra->getCantidad());//Tiene que tirar error
	}
	catch (exception* error)
	{
		cout << error->what() << endl;
		delete error;
	}
	try {
		pCompra->SacarItem(20,0);//Tiene que tirar error
	}
	catch (exception* error)
	{
		cout << error->what() << endl;
		delete error;
	}
	Compra = new cItem(3, new cArticulo("ABC", "Cuaderno", 499.99));
	try {
		pCompra->CrearItem(Compra, Compra->getCantidad());//Tiene que agregarlo
	}
	catch (exception* error)
	{
		cout << error->what() << endl;
		delete error;
	}
	try {
		pCompra->SacarItem(Compra->getArticuloID(), Compra->getCantidad());//Funciona
	}//Cuando lo saco, lo elimino
	catch (exception* error)
	{
		cout << error->what() << endl;
		delete error;
	}
	//Creo otro item
	Compra = new cItem(3, new cArticulo("ABC", "Libro", 799.99));
	try {
		pCompra->CrearItem(Compra, Compra->getCantidad());//Tiene que agregarlo
	}
	catch (exception* error)
	{
		cout << error->what() << endl;
		delete error;
	}

	try
	{
		pCaja->EmitirTicket(pCompra);//Funciona
	}
	catch (exception* error)
	{
		cout << error->what() << endl;
		delete error;
	}
	


	pCompra->Imprimir();
	Queso->Imprimir();
	Compra->Imprimir();

	delete Queso;
	delete Compra;
	return 0;
}