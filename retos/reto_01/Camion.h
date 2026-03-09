#ifndef CAMION_H
#define CAMION_H

#include <string>
#include "vehiculo.h"

class Camion : public Vehiculo {
    int capacidadCarga;

public:
    //constructores 
    Camion();
    Camion(std::string marca, std::string modelo, int anio,
           std::string tipolicencia, std::string placas,
           int capacidadCarga);

    //método para actualizar
    void actualizarCapacidadCarga(int nuevaCapacidad);
        

    //sobrescritura del método de la clase base
    void mostrarInformacion();  
        
    //Getter
    int obtenerCapacidadCarga();
        
};

#endif // CAMION_H