#include <iostream>

// Se define según la siguiente recursion:
// 
//   catalan(0) = 1
//   catalan(1) = 1
//   catalan(n + 1) = suma i = 0..n { catalan(i) * catalan(n - 1) }
//
// (ojo, en la recurrencia el límite n es inclusivo por eso necesitamos n + 1 en la tabla)
//
long catalan(int n) {
  // Implementar
  return -1; 
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
