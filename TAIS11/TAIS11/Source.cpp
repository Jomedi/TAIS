
/*@ <answer>
 *
 * Nombre y Apellidos: Jorge Medina Carretero
 *
 *@ </answer> */

#include <iostream>
#include <fstream>

using namespace std;

#include "Grafo.h"  // propios o los de las estructuras de datos de clase
#include <deque>

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

class MaximaCompConexa {
public:
    bool freeTree = false;
    bool cicle = false;
    MaximaCompConexa(Grafo const& g, int v) : visit(g.V(), false) {
        freeTree = isFreeTree(g, v);
    }

private:
    vector<bool> visit; // visit[v] = se ha visitado el vértice v?
    int dfs(Grafo const& g, int v, int ant) {
        visit[v] = true;
        int tam = 1;
        for (int w : g.ady(v)) {
            if (!visit[w])
                tam += dfs(g, w, v);
            else if (ant != -1 && w != ant)
                cicle = true;
        }
        return tam;
    }

    bool isFreeTree(Grafo const& g, int v) {
        return (g.V() == dfs(g, v, -1)) && !cicle;
    }

};

bool resuelveCaso() {

    // leer los datos de la entrada
    int V, A, v1, v2 = 0;
    cin >> V;
    if (!std::cin)  // fin de la entrada
        return false;

    Grafo g = Grafo(V);

    cin >> A;
    for (int i = 0; i < A; i++) {
        cin >> v1 >> v2;
        g.ponArista(v1, v2);
    }

    // resolver el caso posiblemente llamando a otras funciones
    MaximaCompConexa camino = MaximaCompConexa(g, v2);

    // escribir la solución
    if (camino.freeTree)
        cout << "SI";
    else
        cout << "NO";

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
