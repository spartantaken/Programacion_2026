#include <iostream>
#include "estudiante.h"

int main() {
    std::cout << "=== Sistema de Gestión de Estudiante ===\n\n";

    // Constructor por defecto
    Estudiante estudiante1;
    std::cout << "Estudiante 1 (constructor por defecto):\n";
    estudiante1.mostrarInformacionCompleta();
    std::cout << std::endl;

    // Actualizar datos
    estudiante1.actualizarNombre("María García López");
    estudiante1.actualizarCodigo("EST-2024-001");
    estudiante1.actualizarEdad(20);
    estudiante1.actualizarPromedio(9.2);
    estudiante1.actualizarActivo(true);

    std::cout << "Estudiante 1 después de actualizar:\n";
    estudiante1.mostrarInformacionCompleta();
    estudiante1.calcularEstadoAcademico();
    std::cout << std::endl;

    // Constructor con parámetros
    Estudiante estudiante2("Juan Pérez Martínez", "EST-2024-002", 22, 7.5, true);

    std::cout << "Estudiante 2 (constructor con parámetros):\n";
    estudiante2.mostrarInformacionCompleta();
    estudiante2.calcularEstadoAcademico();
    std::cout << std::endl;

    // Incrementar edad
    std::cout << "Incrementando edad del estudiante 2:\n";
    estudiante2.incrementarEdad();
    estudiante2.mostrarEdad();
    std::cout << std::endl;

    // Validación promedio
    std::cout << "Intentando actualizar promedio con valor inválido:\n";
    estudiante2.actualizarPromedio(15.0);
    estudiante2.mostrarPromedio();

    return 0;
}