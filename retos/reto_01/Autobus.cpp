#include "Autobus.h"
#include <iostream>

Autobus::Autobus() : Vehiculo() {
    cilindrada = 0;
    numeroEjes = 0;
    numeroPuertas = 0;
}
//constructor de parametros
Autobus::Autobus(std::string marca, std::string modelo,
                 int anio, std::string tipoLicencia,
                 std::string placas,
                 int cilindrada, int numeroEjes,
                 int numeroPuertas)
    : Vehiculo(marca, modelo, anio, tipoLicencia, placas),
      cilindrada(cilindrada),
      numeroEjes(numeroEjes),
      numeroPuertas(numeroPuertas)
      //lista
{
}
//metodo para actualizar
void Autobus::actualizarNumeroPuertas(int nuevoNumero) {
    numeroPuertas = nuevoNumero;
}
void Autobus::actualizarCilindrada(int nuevaCilindrada) {
    cilindrada = nuevaCilindrada;
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