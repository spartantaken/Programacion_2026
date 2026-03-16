#ifndef TRIANGULO_H
#define TRIANGULO_H

#include "Figura.h"
#include <string>

class Triangulo : public Figura {
private:
    double base;
    double altura;

public:
    // Constructor
    Triangulo(std::string nombre, double base, double altura);

    // Destructor
    ~Triangulo();

    // Métodos sobrescritos
    double calcularArea() override;
    void describir() override;

    // Getters
    double obtenerBase();
    double obtenerAltura();
};

#endif // TRIANGULO_H