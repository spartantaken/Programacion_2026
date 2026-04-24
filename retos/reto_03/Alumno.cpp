#include "Alumno.h"
#include <iostream>
using namespace std;


Alumno::Alumno(string _nombre, int _edad, float _notaFinal) : persona(_nombre, _edad) {
    notaFinal = _notaFinal;
}

void Alumno::mostrar() {
    persona::mostrar();
    cout << "Nota Final: " << notaFinal << endl;
}


