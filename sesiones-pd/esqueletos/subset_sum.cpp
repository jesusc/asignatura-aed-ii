#include <iostream>
#include <vector>

using namespace std;

void recuperar_solucion(const std::vector<std::vector<bool>>& tabla, const std::vector<int>& numeros, int total) {
}

int subset_sum(const std::vector<int>& numeros, int total) {
    int n = numeros.size();
    // Tabla bidimensional con vectores de C++
    std::vector<std::vector<bool>> tabla(n + 1, std::vector<bool>(total + 1, false));


    bool resultado = 0;

    if (resultado) {
        cout << "Solución recuperada: " << endl;
        recuperar_solucion(tabla, numeros, total);
    }

    return resultado;
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cout << "Uso: " << argv[0] << " <total> <num3> <num2> ..." << std::endl;
        return 1;
    }

    std::vector<int> numeros;
    int total = std::stoi(argv[1]);

    for (int i = 2; i < argc; i++) {
        int num = std::stoi(argv[i]);
        numeros.push_back(num);
    }

    cout << "Total: " << total << endl;
    cout << "Numeros: ";
    for (int num : numeros) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    bool r = subset_sum(numeros, total);
    cout << "Resultado: " << (r ? "SI" : "NO") << endl;

    return 0;
}
