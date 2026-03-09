#include "Camion.h"
#include <iostream>

//constructor por defecto
Camion::Camion() : Vehiculo() {
    capacidadCarga = 0;
}

//constructor con parámetros
Camion::Camion(std::string marca, std::string modelo, int anio,
              std::string tipolicencia, std::string placas, int capacidadCarga)
              : Vehiculo(marca, modelo, anio, tipolicencia, placas) {
     this->capacidadCarga = capacidadCarga;    
}

//método para actualizar
void Camion::actualizarCapacidadCarga(int nuevaCapacidad) {
    capacidadCarga = nuevaCapacidad;
}

//sobrescritura del método de la clase base
void Camion::mostrarInformacion() {
    Vehiculo::mostrarInformacion();
    std::cout << "Capacidad de carga: " << capacidadCarga << " kg" << std::endl;
}   

//Getter
int Camion::obtenerCapacidadCarga() {
    return capacidadCarga;
}
