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
  // Constructores
  Autobus();
  Autobus(std::string marca, std::string modelo, std::string placa,
          int anio, int cilindrada, int numeroEjes, int numeroPuertas);

  // Métodos para actualizar
  void actualizarNumeroPuertas(int nuevoNúmero);
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