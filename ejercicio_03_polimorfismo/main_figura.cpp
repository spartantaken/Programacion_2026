#include "Figura.h"
#include "Rectangulo.h"
#include "Circulo.h"
#include "Triangulo.h"
#include "Cuadrado.h"
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

    Triangulo triangulo1("Triangulo1", 6.0, 4.0);
    std::cout << "Area del " << triangulo1.obtenerNombre()
              << ": " << triangulo1.calcularArea() << std::endl;
    triangulo1.describir();

    Cuadrado cuadrado1("Cuadrado1", 5.0);
    std::cout << "Area del " << cuadrado1.obtenerNombre()
              << ": " << cuadrado1.calcularArea() << std::endl;
    cuadrado1.describir();
}
