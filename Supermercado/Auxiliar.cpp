#include "Auxiliar.h"
string tm_to_string(tm fecha)
{
	return "Fecha: " + std::to_string(fecha.tm_mday) + "/" + std::to_string(fecha.tm_mon + 1) + "/" + std::to_string(fecha.tm_year + 1900) + "\n" +
		"Hora: " + std::to_string(fecha.tm_hour)+ ":" + std::to_string(fecha.tm_min)+ ":" + std::to_string(fecha.tm_sec)+"\n";
}

string bool_to_string(bool booleano)
{
	if (booleano == true)
		return "Si";
	else
		return "No";
}