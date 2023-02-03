/*
 * MUY IMPORTANTE: Solo se corregirán los comentarios y el código
 * contenidos entre las etiquetas <answer> y </answer>.
 * Toda modificación fuera de esas etiquetas no será corregida.
 */

 /*@ <answer>
  *
  * Indicad el nombre completo y usuario del juez de quienes habéis hecho esta solución:
  * Estudiante 1: Alexey Morozov Korzhenkov
  * Estudiante 2: Jorge Medina Carretero
  *
  *@ </answer> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <limits>
#include <queue>
#include <map>
#include "Grafos.h"
using namespace std;


class CaminosDFS {
private:
	std::vector<bool> visit;
	std::vector<int> ant;
	int s;
	void dfs(Grafo const& G, int v) {
		visit[v] = true;
		for (int w : G.ady(v)) {
			if (!visit[w]) {
				ant[w] = v;
				dfs(G, w);
			}
		}
	}
public:
	CaminosDFS(Grafo const& g, int s) : visit(g.V(), false),
		ant(g.V()), s(s) {
		dfs(g, s);
	}
	// ¿hay camino del origen a v?
	bool hayCamino(int v) const {
		return visit[v];
	}
	using Camino = std::deque<int>; // para representar caminos
// devuelve un camino desde el origen a v (debe existir)
	Camino camino(int v) const {
		if (!hayCamino(v))
			throw std::domain_error("No existe camino");
		Camino cam;
		// recuperamos el camino retrocediendo
		for (int x = v; x != s; x = ant[x])
			cam.push_front(x);
		cam.push_front(s);
		return cam;
	}
};

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo (después de la marca)
 //@ <answer>


int res(Grafo g, vector<int> va, vector<bool> marcas) {

	int ress = 0;
	int menor = 0;
	int i = 0;

	while (i < g.V()) {

		if (marcas[i] == false) {
			if (g.ady(i).size() == 0) {
				ress += va[i];
			}
			else {
				menor = va[g.ady(i).at(0)];
				for (int j = 1; j < g.ady(i).size(); j++) {
					if (menor > va[g.ady(i).at(j)]) menor = va[g.ady(i).at(j)];
					marcas[g.ady(i).at(j)] = true;
				}
				ress += menor;
			}
		}
		++i;
	}

	return ress;
}


bool resuelveCaso() {

	// leemos la entrada
	int N, M;
	cin >> N >> M;

	if (!cin)
		return false;

	// leer el resto del caso y resolverlo

	int coste, v1, v2;
	vector<int> va;
	vector<bool> marcas;
	Grafo g(N);

	for (int i = 0; i < N; i++) { //dinero
		cin >> coste;
		va.push_back(coste);
		marcas.push_back(false);
	}

	for (int i = 0; i < M; i++) {//aristas
		cin >> v1 >> v2;
		g.ponArista(v1 - 1, v2 - 1);
	}


	cout << res(g, va, marcas) << '\n';

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

	// Resolvemos
	while (resuelveCaso());

	// para dejar todo como estaba al principio
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}