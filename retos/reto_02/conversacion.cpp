#include "Conversacion.h"
#include <fstream>
#include <filesystem>
#include <ctime>
#include <sstream>
#include <iomanip>

Conversacion::Conversacion(const std::string& nombreArchivo)
    : archivo(construirRutaArchivo(nombreArchivo)) {}

std::string Conversacion::construirRutaArchivo(const std::string& nombreArchivoBase) {
    std::time_t ahora = std::time(nullptr);
    std::tm* tiempo = std::localtime(&ahora);

    std::ostringstream fechaDir;
    fechaDir << std::put_time(tiempo, "%Y-%m-%d");

    std::ostringstream horaDir;
    horaDir << std::put_time(tiempo, "%H");

    std::filesystem::path rutaBase = std::filesystem::path("conversaciones") / fechaDir.str() / horaDir.str();
    std::filesystem::create_directories(rutaBase);

    std::filesystem::path nombreArchivo(nombreArchivoBase);
    std::filesystem::path rutaCompleta = rutaBase / nombreArchivo.filename();

    return rutaCompleta.string();
}

void Conversacion::agregarMensaje(const std::string& prompt, const std::string& respuesta) {
    Mensaje mensaje(prompt);
    mensaje.setRespuesta(respuesta);

    mensajes.push_back(mensaje);
    guardarJSON();
}

void Conversacion::guardarJSON() {
    std::ofstream file(archivo);

    if (!file.is_open()) return;

    file << "[\n";

    for (size_t i = 0; i < mensajes.size(); ++i) {
        file << mensajes[i].toJSON();
        if (i != mensajes.size() - 1) {
            file << ",";
        }
        file << "\n";
    }

    file << "]";
    file.close();
}