
/*@ <answer>
 *
 * Nombre y Apellidos: Jorge Medina Carretero
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
using namespace std;

#include "EnterosInf.h"  // propios o los de las estructuras de datos de clase
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

vector<int> devolver_cambio(vector<int> const& M, int C) {
    int n = M.size();
    vector<EntInf> monedas(C + 1, Infinito);
    monedas[0] = 0;
    // calcular la matriz sobre el propio vector
    for (int i = 1; i <= n; ++i) {
        for (int j = M[i - 1]; j <= C; ++j) {
            monedas[j] = min(monedas[j], monedas[j - M[i - 1]] + 1);
        }
    }
    vector<int> sol;
    if (monedas[C] != Infinito) {
        int i = n, j = C;
        while (j > 0) { // no se ha pagado todo
            if (M[i - 1] <= j && monedas[j] == monedas[j - M[i - 1]] + 1) {
                // tomamos una moneda de tipo i
                sol.push_back(M[i - 1]);
                j = j - M[i - 1];
            }
            else // no tomamos más monedas de tipo i
                --i;
        }
    }
    return sol;
}

bool resuelveCaso() {

    // leer los datos de la entrada
    int valor, S;
    cin >> valor >> S;

    if (!std::cin)  // fin de la entrada
        return false;

    vector<int> puntuaciones(S);
    for (int i = 0; i < S; i++) {
        cin >> puntuaciones[i];
    }
    // resolver el caso posiblemente llamando a otras funciones
    auto sol = devolver_cambio(puntuaciones, valor);
    // escribir la solución
    if (sol.size() == 0)
        cout << "Imposible";
    else {
        cout << sol.size() << ": ";
        for (int val : sol)
            cout << val << " ";
    }
    cout << "\n";
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
