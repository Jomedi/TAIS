
/*@ <answer>
 *
 * Nombre y Apellidos: Jorge Medina Carretero
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include "Grafo.h"

using namespace std;


/*@ <answer>

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
 // ================================================================
 //@ <answer>


class MaximaCompConexa {
public:
    MaximaCompConexa(Grafo const& g) : visit(g.V(), false), maxim(0) {
        for (int v = 0; v < g.V(); ++v) {
            if (!visit[v]) { // se recorre una nueva componente conexa
                int tam = dfs(g, v);
                maxim = max(maxim, tam);
            }
        }
    }
    // tama�o m�ximo de una componente conexa
    int maximo() const {
        return maxim;
    }
private:
    vector<bool> visit; // visit[v] = se ha visitado el v�rtice v?
    int maxim; // tama�o de la componente mayor
    int dfs(Grafo const& g, int v) {
        visit[v] = true;
        int tam = 1;
        for (int w : g.ady(v)) {
            if (!visit[w])
                tam += dfs(g, w);
        }
        return tam;
    }
};

void resuelveCaso() {

    // leer los datos de la entrada
    int N, M;
    cin >> N >> M;

    Grafo g = Grafo(N);

    int A, B;

    for (int i = 0; i < M; i++) {
        cin >> A >> B;
        g.ponArista(A - 1, B - 1);
    }

    // resolver el caso posiblemente llamando a otras funciones
    MaximaCompConexa mcc = MaximaCompConexa(g);

    // escribir la soluci�n
    cout << mcc.maximo() << '\n';
}

//@ </answer>
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
