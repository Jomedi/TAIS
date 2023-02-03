
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

    // escribir la soluci�n
    cout << peliculas << '\n';

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
