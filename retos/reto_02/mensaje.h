#ifndef MENSAJE_H
#define MENSAJE_H

#include <string>

class Mensaje {
private:
    std::string prompt;
    std::string respuesta;
    std::string fechaPrompt;
    std::string fechaRespuesta;

    std::string obtenerFechaHoraActual();
    std::string escapeJSON(const std::string& str) const;

public:
    Mensaje(const std::string& prompt);

    void setRespuesta(const std::string& respuesta);

    std::string toJSON() const;
};

#endif