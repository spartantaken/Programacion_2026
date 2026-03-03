#include "vehiculo.h"
#include <iostream>

Vehiculo::Vehiculo() : marca(""), modelo(""), anio(0), tipolicencia(""), placas("") {}

Vehiculo::Vehiculo(std::string marca, std::string modelo, int anio,
                   std::string tipolicencia, std::string placas) {
    this->marca = marca;
    this->modelo = modelo;
    this->anio = anio;
    this->tipolicencia = tipolicencia;
    this->placas = placas;
}

void Vehiculo::actualizarMarca(std::string nuevaMarca) { marca = nuevaMarca; }
void Vehiculo::actualizarModelo(std::string nuevoModelo) { modelo = nuevoModelo; }
void Vehiculo::actualizarAnio(int nuevoAnio) { anio = nuevoAnio; }
void Vehiculo::actualizarTipoLicencia(std::string nuevaTipo) { tipolicencia = nuevaTipo; }
void Vehiculo::actualizarPlacas(std::string nuevasPlacas) { placas = nuevasPlacas; }

void Vehiculo::mostrarInformacion() {
    std::cout << "Marca: " << marca << "\nModelo: " << modelo << "\nAño: " << anio 
              << "\nTipo de licencia: " << tipolicencia << "\nPlacas: " << placas << std::endl;
}

std::string Vehiculo::obtenerMarca() { return marca; }
std::string Vehiculo::obtenerModelo() { return modelo; }
int Vehiculo::obtenerAnio() { return anio; }
std::string Vehiculo::obtenerTipoLicencia() { return tipolicencia; }
std::string Vehiculo::obtenerPlacas() { return placas; }