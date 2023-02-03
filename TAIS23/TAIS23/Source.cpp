
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

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
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
		// escribir la solución
		if (gc.consulta())
			cout << "SI" << '\n';
		else
			cout << "NO" << '\n';
	}

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
