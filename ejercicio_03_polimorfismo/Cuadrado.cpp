#include "Cuadrado.h"
#include <iostream>

Cuadrado::Cuadrado(std::string nombre, double lado)
    : Figura(nombre) {
        this->lado = lado;
}

double Cuadrado::calcularArea() {
    return lado * lado;
}

void Cuadrado::describir() {
    std::cout << "Figura: " << nombre << std::endl;
    std::cout << "Lado: " << lado << std::endl;
}

double Cuadrado::obtenerLado() {
    return lado;
}
