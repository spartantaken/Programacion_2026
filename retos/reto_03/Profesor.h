#ifndef PROFESOR_H
#define PROFESOR_H

#include "persona.h"
#include <string>

class Profesor : public persona {
private:
    std::string materia;

public:
    Profesor(std::string nombre, int edad, std::string materia);
    void mostrar();
};

#endif