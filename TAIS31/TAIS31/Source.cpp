
/*@ <answer>
 *
 * Nombre y Apellidos: Jorge Medina Carrtero
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

bool resuelveCaso() {

    // leer los datos de la entrada
    int N;
    cin >> N;
    if (!std::cin)  // fin de la entrada
        return false;

    vector<int> at(N), def(N);
    // resolver el caso posiblemente llamando a otras funciones

    for (int i = 0; i < N; i++) {
        cin >> at[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> def[i];
    }

    sort(at.begin(), at.end());
    sort(def.begin(), def.end());

    int index = 0;
    int ciudades = 0;
    for (int i = 0; i < N; i++) {
        if (at[index] <= def[i]) {
            ciudades++;
            index++;
        }   
    }

    // escribir la solución
    cout << ciudades << '\n';

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
