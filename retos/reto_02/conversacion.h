#ifndef CONVERSACION_H
#define CONVERSACION_H

#include "Mensaje.h"
#include <vector>
#include <string>

class Conversacion {
private:
    std::vector<Mensaje> mensajes;
    std::string archivo;

    std::string construirRutaArchivo(const std::string& nombreArchivoBase);
    void guardarJSON();

public:
    Conversacion(const std::string& nombreArchivo);

    void agregarMensaje(const std::string& prompt, const std::string& respuesta);
};

#endif