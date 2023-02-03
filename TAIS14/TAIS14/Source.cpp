
/*@ <answer>
 *
 * Nombre y Apellidos:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>

using namespace std;

#include "Grafo.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

class ConjuntosDisjuntos {
protected:
    int ncjtos; // número de conjuntos disjuntos
    mutable std::vector<int> p; // enlace al padre
    std::vector<int> tam; // tamaño de los árboles
public:
    // partición unitaria de N elementos
    ConjuntosDisjuntos(int N) : ncjtos(N), p(N), tam(N, 1) {
        for (int i = 0; i < N; ++i)
            p[i] = i;
    }
    void unir(int a, int b) {
        int i = buscar(a);
        int j = buscar(b);
        if (i == j) return;
        if (tam[i] >= tam[j]) { // i es la raíz del árbol más grande
            tam[i] += tam[j]; p[j] = i;
        }
        else {
            tam[j] += tam[i]; p[i] = j;
        }
        --ncjtos;
    }
    int buscar(int a) const {
        if (p.at(a) == a) // es una raíz
            return a;
        else
            return p[a] = buscar(p[a]);
    }
    bool unidos(int a, int b) const {
        return buscar(a) == buscar(b);
    }
    int cardinal(int a) const {
        return tam[buscar(a)];
    }
    int num_cjtos() const {
        return ncjtos;
    }
};

bool resuelveCaso() {

    // leer los datos de la entrada
    int N, M;
    cin >> N;

    if (!std::cin)  // fin de la entrada
        return false;

    ConjuntosDisjuntos a = ConjuntosDisjuntos(N);

    cin >> M;
    int usuarios;
    for (int i = 0; i < M; i++) {
        cin >> usuarios;
        int id1, id2;
        if (usuarios > 0)
            cin >> id1;
        for (int j = 0; j < usuarios - 1; j++) {
            id2 = id1;
            cin >> id1;
            a.unir(id1 - 1, id2 - 1);
        }
    }
    // resolver el caso posiblemente llamando a otras funciones

    // escribir la solución
    for (int i = 0; i < N; i++) {
        cout << a.cardinal(i) << " ";
    }

    cout << '\n';

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
