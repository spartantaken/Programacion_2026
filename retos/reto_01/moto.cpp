#include "moto.h"
#include <iostream>

//constructor por defecto
Moto::Moto() : Vehiculo(){
    cilindrada = 0;
    numeroEjes = 0;
} 
//constructor con parametros
Moto::Moto(std::string marca , std::string modelo, std::string placa, int anio, int cilindrada, int numeroEjes)
    : Vehiculo(marca, modelo, anio, "B", placa), cilindrada(cilindrada), numeroEjes(numeroEjes) {
    // inicializado en la lista
}

//motodo para actualizar 
void Moto::actualizarCilindrada(int nuevaCilindrada) {
    cilindrada = nuevaCilindrada;
}

void Moto::actualizarNumeroEjes(int nuevoNumeroEjes){
    numeroEjes = nuevoNumeroEjes;
}
//Sobrescritura: reutiliza el método de la base y añade información del coche
void Moto::mostrarInformacion(){
    Vehiculo::mostrarInformacion();
    std::cout << "Cilindrada: " << cilindrada << std::endl;
    std::cout << "Número de ejes: " << numeroEjes << std::endl;
}
//getter
int Moto::obtenerCilindrada(){
    return cilindrada;
}
int Moto::obtenerNumeroEjes(){
    return numeroEjes;
}