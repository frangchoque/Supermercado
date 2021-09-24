#include "cFecha.h"

cFecha::cFecha()
{

	time_t now = time(0);
	tm* time = localtime(&now);
	fecha = *time;

}

cFecha::cFecha(int d, int m, int a,int h,int min)
{
	fecha.tm_hour = h;
	fecha.tm_min = min;
	fecha.tm_sec = 0;
	fecha.tm_mday = d;
	fecha.tm_mon = m - 1;
	fecha.tm_year = a - 1900;
	fecha.tm_wday = 0;
	fecha.tm_yday = 0;
	fecha.tm_isdst = 0;

}

string cFecha::tm_to_string()
{
	return "\n Fecha: " + std::to_string(fecha.tm_mday) + "/" + std::to_string(fecha.tm_mon + 1) + "/" + std::to_string(fecha.tm_year + 1900);
	return "Hora: " + std::to_string(fecha.tm_hour) + ":" + std::to_string(fecha.tm_min) + ":" + std::to_string(fecha.tm_sec) + "\n";
}





