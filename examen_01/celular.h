#ifndef CELULAR_H
#define CELULAR_H

#include <string>

class Celular {
private:
    std::string marca;
    std::string modelo;
    std::string color;
    int almacenamiento;
    float tamPantalla;
    int bateria;

public:
    Celular(std::string marca, std::string modelo, std::string color,
            int almacenamiento, float tamPantalla, int bateria);

    void mostrarInformacion();
    void llamar(std::string numero);
    void cargar(int porcentaje);
};

#endif
