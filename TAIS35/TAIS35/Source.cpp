/*@ <answer>
 *
 * Nombre y Apellidos: Jorge Medina Carretero
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <algorithm>
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
struct edificio {
    int W;
    int E;
};

bool operator<(edificio a, edificio b) {
    return a.W < b.W;
}

bool resuelveCaso() {

    // leer los datos de la entrada
    int N;
    cin >> N;

    if (N == 0)
        return false;

    vector<edificio> v(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i].W;
        cin >> v[i].E;
    }

    // resolver el caso posiblemente llamando a otras funciones
    sort(v.begin(), v.end());
    int tuneles = 1, maxW = -1, minE = 100000000;

    for (int i = 0; i < N; i++) {
        if (minE > v[i].W) {
            maxW = v[i].W;
            if (minE > v[i].E)
                minE = v[i].E;
        }
        else {
            tuneles++;
            maxW = v[i].W;
            minE = v[i].E;
        }
    }

    // escribir la solución
    cout << tuneles << '\n';

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
