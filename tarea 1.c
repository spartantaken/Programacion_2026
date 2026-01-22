#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_EST 50
#define MAX_NOM 50
#define MAX_COD 15

typedef struct {
    char nombre[MAX_NOM];
    char codigo[MAX_COD];
    int edad;
    float promedio;
    bool activo;
} Estudiante;

// Funciones básicas
void agregarEstudiante(Estudiante estudiantes[], int *contador) {
    if(*contador >= MAX_EST) {
        printf("No hay espacio para mas estudiantes.\n");
        return;
    }
    
    printf("\n--- Agregar Estudiante ---\n");
    
    printf("Nombre: ");
    scanf(" %[^\n]", estudiantes[*contador].nombre);
    
    printf("Codigo: ");
    scanf(" %[^\n]", estudiantes[*contador].codigo);
    
    printf("Edad: ");
    scanf("%d", &estudiantes[*contador].edad);
    
    printf("Promedio (0.0-10.0): ");
    scanf("%f", &estudiantes[*contador].promedio);
    
    char estado;
    printf("Activo? (s/n): ");
    scanf(" %c", &estado);
    estudiantes[*contador].activo = (estado == 's' || estado == 'S');
    
    (*contador)++;
    printf("Estudiante agregado.\n");
}

void mostrarEstudianteSimple(Estudiante est) {
    printf("Nombre: %s\n", est.nombre);
    printf("Codigo: %s\n", est.codigo);
    printf("Edad: %d años\n", est.edad);
    printf("Promedio: %.2f\n", est.promedio);
    printf("Estado: %s\n", est.activo ? "Activo" : "Inactivo");
}

void buscarEstudiante(Estudiante estudiantes[], int contador) {
    if(contador == 0) {
        printf("No hay estudiantes.\n");
        return;
    }
    
    char codigo[MAX_COD];
    printf("\nCodigo a buscar: ");
    scanf(" %[^\n]", codigo);
    
    for(int i = 0; i < contador; i++) {
        if(strcmp(estudiantes[i].codigo, codigo) == 0) {
            printf("\n--- Estudiante Encontrado ---\n");
            mostrarEstudianteSimple(estudiantes[i]);
            return;
        }
    }
    
    printf("Estudiante no encontrado.\n");
}

void mostrarTodos(Estudiante estudiantes[], int contador) {
    if(contador == 0) {
        printf("No hay estudiantes.\n");
        return;
    }
    
    printf("\n=== LISTA DE ESTUDIANTES (%d) ===\n", contador);
    for(int i = 0; i < contador; i++) {
        printf("\nEstudiante %d:\n", i+1);
        mostrarEstudianteSimple(estudiantes[i]);
    }
}

int main() {
    Estudiante estudiantes[MAX_EST];
    int cantidad = 0;
    int opcion;
    
    do {
        printf("\n===== MENU =====\n");
        printf("1. Agregar estudiante\n");
        printf("2. Buscar estudiante\n");
        printf("3. Mostrar todos\n");
        printf("4. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);
        
        switch(opcion) {
            case 1:
                agregarEstudiante(estudiantes, &cantidad);
                break;
            case 2:
                buscarEstudiante(estudiantes, cantidad);
                break;
            case 3:
                mostrarTodos(estudiantes, cantidad);
                break;
            case 4:
                printf("Saliendo\n");
                break;
            default:
                printf("Opcion invalida.\n");
        }
        
    } while(opcion != 4);
    
    return 0;
}