#include "autobus.h"
#include <iostream>

//constructor por defecto
Autobus::Autobus() : vehiculo() {
    numeropuertas = 0;
}
//Costructor con parametros 
Autobus::Autobus(std::string marca, std::string modelo, int anio, int numeroPuertas)
    : vehiculo(marca, modelo, anio) {
    this->numeropuertas = numeroPuertas;
}

void Coche::actualizarNumeroPuertas(int nuevoNumero) {
    numeroPuertas = nuevoNumero;
}

// Sobrescritura: reutiliza el método de la base y añade información del coche
void Coche::mostrarInformacion() {
    Vehiculo::mostrarInformacion();
    std::cout << "Número de puertas: " << numeroPuertas << std::endl;
}

// Getter
int Coche::obtenerNumeroPuertas() {
    return numeroPuertas;
}