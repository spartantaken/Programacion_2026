#include <iostream>
#include "celular.h"

int main() {
    Celular miCel(
        "Samsung",
        "Galaxy S23",
        "Negro",
        256,
        6.1,
        80
    );

    miCel.mostrarInformacion();
    miCel.llamar("9991234567");
    miCel.cargar(15);

    return 0;
}
