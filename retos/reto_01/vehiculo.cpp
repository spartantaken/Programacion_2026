#include "vehiculo.h"
#include <iostream>

// Constructor por defecto
Vehiculo::Vehiculo() {
    marca = "";
    modelo = "";
    anio = 0;
    tipo_licencia = "";
    placas = "";
}

// Constructor con parámetros
Vehiculo::Vehiculo(std::string marca, std::string modelo, int anio,
                   std::string tipo_licencia, std::string placas) {
    this->marca = marca;
    this->modelo = modelo;
    this->anio = anio;
    this->tipo_licencia = tipo_licencia;
    this->placas = placas;
}

// Métodos para actualizar
void Vehiculo::actualizarMarca(std::string nuevaMarca) {
    marca = nuevaMarca;
}

void Vehiculo::actualizarModelo(std::string nuevoModelo) {
    modelo = nuevoModelo;
}

void Vehiculo::actualizarAnio(int nuevoAnio) {
    anio = nuevoAnio;
}

// Método para mostrar
void Vehiculo::mostrarInformacion() {
    std::cout << "Marca: " << marca << std::endl;
    std::cout << "Modelo: " << modelo << std::endl;
    std::cout << "Año: " << anio << std::endl;
    std::cout << "Tipo de licencia: " << tipo_licencia << std::endl;
    std::cout << "Placas: " << placas << std::endl;
}

// Getters
std::string Vehiculo::obtenerMarca() {
    return marca;
}

std::string Vehiculo::obtenerModelo() {
    return modelo;
}

int Vehiculo::obtenerAnio() {
    return anio;
}

// actualizadores adicionales
void Vehiculo::actualizarTipoLicencia(std::string nuevaTipoLicencia) {
    tipo_licencia = nuevaTipoLicencia;
}

void Vehiculo::actualizarPlacas(std::string nuevasPlacas) {
    placas = nuevasPlacas;
}

// getters adicionales
std::string Vehiculo::obtenerTipoLicencia() {
    return tipo_licencia;
}

std::string Vehiculo::obtenerPlacas() {
    return placas;
}
