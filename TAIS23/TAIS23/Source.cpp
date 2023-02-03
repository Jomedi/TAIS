
/*@ <answer>
 *
 * Nombre y Apellidos: Jorge Medina Carretero
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include "GrafoValorado.h"

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

class grafocalle {
public:
	grafocalle(GrafoValorado<int> g, int origen, int destino, int anchuramax) :visit(g.V(), false) {
		_anchuramax = anchuramax;
		dfs(g, origen);
		llega = visit[destino];
	}

	bool consulta() {
		return llega;
	}

private:
	bool llega;
	vector<bool> visit;
	int _anchuramax;

	void dfs(GrafoValorado<int> const& G, int v) {
		visit[v] = true;
		for (auto a : G.ady(v)) {
			int w = a.otro(v);
			if (!visit[w] && a.valor() >= _anchuramax) {
				dfs(G, w);
			}
		}
	}
};

bool resuelveCaso() {
    // leer los datos de la entrada
    int V, E, K;
    vector<int> v;
    cin >> V >> E;

    if (!std::cin)  // fin de la entrada
        return false;

    int i1, i2, ancho;
	GrafoValorado<int> g(V);

    for (int i = 0; i < E; i++) {
        cin >> i1 >> i2 >> ancho;
		Arista<int> a(i1 - 1, i2 - 1, ancho);
        g.ponArista(a);
    }
    
	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> i1 >> i2 >> ancho;
		// resolver el caso posiblemente llamando a otras funciones
		grafocalle gc(g, i1 - 1, i2 - 1, ancho);
		// escribir la soluci�n
		if (gc.consulta())
			cout << "SI" << '\n';
		else
			cout << "NO" << '\n';
	}

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
