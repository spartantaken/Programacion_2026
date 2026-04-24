#ifndef PERSONA_H
#define PERSONA_H

#include <string>

class persona {
private:
    std::string nombre;
    int edad;

public:
    persona(std::string nombre, int edad);
    virtual void mostrar();
};

#endif
