#include "persona.h"
#include <iostream>
using namespace std;

persona::persona(string _nombre, int _edad) {
    nombre = _nombre;
    edad = _edad;
}

void persona::mostrar() {
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << endl;
}
