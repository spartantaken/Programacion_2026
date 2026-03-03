#ifndef AUTOBUS_H
#define AUTOBUS_H

#include <string>
#include "vehiculo.h"

class Autobus : public Vehiculo {
private:
  int numeroPuertas;
  int cilindrada;
  int numeroEjes;

public:
//construtores
  Autobus();
 Autobus(std::string marca, std::string modelo,
        int anio, std::string tipoLicencia,
        std::string placas,
        int cilindrada, int numeroEjes,
        int numeroPuertas);
    //Métodos para actualizar
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
#endif // AUTOBUS_H 