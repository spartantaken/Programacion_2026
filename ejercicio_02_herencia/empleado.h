#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <iostream>
#include <string>
#include <iomanip>

class Empleado {
protected:
    std::string nombre;
    std::string id;
    float salarioBase;

public:
    // Constructor por defecto
    Empleado();

    // Constructor con parámetros
    Empleado(std::string n, std::string i, float s);

    virtual void mostrarInformacion() const;
    virtual float calcularSalarioTotal() const;

    virtual ~Empleado() {}
};

#endif