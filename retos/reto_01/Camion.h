#ifndef CAMION_H
#define CAMION_H

#include <string>
#include "vehiculo.h"

class Camion : public Vehiculo {
private:
  int numeroPuertas;
  int cilindrada;
  int numeroEjes;

public:
  // Constructores
  Camion();
  Camion(std::string marca, std::string modelo, std::string placa,
         int anio, int cilindrada, int numeroEjes, int numeroPuertas);
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

#endif // CAMION_H