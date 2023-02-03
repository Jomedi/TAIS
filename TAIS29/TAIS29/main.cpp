/*
 * MUY IMPORTANTE: Solo se corregirán los comentarios y el código
 * contenidos entre las etiquetas <answer> y </answer>.
 * Toda modificación fuera de esas etiquetas no será corregida.
 */

/*@ <answer>
 *
 * Indicad el nombre completo y usuario del juez de quienes habéis hecho esta solución:
 * Estudiante 1: Jorge Medina Carretero
 * Estudiante 2: Alexey Morozov Korzhenkov
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <limits>
#include <list>
using namespace std;

#include "DigrafoValorado.h"
#include "IndexPQ.h"

/*@ <answer>
 
 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.
 
 El coste del problema es de O(Alogv + V*Gs(V)) siendo V el número total de vértices y siendo Gs() el grado de salida \\ siendo A el número de aristas y v el número de vértices

 Hemos invertido el digrafo valorado para colocar el origen en el destino del laberinto, de esta forma podemos calcular la distancia del camino mínimo hasta cada uno de los vértices y saber si existe camino
 desde el origen hasta cada uno de ellos. Así obtenemos el número total de ratones que llegarán al destino en un tiempo menor al límite.

 @ </answer> */

// ================================================================
// Escribe el código completo de tu solución aquí debajo (después de la marca)
//@ <answer>

template <typename Valor>
class Dijkstra {
public:
    Dijkstra(DigrafoValorado<Valor> const& g, int orig) : origen(orig),
        dist(g.V(), INF), ulti(g.V()), pq(g.V()) {
        dist[origen] = 0;
        pq.push(origen, 0);
        while (!pq.empty()) {
            int v = pq.top().elem; pq.pop();
            for (auto a : g.ady(v))
                relajar(a);
        }
    }
    bool hayCamino(int v) const { return dist[v] != INF; }
    Valor distancia(int v) const { return dist[v]; }
    list<AristaDirigida<Valor>> camino(int v) const {
        list<AristaDirigida<Valor>> cam;
        // recuperamos el camino retrocediendo
        AristaDirigida<Valor> a;
        for (a = ulti[v]; a.desde() != origen; a = ulti[a.desde()])
            cam.push_front(a);
        cam.push_front(a);
        return cam;
    }
private:
    const Valor INF = std::numeric_limits<Valor>::max();
    int origen;
    std::vector<Valor> dist;
    std::vector<AristaDirigida<Valor>> ulti;
    IndexPQ<Valor> pq;
    void relajar(AristaDirigida<Valor> a) {
        int v = a.desde(), w = a.hasta();
        if (dist[w] > dist[v] + a.valor()) {
            dist[w] = dist[v] + a.valor(); ulti[w] = a;
            pq.update(w, dist[w]);
        }
    }
};

bool resuelveCaso() { //O(Alogv + V*Gs(V))
  
  // leemos la entrada
  int N, S, T, P;
  cin >> N >> S >> T >> P;
  
  if (!cin)
    return false;

  DigrafoValorado<int> dgv(N);

  // leer el resto del caso y resolverlo
  int A, B, s;
  for (int i = 0; i < P; i++) {
      cin >> A >> B >> s;
      AristaDirigida<int> ad(A - 1, B - 1, s);
      dgv.ponArista(ad);
  }

  int cont = 0;
  auto gi = dgv.inverso(); //O(V * Gs(V)) siendo V el número total de vértices y siendo Gs() el grado de salida
  Dijkstra<int> d(gi, S - 1); //O(A logv) siendo A el número de aristas y v el número de vértices
  for (int i = 0; i < N; i++) { //O(N)
      if (i != S - 1) {
          int distancia = d.distancia(i);
          if (d.hayCamino(i) && distancia <= T)
              cont++;
      } 
  }

  cout << cont << '\n';
  
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
