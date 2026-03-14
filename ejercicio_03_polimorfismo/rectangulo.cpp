#include "Rectangulo.h"
#include <iostream> 

Rectangulo::Rectangulo(std::string nombre, double base, double altura)
    : Figura(nombre) {
        this->base = base;
        this->altura = altura;

}

double Rectangulo::calcularArea(){
    return base * altura;
}

void Rectangulo::describir() {
    std::cout << "Figura:" << nombre << std::endl;
    std::cout << "Base: " << base << std::endl;
    std::cout << "Altura: " << altura << std::endl;
}

double Rectangulo::obtenerBase(){
    return base;
}

double Rectangulo::obtenerAltura(){
    return altura;
}