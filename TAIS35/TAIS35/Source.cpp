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

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
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

    // escribir la soluci�n
    cout << tuneles << '\n';

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
