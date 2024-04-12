//
// Problema de la mochila
// (Knapsack problem)
//
// Ecuación de recurrencia
//  
//   mochila(k, m) donde k es el objeto actual que se va tomar y m es la capacidad restante
//
// Hay dos decisiones que se pueden tomar, poner el objeto k en la mochila o no ponerlo
//
//   - Poner el objeto k en la mochila:    mochila(k, m) = beneficio[k] + mochila(k - 1, m - peso[k])
//   - No poner el objeto k en la mochila: mochila(k, m) = mochila(k - 1, m)
//
// Se escogerá el máximo de ambas opciones.
//
// Casos base:
//    - mochila(k, 0) = 0  porque eso significa que no hay capacidad en la mochila para el objeto k
//    - mochila(0, m) = 0  porque no hay objetos para poner en la mochila
//
// Diseño de la tabla:
// 
//    - Las filas representan los objetos que se pueden tomar
//    - Las columnas representan la capacidad restante de la mochila
//    - La celda (i, j) representa el beneficio máximo que se puede obtener tomando (o no) el objeto i y con una capacidad restante de j
// 

#include <iostream>

using namespace std;

void imprimir_tabla(int N, int M, int** tabla)
{
    for (int i = 0; i <= M; i++)
    {
        if (i > 0)
            cout << (i) << " ";
        else
            cout << "     ";
    }
    cout << endl;

    for (int i = 0; i <= N; i++)
    {
        if (i > 0)
            cout << "o" << (i) << " ";
        else
            cout << "   ";

        for (int j = 0; j <= M; j++)
        {
            cout << tabla[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void reconstruir_solucion(int N, int M, int pesos[], int** tabla)
{
    int i = N;
    int j = M;
    while (i > 0 && j > 0)
    {
        if (tabla[i][j] != tabla[i - 1][j])
        {
            j = j - pesos[i - 1];
            
            cout << "Tomar objeto " << i << ". Capacidad restante: " << j << endl;
        }
        i--;
    }
}

void mochila(int N, int pesos[], int beneficios[], int capacidad)
{
    int **tabla;
    tabla = new int*[N + 1];
    for(int i = 0; i < N + 1; i++) {
        tabla[i] = new int[capacidad + 1];
    }

    for(int i = 0; i < N + 1; i++) {
        tabla[i][0] = 0;
    }
    for(int j = 0; j < capacidad + 1; j++) {
        tabla[0][j] = 0;
    }

    // Ojo, mochila(k) se refiere aquí a k = i
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= capacidad; j++) {
            int peso_restante = j - pesos[i - 1];
            if(peso_restante >= 0) {
                int tomar_objeto = beneficios[i - 1] + tabla[i - 1][peso_restante];
                int no_tomar_objeto = tabla[i - 1][j];
                tabla[i][j] = max(tomar_objeto, no_tomar_objeto);
            } else {
                tabla[i][j] = tabla[i - 1][j];
            }
        }
    }

    imprimir_tabla(N, capacidad, tabla);

    int resultado = tabla[N][capacidad];

    cout << "Solución: " << resultado << endl;
    reconstruir_solucion(N, capacidad, pesos, tabla);

    for (int i = 0; i < N + 1; i++) {
        delete[] tabla[i];
    }
    delete[] tabla;

}

int main(int argc, char *argv[])
{
    //int N = 3;
    //int pesos[] = {2, 3, 4};
    //int beneficios[] = {1, 2, 5};
    //int capacidad = 6;

    int N = 3;
    int pesos[] = {2, 3, 6};
    int beneficios[] = {1, 2, 5};
    int capacidad = 8;

    mochila(N, pesos, beneficios, capacidad);

    return 0;
}
