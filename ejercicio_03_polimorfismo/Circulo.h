#ifndef CIRCULO_H
#define CIRCULO_H

#include "Figura.h"
#include <string>

class Circulo : public Figura {
private:
    double radio;

public:
    // Constructor
    Circulo(std::string nombre, double radio);

    // Destructor
    ~Circulo();

    // Métodos sobrescritos
    double calcularArea() override;
    void describir() override;

    // Getter
    double obtenerRadio();
};

#endif // CIRCULO_H