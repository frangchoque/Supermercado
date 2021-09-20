#include "cListaCajas.h"

cListaCajas::cListaCajas(int tam)
{
	this->Tam = tam;
	Cupo = 0;
	cajas = new cCaja*[tam];
	for (int i = 0; i < tam; i++) { cajas[i] = NULL; }
}

cCaja* cListaCajas::operator[](unsigned int pos)
{
	return Buscar_por_Pos(pos);
}

cListaCajas::~cListaCajas()
{
	if (cajas != NULL)
	{
		for (int i = 0; i < Cupo; i++)
		{
			if (cajas[i] != NULL)
				delete cajas[i];
		}
		delete[] cajas;
	}
}

int cListaCajas::PosCaja(unsigned int id)
{
	for (int i = 0; i < Cupo; i++) {
		if (cajas[i]->getID() == id)
			return i;
	}
	return -1;//Si no lo encuentra
}

cCaja* cListaCajas::Buscar_por_Pos(unsigned int pos)
{
	if (pos <= Cupo) { 
		return cajas[pos]; 
	}
	else 
		throw new exception("Elemento invalido");
	//Si intenta ingresar un numero mayo a Cupo. Como es unsigned int, no puede ingresar un numero menor a 0
}

void cListaCajas::Eliminar(cCaja* caja){
	cCaja* aux = NULL;
	try {
		aux = Quitar(caja->getID());//Reciclo el codigo de Quitar que de paso revisa todos los errores que pueden ocurrir
	}
	catch (exception* error)
	{
		throw error;
	}
	delete aux;
}

cCaja* cListaCajas::Quitar(unsigned id)
{
	cCaja* aux = BuscarIDcaja(id);//Ya tengo un puntero a cajas[pos]
	if (aux == NULL)
		throw new exception("No se encuentra en la lista");
	int pos = PosCaja(aux->getID());
	for (int i = pos; i < Cupo - 1; i++) {
		cajas[i] = cajas[i + 1];//Desplazo todos los elementos para que ocupen el lugar vacio
	}
	Cupo--;
	return aux;

}

void cListaCajas::AgregarCaja(cCaja* caja)//No se amplia la lista porque es muy raro que eso suceda en la vida real
{
	if (Cupo >= Tam)//Reemplaza a Cupo > Tam || Cupo == Tam
	{
		throw exception("La lista esta llena"); //Lo controlo al principio
	}
	if (caja == NULL)
		throw new exception("Error. Puntero cCaja NULL");

	//Si llego hasta este punto, no deberia haber problemas
	cajas[Cupo] = caja;
	Cupo++;
	
	/*if (caja != NULL) {

		if (Tam > Cupo) {
			cajas[Cupo] = caja;
			Cupo++;
		}
		if (Cupo > Tam || Cupo == Tam) { throw exception("La lista esta llena"); }
	}*/

}

cCaja* cListaCajas::BuscarIDcaja(unsigned int id)
{
	for (int i = 0; i < Cupo; i++) {
		if (cajas[i]->getID() == id) { return cajas[i]; }
		else return NULL;//no se encontro 
	}
}

unsigned int cListaCajas::getCupo()
{
	return Cupo;
}