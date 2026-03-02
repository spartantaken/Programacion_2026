#ifndef MOTO_H
#define MOTO_H

#include <string>
#include "vehiculo.h"

class moto : public Vehiculo {
private:
    int numeroPuertas;


public:
    //constructores
    moto();
    moto(std::string marca, std::string modelo, int anio, int numeroPuertas);

    //metodos para actualizar
    void actualizarNumeroPuertas(int nuevoNumero);
    //sobrescritura del metodo de la clase base
    void mostrarInformacion();
    //getter
    int obtenerNumeroPuertas();
};
#endif // MOTO_H