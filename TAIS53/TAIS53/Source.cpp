
/*@ <answer>
 *
 * Nombre y Apellidos: Jorge Medina Carretero
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <climits>
using namespace std;

#include "Matriz.h"  // propios o los de las estructuras de datos de clase
#include <vector>

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

Matriz<int> multiplica_matrices(Matriz<int> const& alquiler) {
    int n = alquiler.numcols();
    Matriz<int> coste(n, n, 0);
    for (int d = 1; d <= n; ++d) { // recorre diagonales
        for (int i = 0; i <= n - d - 1; ++i) { // recorre elementos de diagonal
            int j = i + d;
            //cálculo del mínimo
            coste[i][j] = alquiler[i][i + 1] + coste[i + 1][j];
            for (int k = i + 2; k <= j; ++k) {
                coste[i][j] = min(coste[i][j], alquiler[i][k] + coste[k][j]);
            }
        }
    }
    return coste;
}

bool resuelveCaso() {

    // leer los datos de la entrada
    int N;
    cin >> N;

    if (!std::cin)  // fin de la entrada
        return false;

    Matriz<int> alquiler(N, N);

    for (int i = 0; i < N - 1; ++i) {
        for (int j = i + 1; j < N; ++j) {
            cin >> alquiler[i][j];
            cout << alquiler[i][j] << " ";
        }
        cout << "\n";
    }
    // resolver el caso posiblemente llamando a otras funciones
    auto sol = multiplica_matrices(alquiler);
    // escribir la solución
    for (int i = 0; i < sol.numfils(); i++) {
        for (int j = i + 1; j < sol.numcols(); j++) {
            cout << sol[i][j] << " ";
        }
        cout << "\n";
    }

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
