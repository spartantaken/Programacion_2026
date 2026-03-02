#ifndef VEHICULO_H
#define VEHICULO_H

#include <string>

class Vehiculo {
protected:
    std::string marca;
    std::string modelo;
    int anio;
    std::string tipo_licencia; /// TIPOS A (AUTOMOVIL), B (MOTO), C (CAMION) D (AUTOBUS)
    std::string placas; /// PLACA DE VEHICULO

public:
    // Constructores
    Vehiculo();
    Vehiculo(std::string marca, std::string modelo, int anio, std::string tipo_licencia, std::string placas);

    // Métodos para actualizar
    void actualizarMarca(std::string nuevaMarca);
    void actualizarModelo(std::string nuevoModelo);
    void actualizarAnio(int nuevoAnio);
    void actualizarTipoLicencia(std::string nuevaTipoLicencia);
    void actualizarPlacas(std::string nuevasPlacas);

    // Métodos para mostrar
    void mostrarInformacion();

    // Getters
    std::string obtenerMarca();
    std::string obtenerModelo();
    int obtenerAnio();
    std::string obtenerTipoLicencia();
    std::string obtenerPlacas();
};

#endif // VEHICULO_H