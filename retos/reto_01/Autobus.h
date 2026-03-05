#ifndef AUTOBUS_H
#define AUTOBUS_H

#include <string>
#include "vehiculo.h"

class Autobus : public Vehiculo {
private:
  int numeroPuertas;
  int asientos;
  int cilindrada;
  int numeroEjes;

public:
//construtores
  Autobus();
 Autobus(std::string marca, std::string modelo,
        int anio, std::string placas,
        int cilindrada, int numeroEjes,
        int numeroPuertas, int asientos);
    //Métodos para actualizar
  void actualizarNumeroPuertas(int nuevoNumero);
  void actualizarCilindrada(int nuevaCilindrada);
  void actualizarNumeroEjes(int nuevoNumeroEjes);
  void actualizarAsientos(int nuevosAsientos);
    // Sobrescritura del método de la clase base
  void mostrarInformacion();
    // Getter
  int obtenerNumeroPuertas();
  int obtenerCilindrada();
  int obtenerNumeroEjes();
  int obtenerAsientos();
};
#endif // AUTOBUS_H 