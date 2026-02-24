#ifndef EMPLEADO_TIEMPO_COMPLETO_H
#define EMPLEADO_TIEMPO_COMPLETO_H

#include "empleado.h"

class EmpleadoTiempoCompleto : public Empleado {
private:
    int horasSemanales;
    float bono;

public:
    // Constructor por defecto
    EmpleadoTiempoCompleto();

    // Constructor con parámetros
    EmpleadoTiempoCompleto(std::string n, std::string i,
                           float s, int horas, float b);

    void actualizarBono(float nuevoBono);

    void mostrarInformacion() const override;
    float calcularSalarioTotal() const override;
};

#endif