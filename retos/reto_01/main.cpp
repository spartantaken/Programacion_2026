/*
 * Instrucciones de Compilación:
 *
 * Para compilar este programa, utiliza el siguiente comando:
 *
 *     g++ vehiculo.cpp coche.cpp Camion.cpp Autobus.cpp moto.cpp main.cpp -o vehiculos
 *
 * O si prefieres usar el estándar C++17:
 *
 *     g++ -std=c++17 vehiculo.cpp coche.cpp Camion.cpp Autobus.cpp moto.cpp main.cpp -o vehiculos
 * 
 * Para ejecutar el programa:
 *
 *     ./vehiculos
 *
 */
#include <iostream>
#include "vehiculo.h"
#include "coche.h"
#include "Camion.h"
#include "Autobus.h"
#include "moto.h"

int main() {

    std::cout << "=== Sistema de Vehiculos ===" << std::endl;
    std::cout << std::endl;

    // Vehículo base 
    Vehiculo vehiculo1("Ford", "F-150", 2019, "C", "AAA111");

    std::cout << "Vehiculo base:" << std::endl;
    vehiculo1.mostrarInformacion();
    std::cout << std::endl;

    // =========================
    // COCHES
    // =========================

    Coche coche1;
    coche1.actualizarMarca("Toyota");
    coche1.actualizarModelo("Corolla");
    coche1.actualizarAnio(2022);
    coche1.actualizarTipoLicencia("A");
    coche1.actualizarPlacas("BBB222");
    coche1.actualizarNumeroPuertas(4);

    Coche coche2("Honda", "Civic", 2020, "A", "CCC333", 4);

    // =========================
    // CAMION
    // =========================

    Camion camion1;
    camion1.actualizarMarca("Volvo");
    camion1.actualizarModelo("FH");
    camion1.actualizarAnio(2018);
    camion1.actualizarTipoLicencia("B");
    camion1.actualizarPlacas("DDD444");
    camion1.actualizarCapacidadCarga(12000);

    Camion camion2("Kenworth", "T680", 2019, "B", "EEE555", 15000);

    // =========================
    // AUTOBUS
    // =========================

    Autobus autobus1;
    autobus1.actualizarMarca("Mercedes");
    autobus1.actualizarModelo("Sprinter");
    autobus1.actualizarAnio(2020);
    autobus1.actualizarTipoLicencia("P");
    autobus1.actualizarPlacas("EEE555");
    autobus1.actualizarNumeroPasajeros(30);

    Autobus autobus2("Scania", "K410", 2021, "P", "FFF666", 50);

    // =========================
    // MOTO
    // =========================

    Moto moto1;
    moto1.actualizarMarca("Yamaha");
    moto1.actualizarModelo("R6");
    moto1.actualizarAnio(2021);
    moto1.actualizarTipoLicencia("D");
    moto1.actualizarPlacas("FFF666");
    moto1.actualizarCilindrada(600);

    Moto moto2("Kawasaki", "Ninja650", 2020, "D", "GGG777", 650);

    // =========================
    // MENU PARA CAMBIAR PLACA
    // =========================

    int opcion;
    std::string nuevaPlaca;

    std::cout << "Seleccione el vehiculo al que desea cambiar la placa:" << std::endl;
    std::cout << "1. Coche" << std::endl;
    std::cout << "2. Camion" << std::endl;
    std::cout << "3. Autobus" << std::endl;
    std::cout << "4. Moto" << std::endl;

    std::cout << "Opcion: ";
    std::cin >> opcion;

    std::cout << "Ingrese la nueva placa: ";
    std::cin >> nuevaPlaca;

    std::cout << "\n=== Vehiculo actualizado ===\n" << std::endl;

    if(opcion == 1){
        coche1.actualizarPlacas(nuevaPlaca);
        coche1.mostrarInformacion();
    }


    else if(opcion == 2){
        camion1.actualizarPlacas(nuevaPlaca);
        camion1.mostrarInformacion();
    }

    else if(opcion == 3){
        autobus1.actualizarPlacas(nuevaPlaca);
        autobus1.mostrarInformacion();
    }

    else if(opcion == 4){
        moto1.actualizarPlacas(nuevaPlaca);
        moto1.mostrarInformacion();
    }

    else{
        std::cout << "Opcion no valida" << std::endl;
    }

    return 0;
}