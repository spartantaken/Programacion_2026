#include "Autobus.h"
#include <iostream>

//constructor por defecto
Autobus::Autobus() : Vehiculo() {
    cilindrada = 0;
    numeroEjes = 0;
    numeroPuertas = 0;
    tipolicencia = "Tipo c (trasporte publico)";
}
//constructor de parametros
Autobus::Autobus(std::string marca, std::string modelo,
                 int anio, std::string placas,
                 int cilindrada, int numeroEjes,
                 int numeroPuertas, int asientos)
    : Vehiculo(marca, modelo, anio, "Tipo c (trasporte publico)", placas),
      cilindrada(cilindrada),
      numeroEjes(numeroEjes),
      numeroPuertas(numeroPuertas),
      asientos(asientos)
{
}
//metodo para actualizar
void Autobus::actualizarNumeroPuertas(int nuevoNumero) {
    numeroPuertas = nuevoNumero;
}
void Autobus::actualizarCilindrada(int nuevaCilindrada) {
    cilindrada = nuevaCilindrada;
}
void Autobus::actualizarAsientos(int nuevosAsientos) {
    asientos = nuevosAsientos;
}

void Autobus::actualizarNumeroEjes(int nuevoNumeroEjes){
    numeroEjes = nuevoNumeroEjes;
}
//sobrescritura
void Autobus::mostrarInformacion() {
    Vehiculo::mostrarInformacion();
    std::cout << "Cilindrada: " << cilindrada << std::endl;
    std::cout << "Numero de ejes: " << numeroEjes << std::endl;
    std::cout << "Numero de puertas: " << numeroPuertas << std::endl;
    std::cout << "Asientos: " << asientos << std::endl;
}

//getter
int Autobus::obtenerCilindrada(){
    return cilindrada;
}
int Autobus::obtenerNumeroEjes(){
    return numeroEjes;
}
int Autobus::obtenerNumeroPuertas(){
    return numeroPuertas;
}
int Autobus::obtenerAsientos(){
    return asientos;
}