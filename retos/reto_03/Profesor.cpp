#include "Profesor.h"
#include <iostream>
using namespace std;


Profesor::Profesor(string _nombre, int _edad, string _materia) : persona(_nombre, _edad) {
    materia = _materia;
}

void Profesor::mostrar() {
    persona::mostrar();
    cout << "Materia: " << materia << endl;
}
