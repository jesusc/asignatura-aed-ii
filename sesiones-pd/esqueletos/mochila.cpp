//
// Problema de la mochila
// (Knapsack problem)
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

void reconstruir_solution(int N, int M, int pesos[], int** tabla)
{
  // Implementar despues del algoritmo de programación dinámica
}

void mochila(int N, int pesos[], int beneficios[], int capacidad)
{
    int **tabla;
    tabla = new int*[N + 1];
    for(int i = 0; i < N + 1; i++) {
        tabla[i] = new int[capacidad + 1];
    }

    // Implementar
    
    int resultado = -1;
      
    imprimir_tabla(N, capacidad, tabla);

    cout << "Solución: " << resultado << endl;
    reconstruir_solution(N, capacidad, pesos, tabla);

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
