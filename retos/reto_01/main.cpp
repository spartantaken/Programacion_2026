/*
 * Instrucciones de Compilación:
 *
 * Para compilar este programa, utiliza el siguiente comando:
 *
 *     g++ vehiculo.cpp coche.cpp main.cpp -o herencia
 *
 * O si prefieres usar la opción de estándar C++17:
 *
 *     g++ -std=c++17 vehiculo.cpp coche.cpp main.cpp -o herencia
 *
 * Para ejecutar el programa:
 *
 *     ./herencia
 */

#include <iostream>
#include "vehiculo.h"
#include "coche.h"

int main() {
    std::cout << "=== Ejemplo de herencia: Vehiculo y Coche ===" << std::endl;
    std::cout << std::endl;

    // Crear un vehículo (clase base)
    Vehiculo vehiculo1("Ford", "F-150", 2019);
    std::cout << "Vehículo 1 (clase base):" << std::endl;
    vehiculo1.mostrarInformacion();
    std::cout << std::endl;

    // Crear un coche usando el constructor por defecto
    Coche coche1;
    std::cout << "Coche 1 (constructor por defecto):" << std::endl;
    coche1.mostrarInformacion();
    std::cout << std::endl;

    // Actualizar los valores del coche1 (hereda setters de Vehiculo + propio)
    coche1.actualizarMarca("Toyota");
    coche1.actualizarModelo("Corolla");
    coche1.actualizarAnio(2022);
    coche1.actualizarNumeroPuertas(4);

    std::cout << "Coche 1 después de actualizar:" << std::endl;
    coche1.mostrarInformacion();
    std::cout << std::endl;

    // Crear un coche usando el constructor con parámetros
    Coche coche2("Honda", "Civic", 2020, 4);
    std::cout << "Coche 2 (constructor con parámetros):" << std::endl;
    coche2.mostrarInformacion();
    std::cout << std::endl;

    // Demostrar que Coche hereda los getters de Vehiculo
    std::cout << "Acceso a miembros heredados (Coche 2):" << std::endl;
    std::cout << "  Marca (heredado): " << coche2.obtenerMarca() << std::endl;
    std::cout << "  Modelo (heredado): " << coche2.obtenerModelo() << std::endl;
    std::cout << "  Año (heredado): " << coche2.obtenerAnio() << std::endl;
    std::cout << "  Puertas (propio): " << coche2.obtenerNumeroPuertas() << std::endl;
    std::cout << std::endl;

    // Modificar solo el número de puertas del coche2
    coche2.actualizarNumeroPuertas(2);
    std::cout << "Coche 2 después de cambiar a 2 puertas:" << std::endl;
    coche2.mostrarInformacion();

    return 0;
}
