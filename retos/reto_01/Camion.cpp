#include "Camion.h"
#include <iostream>

// Constructor por defecto: llama al constructor por defecto de Vehiculo
Camion::Camion() : Vehiculo () {
    cilindrada = 0;
    numeroEjes = 0;
    numeroPuertas = 0;
    tipolicencia = "C (camionero)";
}

// Constructor con parámetros
Camion::Camion(std::string marca, std::string modelo,
              int anio, std::string placas,
             int cilindrada, int numeroEjes,
             int numeroPuertas)
    :Vehiculo(marca, modelo, anio, "C (camionero)", placas),
     cilindrada(cilindrada), 
     numeroEjes(numeroEjes),
     numeroPuertas(numeroPuertas)
{
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
    std::cout << "Cilindrada: " << cilindrada << std::endl;
    std::cout << "Numero de ejes: " << numeroEjes << std::endl;
    std::cout << "Numeros de puertas: " << numeroPuertas << std::endl;
}

// Getter
int Camion::obtenerCilindrada(){
    return cilindrada;
}
int Camion::obtenerNumeroEjes(){
    return numeroEjes;
}
int Camion::obtenerNumeroPuertas(){
    return numeroPuertas;
}
