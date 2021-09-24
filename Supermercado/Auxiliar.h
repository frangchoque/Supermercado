#pragma once
#include <string>

using namespace std;

string tm_to_string(tm fecha);

string bool_to_string(bool booleano);

bool operator==(tm& T1, tm& T2);