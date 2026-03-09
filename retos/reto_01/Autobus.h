#ifndef AUTOBUS_H
#define AUTOBUS_H

#include <string>
#include "vehiculo.h"

class Autobus : public Vehiculo {
    int numeroPasajeros;

public:
    //constructores
    Autobus();
    Autobus(std::string marca, std::string modelo, int anio,
            std::string tipolicencia, std::string placas,
            int numeroPasajeros);

    //método para actualizar
    void actualizarNumeroPasajeros(int nuevoNumero);

    //sobrescritura del método de la clase base
    void mostrarInformacion();

    //Getter
    int obtenerNumeroPasajeros();
};

#endif // AUTOBUS_H


