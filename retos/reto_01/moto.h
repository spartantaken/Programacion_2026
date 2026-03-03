#ifndef MOTO_H
#define MOTO_H

#include <string>
#include "vehiculo.h"

class Moto : public Vehiculo {
private:
    int numeroPuertas; // Aunque las motos no tienen puertas, lo dejamos para mantener la estructura
    int cilindrada;
    int numeroEjes;

public:
    Moto();
    Moto(std::string marca,
         std::string modelo,
         int anio,
         std::string tipoLicencia,
         std::string placas,
         int cilindrada,
         int numeroEjes,
         int numeroPuertas = 0); // Por defecto, las motos no tienen puertas
// Métodos para actualizar
    void actualizarNumeroPuertas(int nuevoNumero);
    void actualizarCilindrada(int nuevaCilindrada);
    void actualizarNumeroEjes(int nuevoNumeroEjes);
// Sobrescritura del método de la clase base
    void mostrarInformacion();
//getter
    int obtenerNumeroPuertas();
    int obtenerCilindrada();
    int obtenerNumeroEjes();
};

#endif // MOTO_H