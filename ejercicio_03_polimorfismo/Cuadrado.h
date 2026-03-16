#ifndef CUADRADO_H
#define CUADRADO_H

#include "Figura.h"
#include <string>

class Cuadrado : public Figura {
private:
    double lado;

public:
    // Constructor
    Cuadrado(std::string nombre, double lado);

    // Destructor
    ~Cuadrado();

    // Métodos sobrescritos
    double calcularArea() override;
    void describir() override;

    // Getter
    double obtenerLado();
};

#endif // CUADRADO_H
