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

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
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
    // escribir la soluci�n
    cout << tiempoMin << "\n";

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

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
