#include "Autobus.h"
#include <iostream>

//constructor por defecto
Autobus::Autobus() : Vehiculo() {
    numeroPasajeros = 0;
}   

//constructor con parámetros
Autobus::Autobus(std::string marca, std::string modelo, int anio,      
              std::string tipolicencia, std::string placas, int numeroPasajeros)
                : Vehiculo(marca, modelo, anio, tipolicencia, placas) {
     this->numeroPasajeros = numeroPasajeros;
    }

//método para actualizar
void Autobus::actualizarNumeroPasajeros(int nuevoNumero) {
    numeroPasajeros = nuevoNumero;
}

//sobrescritura del método de la clase base
void Autobus::mostrarInformacion() {
    Vehiculo::mostrarInformacion();
    std::cout << "Número de pasajeros: " << numeroPasajeros << std::endl;
}

//Getter
int Autobus::obtenerNumeroPasajeros() {
    return numeroPasajeros;
}
