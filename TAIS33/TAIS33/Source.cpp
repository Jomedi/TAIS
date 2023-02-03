
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

bool resuelveCaso() {

    // leer los datos de la entrada
    int N;
    cin >> N;  

    if (N == 0)
        return false;

    int h, m, dur;
    char aux;
    vector<pair <int, int>> v(N);

    for (int i = 0; i < N; i++) {
        cin >> h >> aux >> m >> dur;
        int mins = h * 60 + m;
        v[i] = {mins, mins + dur};
    }

    // resolver el caso posiblemente llamando a otras funciones
    sort(v.begin(), v.end());
    int finUltima = v[0].second, peliculas = 1;
    for (int i = 1; i < v.size(); ++i) {
        if (v[i].first < finUltima && v[i].second < finUltima) {
                finUltima = v[i].second;
        }
        else if (finUltima <= v[i].first - 10) {
            peliculas++;
            finUltima = v[i].second;
        }
    }

    // escribir la solución
    cout << peliculas << '\n';

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
