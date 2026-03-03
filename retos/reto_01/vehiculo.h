#ifndef VEHICULO_H
#define VEHICULO_H

#include <string>

class Vehiculo {
protected:
    std::string marca;
    std::string modelo;
    int anio;
    std::string tipolicencia; 
    std::string placas;         

public:
    Vehiculo();
    Vehiculo(std::string marca, std::string modelo, int anio, 
             std::string tipolicencia, std::string placas);

    void actualizarMarca(std::string nuevaMarca);
    void actualizarModelo(std::string nuevoModelo);
    void actualizarAnio(int nuevoAnio);
    void actualizarTipoLicencia(std::string nuevaTipo);
    void actualizarPlacas(std::string nuevasPlacas);

    virtual void mostrarInformacion(); 

    std::string obtenerMarca();
    std::string obtenerModelo();
    int obtenerAnio();
    std::string obtenerTipoLicencia();
    std::string obtenerPlacas();
};

#endif
