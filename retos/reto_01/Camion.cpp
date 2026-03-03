#include "Camion.h"
#include <iostream>

// Constructor por defecto: llama al constructor por defecto de Vehiculo
Camion::Camion() : Vehiculo () {
    numeroEjes = 0;
    numeroPuertas = 0;
    cilindrada = 0;
}

// Constructor con parámetros
Camion::Camion(std::string marca , std::string modelo, std::string placa, int anio,
                 int cilindrada, int numeroEjes, int numeroPuertas)
    : Vehiculo(marca, modelo, anio, "C", placa),
      cilindrada(cilindrada), numeroEjes(numeroEjes), numeroPuertas(numeroPuertas) {
    // campos inicializados arriba
}

// Método para actualizar
void Camion::actualizarNumeroPuertas(int nuevoNumero) {
    numeroPuertas = nuevoNumero;
}

void Camion::actualizarCilindrada(int nuevaCilindrada) {
    cilindrada = nuevaCilindrada;
}

void Camion::actualizarNumeroEjes(int nuevoNumeroEjes) {
    numeroEjes = nuevoNumeroEjes;
}

// Sobrescritura: reutiliza el método de la base y añade información del coche
void Camion::mostrarInformacion() {
    Vehiculo::mostrarInformacion();
    std::cout << "Número de puertas: " << numeroPuertas << std::endl;
    std::cout << "Cilindrada: " << cilindrada << std::endl;
    std::cout << "Número de ejes: " << numeroEjes << std::endl;
}

// Getter
int Camion::obtenerNumeroPuertas() {
    return numeroPuertas;
}

int Camion::obtenerCilindrada() {
    return cilindrada;
}

int Camion::obtenerNumeroEjes() {
    return numeroEjes;
}