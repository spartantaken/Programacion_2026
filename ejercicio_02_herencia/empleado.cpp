#include "empleado.h"

Empleado::Empleado() 
    : nombre("Sin nombre"), id("000"), salarioBase(0.0f) {}

Empleado::Empleado(std::string n, std::string i, float s)
    : nombre(n), id(i), salarioBase(s) {}

void Empleado::mostrarInformacion() const {
    std::cout << "Nombre: " << nombre << std::endl;
    std::cout << "ID: " << id << std::endl;
    std::cout << "Salario Base: $"
              << std::fixed << std::setprecision(2)
              << salarioBase << std::endl;
}

float Empleado::calcularSalarioTotal() const {
    return salarioBase;
}