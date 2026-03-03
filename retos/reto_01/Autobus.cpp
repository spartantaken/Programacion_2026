#include "Autobus.h"
#include <iostream>

// Constructor por defecto: llama al constructor por defecto de Vehiculo
Autobus::Autobus() : Vehiculo() {
    numeroPuertas = 0;
    cilindrada = 0;
    numeroEjes = 0;
}

// Constructor con parámetros: pasa los datos del vehículo a la base
Autobus::Autobus(std::string marca, std::string modelo, std::string placa,
                 int anio, int cilindrada, int numeroEjes, int numeroPuertas)
    : Vehiculo(marca, modelo, anio, "D", placa),
      cilindrada(cilindrada), numeroEjes(numeroEjes), numeroPuertas(numeroPuertas) {
    // inicializaciones completadas en la lista
}

// Método para actualizar
void Autobus::actualizarNumeroPuertas(int nuevoNumero) {
    numeroPuertas = nuevoNumero;
}

void Autobus::actualizarCilindrada(int nuevaCilindrada) {
    cilindrada = nuevaCilindrada;
}

void Autobus::actualizarNumeroEjes(int nuevoNumeroEjes) {
    numeroEjes = nuevoNumeroEjes;
}

// Sobrescritura: reutiliza el método de la base y añade información del coche
void Autobus::mostrarInformacion() {
    Vehiculo::mostrarInformacion();
    std::cout << "Número de puertas: " << numeroPuertas << std::endl;
    std::cout << "Cilindrada: " << cilindrada << std::endl;
    std::cout << "Número de ejes: " << numeroEjes << std::endl;
}

// Getter
int Autobus::obtenerNumeroPuertas() {
    return numeroPuertas;
}

int Autobus::obtenerCilindrada() {
    return cilindrada;
}

int Autobus::obtenerNumeroEjes() {
    return numeroEjes;
}