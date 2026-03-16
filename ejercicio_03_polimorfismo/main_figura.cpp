/*
 * Instrucciones de Compilación:
 *
 * Para compilar este programa, utiliza el siguiente comando:
 *
 *     g++ Figura.cpp Rectangulo.cpp Cuadrado.cpp Triangulo.cpp main_figura.cpp -o figuras
 *
 * O si prefieres usar el estándar C++17:
 *
 *     g++ -std=c++17 Figura.cpp Circulo.cpp Rectangulo.cpp Cuadrado.cpp Triangulo.cpp main_figura.cpp -o figuras
 *
 * Para ejecutar el programa:
 *
 *     ./figuras
 *
 */
#include <iostream>
#include "Rectangulo.h"
#include "Cuadrado.h"
#include "Triangulo.h"
#include "Circulo.h"
#include "Figura.h"

using namespace std;

int main() {

    double baseR, alturaR;
    double lado;
    double baseT, alturaT;
    double radio;

    cout << "Base del rectangulo: ";
    cin >> baseR;

    cout << "Altura del rectangulo: ";
    cin >> alturaR;

    cout << "Lado del cuadrado: ";
    cin >> lado;

    cout << "Base del triangulo: ";
    cin >> baseT;

    cout << "Altura del triangulo: ";
    cin >> alturaT;

    cout << "Radio del circulo: ";
    cin >> radio;

    Figura* r = new Rectangulo("Rectangulo", baseR, alturaR);
    Figura* c = new Cuadrado("Cuadrado", lado);
    Figura* t = new Triangulo("Triangulo", baseT, alturaT);
    Figura* ci = new Circulo("Circulo", radio);

    cout << "\n--- Rectangulo ---\n";
    r->describir();
    cout << "Area: " << r->calcularArea() << endl;

    cout << "\n--- Cuadrado ---\n";
    c->describir();
    cout << "Area: " << c->calcularArea() << endl;

    cout << "\n--- Triangulo ---\n";
    t->describir();
    cout << "Area: " << t->calcularArea() << endl;

    cout << "\n--- Circulo ---\n";
    ci->describir();
    cout << "Area: " << ci->calcularArea() << endl;

    delete r;
    delete c;
    delete t;
    delete ci;

    return 0;
}
