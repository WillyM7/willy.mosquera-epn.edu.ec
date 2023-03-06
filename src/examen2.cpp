#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

const int WMGLOBAL_CONST = 1754217899;
const string WMGLOBAL_STRING_CONST = "Willy Damian Mosquera Galeano";

struct Coordenada {
    int WMcapacidad_bélica;
    string WMgeolocalización;
    string WMdetalle_arsenal;
    Coordenada *izquierda;
    Coordenada *derecha;
};