#include "coche.h"
#include <iostream>

// Constructor por defecto: llama al constructor por defecto de Vehiculo
Coche::Coche() : Vehiculo() {
    numeroPuertas = 0;
    cilindrada = 0;
    numeroEjes = 0;
}

// Constructor con parámetros: pasa los datos del vehículo a la base
Coche::Coche(std::string marca , std::string modelo, std::string placa, int anio,
                 int cilindrada, int numeroEjes, int numeroPuertas)
    : Vehiculo(marca, modelo, anio, "A", placa),
      cilindrada(cilindrada), numeroEjes(numeroEjes), numeroPuertas(numeroPuertas) {
    // inicializaciones hechas en la lista
}

// Método para actualizar
void Coche::actualizarNumeroPuertas(int nuevoNumero) {
    numeroPuertas = nuevoNumero;
}

void Coche::actualizarCilindrada(int nuevaCilindrada) {
    cilindrada = nuevaCilindrada;
}

void Coche::actualizarNumeroEjes(int nuevoNumeroEjes) {
    numeroEjes = nuevoNumeroEjes;
}

// Sobrescritura: reutiliza el método de la base y añade información del coche
void Coche::mostrarInformacion() {
    Vehiculo::mostrarInformacion();
    std::cout << "Número de puertas: " << numeroPuertas << std::endl;
    std::cout << "Cilindrada: " << cilindrada << std::endl;
    std::cout << "Número de ejes: " << numeroEjes << std::endl;
}

// Getter
int Coche::obtenerNumeroPuertas() {
    return numeroPuertas;
}

int Coche::obtenerCilindrada() {
    return cilindrada;
}

int Coche::obtenerNumeroEjes() {
    return numeroEjes;
}

