#include "Circulo.h"
#include <iostream>

Circulo::Circulo(std::string nombre, double radio)
      : Figura(nombre) {
        this->radio = radio;
      }

      double Circulo::calcularArea(){
        return 3.14159 * radio * radio; 
}

void Circulo::describir(){
    std::cout << "figura: "<< nombre << std::endl;
    std::cout << "Radio: " << radio << std::endl;
}

double Circulo::obtenerRadio(){
    return radio;
}