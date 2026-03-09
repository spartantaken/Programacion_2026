#ifndef MOTO_H
#define MOTO_H

#include <string>
#include "vehiculo.h"

class Moto : public Vehiculo {
    int Cilindrada;

public:
    // constructores
    Moto();
    Moto(std::string marca, std::string modelo, int anio,
         std::string tipolicencia, std::string placas,
         int cilindrada);
        
    //métodos para actualizar 
    void actualizarCilindrada(int nuevaCilindrada);

    //sobrescritura del método de la clase base
    void mostrarInformacion();

    //Getter
    int obtenerCilindrada();

};

#endif // MOTO_H
