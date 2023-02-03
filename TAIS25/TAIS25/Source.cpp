/*
 * MUY IMPORTANTE: Solo se corregirán los comentarios y el código
 * contenidos entre las etiquetas <answer> y </answer>.
 * Toda modificación fuera de esas etiquetas no será corregida.
 */

 /*@ <answer>
  *
  * Indicad el nombre completo y usuario del juez de quienes habéis hecho esta solución:
  * Estudiante 1: Jorge Medina Carretero
  * Estudiante 2: Alexey Morozov
  *
  *@ </answer> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

#include "GrafoValorado.h"
#include "ConjuntosDisjuntos.h"
#include "PriorityQueue.h"


/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */

 // ================================================================
 // Escribe el código completo de tu solución aquí debajo (después de la marca)
 //@ <answer>



template <typename Valor>
class ARM_Kruskal {
private:
    std::vector<Arista<Valor>> _ARM;
    Valor coste;
    ConjuntosDisjuntos cjtos;
public:
    int numComps() {
        return cjtos.num_cjtos();
    }
    Valor costeARM() const {
        return coste;
    }
    std::vector<Arista<Valor>> const& ARM() const {
        return _ARM;
    }
    ARM_Kruskal(GrafoValorado<Valor> const& g) : coste(0), cjtos(g.V()) {
        PriorityQueue<Arista<Valor>> pq(g.aristas());
        while (!pq.empty()) {
            auto a = pq.top(); pq.pop();
            int v = a.uno(), w = a.otro(v);
            if (!cjtos.unidos(v, w)) {
                cjtos.unir(v, w);
                _ARM.push_back(a); coste += a.valor();
                if (_ARM.size() == g.V() - 1) break;
            }
        }
    }
};


bool resuelveCaso() { //O(A*Log(A)) siendo A el número de aristas

    // leemos la entrada
    int N, M, A;
    cin >> N >> M >> A;
    if (!cin)
        return false;

    GrafoValorado<int> gv(N);

    // leer el resto del caso y resolverlo
    int X, Y, C;
    for (int i = 0; i < M; i++) {
        cin >> X >> Y >> C;
        if (C < A) {
            Arista<int> a(X - 1, Y - 1, C);
            gv.ponArista(a);
        }
    }

    ARM_Kruskal<int> kr(gv); //O(a*log(a)) siendo a el número de aristas
    int coste = 0;

    for (int i = 0; i < kr.numComps(); i++) {
        coste += A;
    }

    coste += kr.costeARM();
    cout << coste << " " << kr.numComps() << '\n';

    return true;
}

//@ </answer>
//  Lo que se escriba debajo de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    // Resolvemos
    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    // system("PAUSE");
#endif
    return 0;
}
