#include "moto.h"
#include <iostream>

// Constructor por defecto
Moto::Moto() : Vehiculo(){
    Cilindrada = 0;
}

// Constructor con parámetros
Moto::Moto(std::string marca, std::string modelo, int anio,
         std::string tipolicencia, std::string placas, int cilindrada)
         : Vehiculo(marca, modelo, anio, tipolicencia, placas) {
            this->Cilindrada = cilindrada;
}

// Método para actualizar
void Moto::actualizarCilindrada(int nuevaCilindrada){
    Cilindrada = nuevaCilindrada;
}

// sobrescritura
void Moto::mostrarInformacion(){
    Vehiculo::mostrarInformacion();
    std::cout << "cilindrada: " << Cilindrada << std::endl;
}

//Getter
int Moto::obtenerCilindrada(){
    return Cilindrada;
}