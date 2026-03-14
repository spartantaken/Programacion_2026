#ifndef RECTANGULO_H
#define RECTANGILO_H
#include "Figura.h"
#include <iostream>

class Rectangulo : public Figura {
    private:
        double base; //double es utiliza para números con decimales y int para numeros enteros 
        double altura;
    //constructores
        public:
        Rectangulo(std::string nombre, double base, double altura);
        ~Rectangulo();
        double calcularArea() override;
        void describir() override;

        double obtenerBase();
        double obtenerAltura();
};

#endif // RECTANGULO_H
