
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

std::string dictionary[] = {"yo", "soy", "tu", "padre", 
    "juntos", "dominaremos", "la", "galaxia",
    "junto", "dominar", "gala",
    "te", "quiero", "lo", "se", ",",
    "dejalo", "ganar", "no", "conviene", "soliviantar", "a", "un", "wookiee"};

int DIC_SIZE = sizeof(dictionary) / sizeof(dictionary[0]);

bool es_palabra(const std::string& s) {
    return std::find(std::begin(dictionary), std::end(dictionary), s) != std::end(dictionary);
}


void recuperar_resultado(const std::string& s, const bool tabla[]) {
    int N = s.size();

    // Implementar
}

bool word_break(const std::string& s) {
  // Implementar
  
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "./work_break cadena" << std::endl;
        return 1;
    }

    std::string entrada = argv[1];

    bool r = word_break(entrada);

    std::cout << "Cadena: " << entrada << std::endl;
    std::cout << "Resultado: " << (r ? "SI" : "NO") << std::endl;

    return 0;
}

