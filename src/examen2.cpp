#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>
#include <thread>

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

struct Coordenada {
    int cap;
    string geo;
    string tipo_arsenal;
    Coordenada* izq;
    Coordenada* der;
};

void WMagregarCoordenada(Coordenada* &raiz, int cap, string geo, string tipo_arsenal) {
    if (raiz == NULL) {
        raiz = new Coordenada;
        raiz->cap = cap;
        raiz->geo = geo;
        raiz->tipo_arsenal = tipo_arsenal;
        raiz->izq = NULL;
        raiz->der = NULL;
    }
    else if (cap < raiz->cap) {
        WMagregarCoordenada(raiz->izq, cap, geo, tipo_arsenal);
    }
    else if (cap > raiz->cap) {
        WMagregarCoordenada(raiz->der, cap, geo, tipo_arsenal);
    }
    // Si la capacidad es igual, se descarta la coordenada repetida
}

void WMcargarCoordenadas(string nombre_archivo, Coordenada* &raiz) {
    ifstream archivo(nombre_archivo);
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo" << endl;
        return;
    }
    string linea;
    int contador = 0;
    while (getline(archivo, linea)) {
        // Mostrar loading de carga
        cout << "Loading: " << contador << "%" << endl;
        for (int i = 0; i <= contador; i++) {
            cout << "=";
        }
        for (int i = contador + 1; i <= 100; i++) {
            cout << " ";
        }
        cout << "|" << endl;
        contador += 10;
        // Leer la línea y validar si es una coordenada
        istringstream ss(linea);
        int cap;
        string geo;
        string tipo_arsenal;
        if (ss >> cap >> geo >> tipo_arsenal) {
            // Si es una coordenada, agregarla al árbol binario
            WMagregarCoordenada(raiz, cap, geo, tipo_arsenal);
            cout << "\033[32m" << linea << "\033[0m" << endl; // Mostrar en color verde
        }
        else {
            // Si no es una coordenada, mostrar error en color rojo
            cout << "\033[31m" << "Error en la línea: " << linea << "\033[0m" << endl;
        }
        this_thread::sleep_for(chrono::milliseconds(500)); // Simular una pausa en la carga
    }
    archivo.close();
}

int main() {
    Coordenada* raiz = NULL;
    WMcargarCoordenadas("coordenadas.txt", raiz);
    return 0;
}

void WMInformacion(){
    cout<<"[+] Informacion Arbol Binario de capacidad belica Ucrania"<<endl;
    cout<<"Desarrollador-Nombre : "<<WMGLOBAL_CONST<<endl;;
    cout<<"Desarrollador-Cedula : "<<WMGLOBAL_STRING_CONST<<endl;;
    cout<<"Capacidad Belica : 36"<<endl;
    cout<<"Coordenada Total : 7"<<endl;
    cout<<"Coordenada-SecCarga : 1 7 5 4 2 8 9"<<endl;
}

int main()

{
    WMagregarCoordenada();
    WMcargarCoordenadas();
    WMInformacion();
}