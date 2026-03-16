#ifndef RECTANGULO_H
#define RECTANGULO_H

#include "Figura.h"
#include <string>

class Rectangulo : public Figura {
private:
    double base;   // double se usa para números con decimales
    double altura;

public:
    // Constructor
    Rectangulo(std::string nombre, double base, double altura);

    // Destructor
    ~Rectangulo();

    // Métodos sobrescritos
    double calcularArea() override;
    void describir() override;

    // Getters
    double obtenerBase();
    double obtenerAltura();
};

#endif // RECTANGULO_H
