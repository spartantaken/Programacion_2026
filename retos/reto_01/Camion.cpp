#include "coche.h"
#include <iostream>

// Constructor por defecto: llama al constructor por defecto de Vehiculo


// Constructor con parámetros: pasa los datos del vehículo a la base
camion::camion(std::string marca, std::string modelo, int anio, int numeroPuertas)
    : Vehiculo(marca, modelo, anio) {
    this->numeroPuertas = numeroPuertas;
}

// Método para actualizar
void camion::actualizarNumeroPuertas(int nuevoNumero) {
    numeroPuertas = nuevoNumero;
}

// Sobrescritura: reutiliza el método de la base y añade información del camion
void camion::mostrarInformacion() {
    Vehiculo::mostrarInformacion();
    std::cout << "Número de puertas: " << numeroPuertas << std::endl;
}

// Getter
int camion::obtenerNumeroPuertas() {
    return numeroPuertas;
}