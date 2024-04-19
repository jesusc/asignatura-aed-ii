
#include <iostream>
#include <vector>

using namespace std;

void recuperar_solucion(const std::vector<std::vector<bool>>& tabla, const std::vector<int>& numeros, int total) {
    int n = numeros.size();
    int i = n;
    int j = total;

    while (i > 0 && j > 0) {
        if (tabla[i][j] == tabla[i - 1][j]) {
            i--;
        } else {
            cout << numeros[i - 1] << " ";
            j = j - numeros[i - 1];
            i--;
        }
    }
    cout << endl;

}

int subset_sum(const std::vector<int>& numeros, int total) {
    int n = numeros.size();
    std::vector<std::vector<bool>> tabla(n + 1, std::vector<bool>(total + 1, false));

    for (int i = 0; i <= n; i++) {
        tabla[i][0] = true;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= total; j++) {
            if (j < numeros[i - 1]) {
                tabla[i][j] = tabla[i - 1][j];
            } else {
                tabla[i][j] = tabla[i - 1][j] || tabla[i - 1][j - numeros[i - 1]];
            }
        }
    }

    bool resultado = tabla[n][total];

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
