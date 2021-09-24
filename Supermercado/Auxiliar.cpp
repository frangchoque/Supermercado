#include "Auxiliar.h"


string bool_to_string(bool booleano)
{
	if (booleano == true)
		return "Si";
	else
		return "No";
}

bool operator==(tm& T1, tm& T2)
{
	if (T1.tm_min == T2.tm_min && T1.tm_sec == T2.tm_sec)//Para simplificar uso minutos y segundos en lugar de dias meses y años
		return true;
	else
		return false;
}