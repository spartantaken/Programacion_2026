#ifndef TRIANGULO_H
#define TRIANGULO_H
#include "Figura.h"
#include <iostream>

class Triangulo : public Figura {
    private:
        double base;
        double altura;
    public:
    Triangulo(std::string nombre,
             double base, double altura);
    ~Triangulo();
    double calcularArea() override;
    void describir() override;

    double obtenerBase();
    double obtenerAltura();
};

#endif // TRIANGULO_H