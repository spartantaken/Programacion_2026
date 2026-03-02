#ifndef CAMION_H
#define CAMION_H

#include <string>
#include "vehiculo.h"

class camion : public Vehiculo {
    private:
    int numeroPuertas;
    public:
    //constructores
    camion();
    camion(std::string marca, std::string modelo, int anio, int numeroPuertas);

    //metodos para actualizar
    void actualizarNumeroPuertas(int nuevoNumero);
      // Sobrescritura del método de la clase base
    void mostrarInformacion();

    // Getter
    int obtenerNumeroPuertas();
};

#endif // CAMION_H