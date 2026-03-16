#include "Triangulo.h"
#include <iostream>

Triangulo::Triangulo(std::string nombre, double base, double altura)
    : Figura(nombre) {
    this->base = base;
    this->altura = altura;
}

Triangulo::~Triangulo() {}

double Triangulo::calcularArea() {
    return (base * altura) / 2;
}

void Triangulo::describir() {
    std::cout << "Figura: " << nombre << std::endl;
    std::cout << "Base: " << base << std::endl;
    std::cout << "Altura: " << altura << std::endl;
}

double Triangulo::obtenerBase() {
    return base;
}

double Triangulo::obtenerAltura() {
    return altura;
}