#include "celular.h"
#include <iostream>

Celular::Celular(std::string marca, std::string modelo, std::string color,
                 int almacenamiento, float tamPantalla, int bateria) {
    this->marca = marca;
    this->modelo = modelo;
    this->color = color;
    this->almacenamiento = almacenamiento;
    this->tamPantalla = tamPantalla;
    this->bateria = bateria;
}

void Celular::mostrarInformacion() {
    std::cout << "Marca: " << marca << std::endl;
    std::cout << "Modelo: " << modelo << std::endl;
    std::cout << "Color: " << color << std::endl;
    std::cout << "Almacenamiento: " << almacenamiento << " GB" << std::endl;
    std::cout << "Pantalla: " << tamPantalla << " pulgadas" << std::endl;
    std::cout << "Bateria: " << bateria << "%" << std::endl;
}

void Celular::llamar(std::string numero) {
    std::cout << "Llamando al numero: " << numero << std::endl;
}

void Celular::cargar(int porcentaje) {
    bateria += porcentaje;
    if (bateria > 100)
        bateria = 100;

    std::cout << "Bateria actual: " << bateria << "%" << std::endl;
}
