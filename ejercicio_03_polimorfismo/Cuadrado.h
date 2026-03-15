#ifndef CUADRADO_H
#define CUADRADO_H
#include "Figura.h"
#include <iostream>

class Cuadrado : public Figura {
    private:
        double lado;
    public:
    Cuadrado(std::string nombre, double lado);
    ~Cuadrado();
    double calcularArea() override;
    void describir() override;

    double obtenerLado();

};

#endif // CUADRADO_H
