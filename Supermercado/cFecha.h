#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <string>
using namespace std;
class cFecha
{

	tm fecha;
public:
	//Constructor por default, inicia en la fecha y hora de hoy
	cFecha();
	//Constructor inicia en dia, mes, año, hora
	cFecha(int d, int m, int a,int h,int min);
	string tm_to_string();
};

