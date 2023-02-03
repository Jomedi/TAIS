/*
 * MUY IMPORTANTE: Solo se corregir�n los comentarios y el c�digo
 * contenidos entre las etiquetas <answer> y </answer>.
 * Toda modificaci�n fuera de esas etiquetas no ser� corregida.
 */

 /*@ <answer>
  *
  * Indicad el nombre completo y usuario del juez de quienes hab�is hecho esta soluci�n:
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

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> */

 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo (despu�s de la marca)
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


bool resuelveCaso() { //O(A*Log(A)) siendo A el n�mero de aristas

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

    ARM_Kruskal<int> kr(gv); //O(a*log(a)) siendo a el n�mero de aristas
    int coste = 0;

    for (int i = 0; i < kr.numComps(); i++) {
        coste += A;
    }

    coste += kr.costeARM();
    cout << coste << " " << kr.numComps() << '\n';

    return true;
}

//@ </answer>
//  Lo que se escriba debajo de esta l�nea ya no forma parte de la soluci�n.

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
