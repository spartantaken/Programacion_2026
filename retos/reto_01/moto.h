#ifndef MOTO_H
#define MOTO_H

#include <string>
#include "vehiculo.h"

class Moto : public Vehiculo {
private:
    int cilindrada;
    int numeroEjes;

public:
    //constructores
    Moto();
    Moto(std::string marca, std::string modelo, std::string placa,
         int anio, int cilindrada, int numeroEjes);

    //metodos para actualizar
    void actualizarCilindrada(int nuevaCilindrada);
    void actualizarNumeroEjes(int nuevoNumeroEjes);
    //sobrescritura del metodo de la clase base
    void mostrarInformacion();
    //getter
    int obtenerCilindrada();
    int obtenerNumeroEjes();
};
#endif // MOTO_H