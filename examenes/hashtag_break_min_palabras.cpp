// Dada un hashtag como:
//
//    "byeexamenalgoritmos"
//
// Encontrar las palabras que forman el hashtag utilizando como ayuda un diccionario.
//
// Recurrencia:
//    
//    word_break(i) = 0 si i == N
//    word_break(i) = min(word_break(j + 1) + 1) para todo j > i hasta N que cumpla que diccionario(i, j) = true
//
// Ejemplo de tabla:
//
//  b y e e x a m e n a l g o r i t m o s 
//  3 ∞ ∞ 2 ∞ ∞ ∞ ∞ ∞ 1 ∞ ∞ ∞ 1 ∞ ∞ ∞ ∞ ∞ 0 
//
// Resultado:  
//      bye examen algoritmos 
//      Num palabras: 3
//
#include <iostream>
#include <string>
#include <algorithm>
#include <utility> 

#define INFINITO (9999)

using namespace std;

bool diccionario(const string& s) {
    int N = 5;
    string dicc[] = {"bye", "examen", "algo", "ritmos", "algoritmos"};
    for(int i = 0; i < N; i++) {
        if (s == dicc[i]) 
            return true;
    }
    return false;
}

void recuperar_resultado(const std::string& s, const int tabla[]) {
    int N = s.size();
    for(int i = 0; i < N; i++) {
        int ultimo_min = tabla[i];
        int j = i;

        std::string subcadena = s.substr(i, j - i + 1);
        while(tabla[j + 1] != ultimo_min - 1 || !diccionario(subcadena)) {
            j++;
            subcadena = s.substr(i, j - i + 1);
        }

        std::cout << subcadena << " ";

        i = j;        
    }
    std::cout << std::endl;
}

int word_break(const std::string& s) {
    int N = s.size();

    int tabla[N + 1];
    tabla[N] = 0; 

    for(int i = N - 1; i >= 0; i--) {
        tabla[i] = INFINITO;
        // Me quedo con el que da el mínimo
        for(int j = i; j < N; j++) {
            std::string subcadena = s.substr(i, j - i + 1);
            if (diccionario(subcadena)) {
                int num_palabras = tabla[j + 1] + 1;
                if (num_palabras < tabla[i]) {
                    tabla[i] = num_palabras;
                }
            }
        }
    }

    for(int i = 0; i < N; i++) {
        cout << s[i] << " ";
    }
    cout << endl;

    for(int i = 0; i <= N; i++) {
        if (tabla[i] == INFINITO) cout << "\xE2\x88\x9E";
        else  cout << tabla[i];
        cout << " ";
    }
    cout << endl;

    if (tabla[0] != 0)
        recuperar_resultado(s, tabla);

    return tabla[0];
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "./" << argv[0] << " cadena" << std::endl;
        return 1;
    }

    std::string entrada = argv[1];

    int r = word_break(entrada);

    std::cout << "Cadena: " << entrada << std::endl;
    std::cout << "Resultado: " << r << std::endl;

    return 0;
}

