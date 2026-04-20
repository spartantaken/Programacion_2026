#include <curl/curl.h>

#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>
#include <stdexcept>
#include <string>

// 🔥 AGREGADO
#include "Conversacion.h"

#ifdef _WIN32
#include <windows.h>
#endif

namespace {

void set_env_value(const std::string& key, const std::string& value) {
#ifdef _WIN32
    _putenv_s(key.c_str(), value.c_str());
#else
    setenv(key.c_str(), value.c_str(), 1);
#endif
}

std::string trim(const std::string& value) {
    const std::string whitespace = " \t\r\n";
    const size_t start = value.find_first_not_of(whitespace);
    if (start == std::string::npos) {
        return "";
    }

    const size_t end = value.find_last_not_of(whitespace);
    return value.substr(start, end - start + 1);
}

void load_dotenv_file(const std::string& path) {
    std::ifstream dotenv_file(path);
    if (!dotenv_file.is_open()) {
        return;
    }

    std::string line;
    while (std::getline(dotenv_file, line)) {
        const std::string cleaned_line = trim(line);
        if (cleaned_line.empty() || cleaned_line[0] == '#') {
            continue;
        }

        const size_t separator = cleaned_line.find('=');
        if (separator == std::string::npos || separator == 0) {
            continue;
        }

        const std::string key = trim(cleaned_line.substr(0, separator));
        std::string value = trim(cleaned_line.substr(separator + 1));

        if (value.size() >= 2 &&
            ((value.front() == '"' && value.back() == '"') ||
             (value.front() == '\'' && value.back() == '\''))) {
            value = value.substr(1, value.size() - 2);
        }

        if (key.empty()) {
            continue;
        }

        const char* existing_value = std::getenv(key.c_str());
        const bool is_missing_or_empty = (existing_value == nullptr || std::string(existing_value).empty());
        if (is_missing_or_empty) {
            set_env_value(key, value);
        }
    }
}

size_t write_callback(void* contents, size_t size, size_t nmemb, void* userp) {
    const size_t total_size = size * nmemb;
    auto* output = static_cast<std::string*>(userp);
    output->append(static_cast<char*>(contents), total_size);
    return total_size;
}

std::string escape_json(const std::string& input) {
    std::string escaped;
    escaped.reserve(input.size() + 8);

    for (const char ch : input) {
        switch (ch) {
            case '"': escaped += "\\\""; break;
            case '\\': escaped += "\\\\"; break;
            case '\b': escaped += "\\b"; break;
            case '\f': escaped += "\\f"; break;
            case '\n': escaped += "\\n"; break;
            case '\r': escaped += "\\r"; break;
            case '\t': escaped += "\\t"; break;
            default: escaped += ch; break;
        }
    }

    return escaped;
}

std::string unescape_json_string(const std::string& input) {
    std::string output;
    output.reserve(input.size());

    for (size_t index = 0; index < input.size(); ++index) {
        if (input[index] != '\\') {
            output += input[index];
            continue;
        }

        if (index + 1 >= input.size()) {
            break;
        }

        const char next = input[++index];
        switch (next) {
            case '"': output += '"'; break;
            case '\\': output += '\\'; break;
            case '/': output += '/'; break;
            case 'b': output += '\b'; break;
            case 'f': output += '\f'; break;
            case 'n': output += '\n'; break;
            case 'r': output += '\r'; break;
            case 't': output += '\t'; break;
            default: output += next; break;
        }
    }

    return output;
}

std::string extract_content_field(const std::string& json_response) {
    const std::regex content_regex("\"content\"\\s*:\\s*\"((?:\\\\.|[^\\\"])*)\"");
    std::smatch match;

    if (std::regex_search(json_response, match, content_regex) && match.size() > 1) {
        return unescape_json_string(match[1].str());
    }

    return "";
}

enum class Provider {
    OpenAI,
    Gemini
};

struct CliOptions {
    std::string model = "gpt-4o-mini";
    std::string prompt;
    std::string provider = "auto";
};

std::string to_lower(std::string value) {
    std::transform(value.begin(), value.end(), value.begin(), [](unsigned char ch) {
        return static_cast<char>(std::tolower(ch));
    });
    return value;
}

bool starts_with(const std::string& value, const std::string& prefix) {
    return value.size() >= prefix.size() &&
           value.compare(0, prefix.size(), prefix) == 0;
}

Provider resolve_provider(const CliOptions& options) {
    const std::string provider = to_lower(options.provider);
    if (provider.empty() || provider == "auto") {
        const std::string model = to_lower(options.model);
        if (starts_with(model, "gemini")) {
            return Provider::Gemini;
        }
        return Provider::OpenAI;
    }

    if (provider == "openai") {
        return Provider::OpenAI;
    }

    if (provider == "gemini" || provider == "google" || provider == "google-gemini") {
        return Provider::Gemini;
    }

    throw std::runtime_error("Unknown provider: " + options.provider);
}

std::string resolve_api_key(Provider provider) {
    if (provider == Provider::OpenAI) {
        const char* value = std::getenv("OPENAI_API_KEY");
        if (value != nullptr && !std::string(value).empty()) {
            return value;
        }
        throw std::runtime_error("Missing OPENAI_API_KEY");
    }

    const char* value = std::getenv("GEMINI_API_KEY");
    if (value) return value;

    throw std::runtime_error("Missing GEMINI_API_KEY");
}

std::string resolve_base_url(Provider provider) {
    return (provider == Provider::OpenAI)
        ? "https://api.openai.com"
        : "https://generativelanguage.googleapis.com/v1beta/openai";
}

std::string resolve_chat_path(Provider provider) {
    return (provider == Provider::Gemini)
        ? "/chat/completions"
        : "/v1/chat/completions";
}

void configure_console_utf8() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif
}

