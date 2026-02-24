#include "empleado_tiempo_completo.h"

EmpleadoTiempoCompleto::EmpleadoTiempoCompleto()
    : Empleado(), horasSemanales(0), bono(0.0f) {}

EmpleadoTiempoCompleto::EmpleadoTiempoCompleto(
    std::string n, std::string i,
    float s, int horas, float b)
    : Empleado(n, i, s),
      horasSemanales(horas),
      bono(b) {}

void EmpleadoTiempoCompleto::actualizarBono(float nuevoBono) {
    bono = nuevoBono;
}

void EmpleadoTiempoCompleto::mostrarInformacion() const {
    Empleado::mostrarInformacion();
    std::cout << "Horas Semanales: " << horasSemanales << std::endl;
    std::cout << "Bono: $"
              << std::fixed << std::setprecision(2)
              << bono << std::endl;
}

float EmpleadoTiempoCompleto::calcularSalarioTotal() const {
    return salarioBase + bono;
}