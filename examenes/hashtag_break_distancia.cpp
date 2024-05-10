// Dado un hashtag como:
//
//    "byeexmnlgoritmos"
//
// Encontrar las palabras que lo forman entiendo en cuenta que se quiere minimizar la distancia de las abreviaturas con respecto a las palabras reales del diccionaio.
//
// Recurrencia:
//    
//    hashtag(i) = 0 si i == N
//    hashtag(i) = Entre j = i hasta N, devolver el mínimo de hashtag(j + 1) + distancia_palabra(i, j)
//
//
// Ejemplo de tabla:
//
//      b y e e x m n l g o r i t m o s 
//      3 ∞ ∞ 3 ∞ ∞ ∞ 1 ∞ ∞ 0 ∞ ∞ ∞ ∞ ∞ 0 
//
// Resultado obtenido:
//      Palabras: bye examen algo ritmos 
//      Distancia: 3
//
// Otra solución válida sería: bye examen algoritmos
//

#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <utility> 

#define INFINITO (9999)

using namespace std;

std::pair<int, string> palabra_mas_cercana(const string& s) {
    std::unordered_map<std::string, std::pair<int, std::string>> m;

    m["exmn"] = std::make_pair(2, "examen");
    m["bye"] = std::make_pair(0, "bye");
    m["ritmos"] = std::make_pair(0, "ritmos");
    m["algo"] = std::make_pair(0, "algo");
    m["lgo"] = std::make_pair(1, "algo");
    m["lgoritmos"] = std::make_pair(1, "algoritmos");
    m["algoritmos"] = std::make_pair(0, "algoritmos");

    if (m.count(s))
        return m[s];

    return std::make_pair(INFINITO, "");
}

void recuperar_resultado(const std::string& s, const int tabla[]) {
    int N = s.size();
    for(int i = 0; i < N; i++) {
        int j = i;

        int menor_distancia = INFINITO;
        string menor_palabra = "";

        for(int j = i; j < N; j++) {
            std::string subcadena = s.substr(i, j - i + 1);
            std::pair<int, string> par = palabra_mas_cercana(subcadena);
            int distancia = par.first;
            string palabra = par.second;

            int d = tabla[j + 1] + distancia;
            if (d < menor_distancia) {
                menor_distancia = d;
                menor_palabra = palabra;
        
                i = j;        
            }
            
        }

        std::cout << menor_palabra << " ";

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
            std::pair<int, string> par = palabra_mas_cercana(subcadena);
            int distancia = par.first;
            string palabra = par.second;

            int v = tabla[j + 1] + distancia;
            if (v < tabla[i]) {
                tabla[i] = v;
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

    if (tabla[0] != INFINITO)
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