std::string request_chat_completion(
    const std::string& api_key,
    const std::string& base_url,
    const std::string& chat_path,
    const std::string& model,
    const std::string& prompt
) {
    CURL* curl = curl_easy_init();
    if (!curl) throw std::runtime_error("CURL init failed");

    std::string response;

    std::string url = base_url + chat_path;

    std::string payload =
        "{\"model\":\"" + escape_json(model) +
        "\",\"messages\":[{\"role\":\"user\",\"content\":\"" +
        escape_json(prompt) + "\"}]}";

    struct curl_slist* headers = nullptr;
    headers = curl_slist_append(headers, "Content-Type: application/json");
    headers = curl_slist_append(headers, ("Authorization: Bearer " + api_key).c_str());

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, payload.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

    curl_easy_perform(curl);

    curl_slist_free_all(headers);
    curl_easy_cleanup(curl);

    return response;
}

} // namespace

// ================= MAIN =================
int main(int argc, char* argv[]) {
    try {
        configure_console_utf8();

        load_dotenv_file(".env");

        // 🔥 CAMBIO: usar GEMINI_API_KEY
        const char* key = std::getenv("GEMINI_API_KEY");
        if (!key) throw std::runtime_error("Falta GEMINI_API_KEY");

        std::string prompt;
        std::cout << "Enter prompt: ";
        std::getline(std::cin, prompt);

        if (prompt.empty()) {
            std::cerr << "Prompt vacío\n";
            return 1;
        }

        // 🔥 CREAR CONVERSACIÓN
        Conversacion chat("conversacion.json");

        curl_global_init(CURL_GLOBAL_DEFAULT);

        // 🔥 CAMBIOS: URL + endpoint + modelo Gemini
        const std::string response_json = request_chat_completion(
            key,
            "https://generativelanguage.googleapis.com/v1beta/openai",
            "/chat/completions",
            "gemini-2.5-flash",
            prompt
        );

        curl_global_cleanup();

        const std::string content = extract_content_field(response_json);

        if (!content.empty()) {
            std::cout << "\nModel response:\n" << content << "\n";

            // 🔥 GUARDAR EN JSON
            chat.agregarMensaje(prompt, content);

        } else {
            std::cout << "\nRaw JSON response:\n" << response_json << "\n";
        }

        return 0;

    } catch (const std::exception& error) {
        std::cerr << "Error: " << error.what() << "\n";
        return 1;
    }
}