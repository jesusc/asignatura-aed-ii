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
// Hay que pensar en qué decisiones se pueden tomar en cada paso. 
//   - Dado un caracter de A y un caracter de B, se pueden tomar cuatro decisiones:
//     0. No hacer nada (cuando ambos caracteres sean iguales)
//     1. Insertar el caracter de B en A
//     2. Eliminar el caracter de A
//     3. Reemplazar el caracter de A por el de B
//
// Ecuación de recurrencia:
//    
//   distancia_edicion(i, j) donde i es el índice del caracter actual de A y j es el índice del caracter actual de B
//
//   - Si A[i] == B[j], entonces distancia_edicion(i, j) = distancia_edicion(i - 1, j - 1)
//
//   - d_insertar = 1 + distancia_edicion(i, j - 1)
//     * Ejemplo (i = 4):   C A S A|    C A S A| _     
//                          C A S O|      C A S| O
//       porque al insertar un caracter, se avanza en B pero no en A ya que seguimos comparando el mismo caracter de A
//
//   - d_eliminar = 1 + distancia_edicion(i - 1, j)
//     * Ejemplo (i = 4):   C A S A|      C A S| -     
//                          C A S O|    C A S O|
//       porque al eliminar un caracter, se avanza en A pero no en B
//
//   - d_reemplazar = 1 + distancia_edicion(i + 1, j + 1)
//     * Ejemplo (i = 4):   C A S A|    C A S| A     
//                          C A S O|    C A S| O
//       porque al reemplazar un caracter, se avanza en ambos
//
//   Casos base:
//      - distancia_edicion(N, M) = 0 porque ambas cadenas están vacías
//      - distancia_edicion(0, j) = j porque se tienen que insertar los caracteres restantes de B en A
//      - distancia_edicion(i, 0) = i porque se tienen que eliminar los caracteres restantes de A
//
//
// Diseño de las tablas:
//   La tabla tiene N + 1 filas y M + 1 columnas, donde N es la longitud de A y M es la longitud de B
//   La celda (i, j) representa la distancia de edición entre A[0..i] y B[0..j]
//   Las ultima fila y la última columna se rellenan con la distancia de edición entre la cadena vacía y la cadena no vacía
//
// 

#include <iostream>
#include <string>

using namespace std;

#define MAX (9999)

void imprimir_tabla(int N, int M, const std::string &str1, const std::string &str2, int** tabla)
{
    cout << "  ";
    for (int j = 0; j <= M; j++)
    {
        cout << str2[j] << " ";
    }
    cout << endl;
    for (int i = 0; i <= N; i++)
    {
        if (i == N)
        {
            cout << " "
                 << " ";
        }
        else
        {
            cout << str1[i] << " ";
        }
        for (int j = 0; j <= M; j++)
        {
            cout << tabla[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void recuperar_solucion(int N, int M, const std::string &str1, const std::string &str2, int** tabla) {
    // Recuperar la solución del problema de distancia de edición
    int i = N;
    int j = M;

    while (i > 0 && j > 0) {
        char c1 = str1[i - 1];
        char c2 = str2[j - 1];

        if (c1 == c2) {
            i--;
            j--;
            cout << "Mantener " << c1 << endl;
            continue;
        }

        int distancia = tabla[i][j];
        int distancia_insertar   = 1 + tabla[i][j - 1];
        int distancia_eliminar   = 1 + tabla[i - 1][j];
        int distancia_reemplazar = 1 + tabla[i - 1][j - 1];

        if (distancia == distancia_reemplazar) {
            cout << "Reemplazar " << c1 << " por " << c2 << endl;
            i--;
            j--;
        } else if (distancia == distancia_insertar) {
            cout << "Insertar " << c2 << endl;
            j--;
        } else if (distancia == distancia_eliminar) {
            cout << "Eliminar " << c1 << endl;
            i--;
        }
    }

    // Casos base:
    // Insertar los caracteres restantes de B
    while (j > 0) {
        cout << "Insertar " << str2[j - 1] << endl;
        j--;
    }

    // Eliminar los caracteres restantes de A
    while (i > 0) {
        cout << "Eliminar " << str1[i - 1] << endl;
        i--;
    }
    
}

int distancia_edicion(const string& str1, const string& str2) {
    int N = str1.length();
    int M = str2.length();

    //int tabla[N + 1][M + 1];
    int **tabla = new int*[N + 1];
    for(int i = 0; i <= N; i++) {
        tabla[i] = new int[M + 1];
    }

    // Rellenar la primera columna
    for(int i = 0; i <= N; i++) {
        // Esto es solo para depurar
        for(int j = 0; j <= M; j++) {
            tabla[i][j] = 0;
        }

        tabla[i][0] = i;
    }
    for(int j = 0; j <= M; j++) {
        tabla[0][j] = j;
    }

    cout << "Inicial:" << endl;
    imprimir_tabla(N, M, str1, str2, tabla);

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            char c1 = str1[i - 1];
            char c2 = str2[j - 1];

            int distancia;
            if (c1 == c2) {
                distancia = tabla[i - 1][j - 1];
            } else {
                // Reemplazar
                int distancia_insertar   = 1 + tabla[i][j - 1];
                int distancia_eliminar   = 1 + tabla[i - 1][j];
                int distancia_reemplazar = 1 + tabla[i - 1][j - 1];

                distancia = min(distancia_insertar, min(distancia_eliminar, distancia_reemplazar));

                // cout << "i: "  << i << " j: " << j << " distancia: " << distancia << " distancia_insertar: " << distancia_insertar << " distancia_eliminar: " << distancia_eliminar << endl;
            }

            tabla[i][j] = distancia;
        }
    }

    int resultado = tabla[N][M];
    cout << "Min. operaciones edición: " << resultado << endl;

    imprimir_tabla(N, M, str1, str2, tabla);
    recuperar_solucion(N, M, str1, str2, tabla);

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