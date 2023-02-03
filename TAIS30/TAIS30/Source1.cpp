
/*@ <answer>
 *
 * Nombre y Apellidos: Jorge Medina Carretero
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <...>
using namespace std;

#include "..."  // propios o los de las estructuras de datos de clase
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

int parches_manguera(vector<int> const& agujeros, int L) {
    int ini = agujeros[0], fin, tiras = 1;
    for (int i = 1; i < agujeros.size(); i++) {
        fin = agujeros[i];
        if (fin - ini > L) {
            tiras++;
            ini = fin;
        }
    }
    return tiras;
}

bool resuelveCaso() {
    int N, L;
    // leer los datos de la entrada
    cin >> N >> L;
    if (!std::cin)  // fin de la entrada
        return false;

    vector<int> v(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    // resolver el caso posiblemente llamando a otras funciones
    int tiras = parches_manguera(v, L);
    // escribir la soluci�n
    cout << tiras;

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
