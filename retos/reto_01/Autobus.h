#ifdef AUTOBUS_H
#define AUTOBUS_H

#include <string>
#include "veiculo.h"
class Autobus : public vehiculo {
    private:
    int numeropuertas;
    public:
    //constructores
    Autobus();
    Autobus(std::string marca, std::string modelo, int anio, int numeropuertas);
    //actualizar
    void actualizarNumeroPuertas(int nuevoNumero);
    //sobrescritura del metodo
    void mostrarInformacion();
    //getter 
    int obtenerNumeroPuertas();
};

#endif // AUTOBUS_H