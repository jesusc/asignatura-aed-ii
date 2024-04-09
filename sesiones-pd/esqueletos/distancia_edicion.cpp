// Distancia de edicion (edit distance)
//
// Las operaciones de edición son:
// 1. Insertar un caracter
// 2. Eliminar un caracter
// 3. Reemplazar un caracter
//
// Dada una cadena A y una cadena B, se desea minimizar el número de operaciones para que A sea igual a B.
//
// Por ejemplo, si A = "casa" y B = "cate", la distancia de edición es 2:
//
#include <iostream>
#include <string>

using namespace std;

#define MAX (9999)



int distancia_edicion(const string& str1, const string& str2) {
    int N = str1.length();
    int M = str2.length();

    // Construir tabla
    int **tabla = new int*[N + 1];
    for(int i = 0; i <= N; i++) {
        tabla[i] = new int[M + 1];
    }


    // TODO: Construir el algoritmo
    
    int resultado = -1;
    
    // Liberar tabla
    for (int i = 0; i < N + 1; i++) {
        delete[] tabla[i];
    }
    delete[] tabla;

    return resultado;
}

int main(int argc, char *argv[])
{
    if (argc < 3) {
        cout << "Son necesarios dos argumentos. ./distancia_edicion cadena1 cadena2" << endl;
        return 1;
    }

    string str1 = argv[1];
    string str2 = argv[2];

    cout << str1 << endl;
    cout << str2 << endl;
    cout << "N: " << str1.length() << ", M: " << str2.length() << endl;
    cout << endl << endl;

    int dist = distancia_edicion(str1, str2);

    cout << "Distancia: " << dist << endl;

    return 0;
}
