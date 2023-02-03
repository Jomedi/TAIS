
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

void backTracking(const vector<vector<int>> &v, int m, int n, int k, int &mejorCoste, int costeActual, vector<int> &marcas) {
    for (int i = 0; i < m; i++){
        if (marcas[i] < 3) {
            costeActual += v[i][k];
            marcas[i]++;
            if (costeActual < mejorCoste) {
                if (k == n - 1) 
                    mejorCoste = costeActual;
                else
                    backTracking(v, m, n, k + 1, mejorCoste, costeActual, marcas);
            }
            marcas[i]--;
            costeActual -= v[i][k];
        }
    }
}

void resuelveCaso() {

    // leer los datos de la entrada
    int m, n;
    cin >> m >> n;
    vector<vector<int>> v(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }

    int mejorCoste = INT_MAX;
    int costeActual = 0;
    vector<int> marcas(m, 0);
    // resolver el caso posiblemente llamando a otras funciones
    backTracking(v, m, n, 0, mejorCoste, costeActual, marcas);
    // escribir la soluci�n
    cout << mejorCoste << "\n";
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}