#include "Mensaje.h"
#include <ctime>
#include <sstream>
#include <iomanip>

Mensaje::Mensaje(const std::string& p) : prompt(p) {
    fechaPrompt = obtenerFechaHoraActual();
}

void Mensaje::setRespuesta(const std::string& r) {
    respuesta = r;
    fechaRespuesta = obtenerFechaHoraActual();
}

std::string Mensaje::obtenerFechaHoraActual() {
    std::time_t ahora = std::time(nullptr);
    std::tm* tiempo = std::localtime(&ahora);

    std::ostringstream oss;
    oss << std::put_time(tiempo, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}

std::string Mensaje::escapeJSON(const std::string& str) const {
    std::string result;
    for (char c : str) {
        switch (c) {
            case '\"': result += "\\\""; break;
            case '\\': result += "\\\\"; break;
            case '\n': result += "\\n"; break;
            default: result += c;
        }
    }
    return result;
}

std::string Mensaje::toJSON() const {
    std::ostringstream oss;
    oss << "{\n";
    oss << "  \"prompt\": \"" << escapeJSON(prompt) << "\",\n";
    oss << "  \"fecha_prompt\": \"" << fechaPrompt << "\",\n";
    oss << "  \"respuesta\": \"" << escapeJSON(respuesta) << "\",\n";
    oss << "  \"fecha_respuesta\": \"" << fechaRespuesta << "\"\n";
    oss << "}";
    return oss.str();
}