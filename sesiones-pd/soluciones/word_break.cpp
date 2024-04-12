
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

void recuperar_resultado_alternativo(const std::string& s, const bool tabla[]) {
    int N = s.size();
    int i = 0;
    while(i < N) {
        for(int j = i; j < N; j++) {
            std::string subcadena = s.substr(i, j - i + 1);
            if (tabla[j + 1] && es_palabra(subcadena)) {
                std::cout << subcadena << " ";
                i = j + 1;
                break;
            }
        }
    }
    std::cout << std::endl;
}

void recuperar_resultado(const std::string& s, const bool tabla[]) {
    int N = s.size();
    for(int i = 0; i < N; i++) {
        int j = i;

        std::string subcadena = s.substr(i, j - i + 1);
        while(!tabla[j + 1] || !es_palabra(subcadena)) {
            j++;
            subcadena = s.substr(i, j - i + 1);
        }

        std::cout << subcadena << " ";

        i = j;        
    }
    std::cout << std::endl;
}


// Dada una frase como:
//
//    "juntosdominaremoslagalaxia"
//
// Encontrar las palabras del diccionario que la componen.
//
// Recurrencia:
//    
//    word_break(i) = true si i == N
//    word_break(i) = true si en alguna subcadena entre i y N cumple que es_palabra(subcadena) y word_break(j) 
//                            donde j es el índice siguiente de la subcadena
//
//
// Diseño de la tabla:
//
//    - Solo hay n posibles resultados para el subproblema word_break(j), que son las posibles subcadenas (j hasta N)
//    - Cada subproblema work_break(i) depende de los subproblemas word_break(j) donde j > i
//      Por tanto, el orden de evaluación tiene que empezar por el final de la cadena
//
bool word_break(const std::string& s) {
    // Implementación basada en programación dinámica

    int N = s.size();

    bool tabla[N + 1];
    tabla[N] = true; 

    for(int i = N - 1; i >= 0; i--) {
        tabla[i] = false;
        for(int j = i; j < N; j++) {
            std::string subcadena = s.substr(i, j - i + 1);
            if (tabla[j + 1] && es_palabra(subcadena)) {
                tabla[i] = true;
            }
        }
    }


    // imprimir tabla
    cout << s << endl;
    for(int i = 0; i <= N; i++) {
        std::cout << (tabla[i] ? "T" : "F");
    }
    cout << endl;

    if (tabla[0])
        recuperar_resultado(s, tabla);

    return tabla[0];
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

