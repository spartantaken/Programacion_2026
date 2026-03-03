#ifndef COCHE_H
#define COCHE_H

#include <string>
#include "vehiculo.h"

class Coche : public Vehiculo {
private:
    int numeroPuertas;
    int cilindrada;
    int numeroEjes;

public:
    // Constructores
    Coche();
    Coche(std::string marca, std::string modelo,int anio, 
           std::string tipoLicencia,  std::string placa,
           int cilindrada, int numeroEjes, int numeroPuertas);

    // Métodos para actualizar
    void actualizarNumeroPuertas(int nuevoNumero);
    void actualizarCilindrada(int nuevaCilindrada);
    void actualizarNumeroEjes(int nuevoNumeroEjes);

    // Sobrescritura del método de la clase base
    void mostrarInformacion();

    // Getter
    int obtenerNumeroPuertas();
    int obtenerCilindrada();
    int obtenerNumeroEjes();
};

#endif // COCHE_H
