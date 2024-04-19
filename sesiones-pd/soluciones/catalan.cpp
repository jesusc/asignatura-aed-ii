#include <iostream>

// Se define según la siguiente recursion:
// 
//   catalan(0) = 1
//   catalan(1) = 1
//   catalan(n + 1) = suma i = 0..n { catalan(i) * catalan(n - 1) }
//
// (ojo, en la recurrencia el límite n es inclusivo por eso necesitamos n + 1 en la tabla)
//
// Estrategia para rellenar la tabla:
// - El bucle externo se encarga de "invocar" a catalan(i) hasta n
// - El bucle interno se encarga de generar catalan(i) sabiendo que todos los catalan(0.. i - 1) 
//   están disponibles porque han sido calculados en las iteraciones previas
//
long catalan(int n) {
    long c0 = 1;
    long c1 = 1;

    long tabla[n + 1];
    tabla[0] = c0;
    tabla[1] = c1;
 
    for (int i = 2; i <= n; i++) {
        tabla[i] = 0;
        for (int j = 0; j < i; j++)
            tabla[i] += tabla[j] * tabla[i - j - 1];
            // Es i - j - 1 porque tenemos que hacer "el anterior" porque se define como catalan(n + 1)
    }
 
    return tabla[n];
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Uso: ./catalan <entero>" << std::endl;
        return 1;
    }

    int n = std::stoi(argv[1]);

    long resultado = catalan(n);

    std::cout << "Catalan(" << n << ") = " << resultado << std::endl;  

    return 0;
}