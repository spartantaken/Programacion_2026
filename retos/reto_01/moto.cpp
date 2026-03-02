#include "moto.h"
#include <iostream>

//constructor por defecto
moto::moto() : Vehiculo(){
    numeroPuertas = 0;
} 
//constructor con parametros
moto::moto(std::string marca , std::string modelo, int anio, int numeroPuertas)
    : Vehiculo(marca, modelo, anio) {
    this->numeroPuertas = numeroPuertas;
}

//motodo para actualizar 
void moto::actualizarNumeroPuertas(int nuevoNumero) {
    numeroPuertas = nuevoNumero;
}

//Sobrescritura: reutiliza el método de la base y añade información del coche
void moto::mostrarInformacion(){
    Vehiculo::mostrarInformacion();
    std::cout << "Numero de puertas: " << numeroPuertas << std::endl;
}
//getter
int moto::obtenerNumeroPuertas(){
    return numeroPuertas;
}