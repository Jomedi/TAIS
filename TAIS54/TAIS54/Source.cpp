/*@ <answer>
 *
 * Nombre y Apellidos: Jorge Medina Carretero
 *
 *@ </answer> */

#include <iostream>
#include <fstream>

using namespace std;

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

void backtracking(const vector<vector<int>> &v, int n, int k, int tiempoTot, int &tiempoMin, vector<bool> &marcas) {
    for (int i = 0; i < n; i++) {
        if (!marcas[i]) {
            int t = v[i][k];
            tiempoTot += t;
            marcas[i] = true;

            if (k == n - 1) {
                if (tiempoTot < tiempoMin)
                    tiempoMin = tiempoTot;
            }
            else 
                backtracking(v, n, k + 1, tiempoTot, tiempoMin, marcas);
            
            tiempoTot -= t;
            marcas[i] = false;
        }

    }
}

bool resuelveCaso() {

    // leer los datos de la entrada
    int n;
    cin >> n;

    if (n == 0)
        return false;
    
    vector<vector<int>> v(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) 
            cin >> v[i][j];
    }

    int tiempoMin = 10000;
    int tiempoTot = 0;
    vector<bool> marcas(n, false);

    // resolver el caso posiblemente llamando a otras funciones
    backtracking(v, n, 0, tiempoTot, tiempoMin, marcas);
    // escribir la solución
    cout << tiempoMin << "\n";

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
