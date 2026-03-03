#include "moto.h"
#include <iostream>

// Constructor por defecto
Moto::Moto() : Vehiculo() {
    cilindrada = 0;
    numeroEjes = 0;
    numeroPuertas = 0; // Por defecto, las motos no tienen puertas
}

// Constructor con parámetros (7 parámetros)
Moto::Moto(std::string marca, std::string modelo,
                 int anio, std::string tipoLicencia,
                 std::string placas,
                 int cilindrada, int numeroEjes,
                 int numeroPuertas)
    : Vehiculo(marca, modelo, anio, tipoLicencia, placas),
      cilindrada(cilindrada),
      numeroEjes(numeroEjes),
      numeroPuertas(numeroPuertas)
{
}

void Moto::actualizarCilindrada(int nuevaCilindrada) {
    cilindrada = nuevaCilindrada;
}

void Moto::actualizarNumeroEjes(int nuevoNumeroEjes) {
    numeroEjes = nuevoNumeroEjes;
}

void Moto::actualizarNumeroPuertas(int nuevoNumeroPuertas) {
    numeroPuertas = nuevoNumeroPuertas;
}

int Moto::obtenerNumeroPuertas() {
    return numeroPuertas;
}

int Moto::obtenerCilindrada() {
    return cilindrada;
}

int Moto::obtenerNumeroEjes() {
    return numeroEjes;
}

void Moto::mostrarInformacion() {
    Vehiculo::mostrarInformacion();
    std::cout << "Cilindrada: " << cilindrada << std::endl;
    std::cout << "Numero de ejes: " << numeroEjes << std::endl;
    std::cout << "Numero de puertas: " << numeroPuertas << std::endl;
}

//getter
int Moto::obtenerCilindrada(){
    return cilindrada;
}
int Moto::obtenerNumeroEjes(){
    return numeroEjes;
}
int Moto::obtenerNumeroPuertas(){
    return numeroPuertas;
}
