#include "moto.h"
#include <iostream>

// Constructor por defecto
Moto::Moto() : Vehiculo() {
    cilindrada = 0;
    numeroEjes = 0;
    numeroPuertas = 0; // Por defecto, las motos no tienen puertas
    tipolicencia = "tipo M (Motociclista)";
}
// Constructor con parámetros (7 parámetros)
Moto::Moto(std::string marca, std::string modelo,
                 int anio, std::string placas,
                 int cilindrada, int numeroEjes,
                 int numeroPuertas)
    : Vehiculo(marca, modelo, anio, "tipo M (Motociclista)", placas),
      cilindrada(cilindrada),
      numeroEjes(numeroEjes),
      numeroPuertas(numeroPuertas)
{
}

void Moto::actualizarNumeroPuertas(int nuevoNumero) {
    numeroPuertas = nuevoNumero; 
}

void Moto::actualizarCilindrada(int nuevaCilindrada) {
    cilindrada = nuevaCilindrada;
}

void Moto::actualizarNumeroEjes(int nuevoNumeroEjes) {
    numeroEjes = nuevoNumeroEjes;
}
//sobrescritura
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
