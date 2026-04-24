//Para compilar: g++ *.cpp -o programa
//Para ejecutar: ./programa
#include "persona.h"
#include "Alumno.h"
#include "Profesor.h"
#include <iostream>
using namespace std;

int main() {
    persona* vector[3];

    vector[0] = new Alumno("Alejandro", 20, 18.9);
    vector[1] = new Alumno("Maria", 19, 15.5);
    vector[2] = new Profesor("Jose", 25, "Algoritmos");

    vector[0]->mostrar();
    cout<<"\n";
    vector[1]->mostrar();
    cout<<"\n";
    vector[2]->mostrar();

}