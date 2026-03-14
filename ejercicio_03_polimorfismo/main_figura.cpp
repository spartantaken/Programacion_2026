#include "Figura.h"
#include "Rectangulo.h"
#include "Circulo.h"
#include <iostream>

int main() {
    std::cout << "=== Sistema de Figuras ===" << std::endl;
    std::cout << std::endl;
    
    //========================
    //Figuras 
    //========================

    Rectangulo rectangulo1("Rectangulo1", 5.0, 3.0);
    std::cout << "Area del " << rectangulo1.obtenerNombre()
              << ": " << rectangulo1.calcularArea() << std::endl;
    rectangulo1.describir();

    Circulo circulo1("Circulo1", 4.0);
    std::cout << "Area del " << circulo1.obtenerNombre()
              << ": " << circulo1.calcularArea() << std::endl;
    circulo1.describir();
}
