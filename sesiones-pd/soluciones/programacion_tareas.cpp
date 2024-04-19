// Programación de tareas
// (Weighted Interval Scheduling)
//
// Problema:
//      Dadas n tareas, cada una con un tiempo de inicio, tiempo de finalización y un beneficio asociado,
//      se desea determinar el beneficio máximo que se puede obtener al realizar un subconjunto de estas tareas
//      en un tiempo máximo de tal forma que no se superpongan en el tiempo.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Intervalo {
    int comienzo;
    int fin;
    int beneficio;
};

bool compararIntervalos(const Intervalo& a, const Intervalo& b) {
    return a.fin < b.fin;
}

int ultimaTareaCompatible(const vector<Intervalo>& intervalos, int actual) {
    for (int i = actual - 1; i >= 0; i--) {
        if (intervalos[i].fin <= intervalos[actual].comienzo) {
            return i;
        }
    }
    return -1;
}

void imprimirSolucion(const vector<Intervalo>& intervalos, const vector<int>& tabla) {
    // Dada la tabla de programación dinámica, imprimir la solución óptima
    int n = tabla.size();
    int i = n - 1;
    while (i >= 0) {
        if (i == 0) {
            cout << "Tarea " << i + 1 << endl;
            break;
        }
        if (tabla[i] != tabla[i - 1]) {
            cout << "Tarea " << i + 1 << endl;
            i = ultimaTareaCompatible(intervalos, i);
        } else {
            i--;
        }
    }
}


int programacionTareasOptima(const vector<Intervalo>& intervalos) {
    int n = intervalos.size();
    vector<int> tabla(n);

    tabla[0] = intervalos[0].beneficio;

    for (int i = 1; i < n; i++) {
        int beneficioTarea = intervalos[i].beneficio;
        int ultimaCompatible = ultimaTareaCompatible(intervalos, i);
        tabla[i] = max(beneficioTarea + tabla[ultimaCompatible], tabla[i - 1]);
    }

    imprimirSolucion(intervalos, tabla);

    return tabla[n - 1];
}

int main() {
    vector<Intervalo> intervalos = {
        {1, 4, 13},
        {3, 5, 5},
        {0, 6, 7},
        {5, 8, 1}
    };

    sort(intervalos.begin(), intervalos.end(), compararIntervalos);

    int beneficio = programacionTareasOptima(intervalos);
    cout << "Beneficio máximo: " << beneficio << endl;

    return 0;
}
