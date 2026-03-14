#include "Figura.h"
#include <iostream>

Figura::Figura(std::string nombre) {
    this->nombre = nombre;
}
Figura::~Figura(){
    //destructor vacío
}
std::string Figura::obtenerNombre() {
    return nombre;
}