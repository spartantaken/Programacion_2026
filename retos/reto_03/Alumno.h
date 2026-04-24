#ifndef ALUMNO_H
#define ALUMNO_H
#include "persona.h"
#include <string>

class Alumno : public persona {
private:
    float notaFinal;

public:
    Alumno(std::string , int, float);
    void mostrar();   
};

#endif 