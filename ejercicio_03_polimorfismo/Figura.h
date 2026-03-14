#ifndef FIGURA_H
#define FIGURA_H
#include <string>

class Figura{
    protected:
        std::string nombre;
    
    //constructores
    public:
    Figura(std::string nombre);
    virtual ~Figura();
    //métodos virtuales puros
    virtual double calcularArea()=0;
    virtual void describir()=0;
    std::string obtenerNombre();
};

#endif // FIGURA_H