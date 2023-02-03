/*
 * MUY IMPORTANTE: Solo se corregirán los comentarios y el código
 * contenidos entre las etiquetas <answer> y </answer>.
 * Toda modificación fuera de esas etiquetas no será corregida.
 */

/*@ <answer>
 *
 * Indicad el nombre completo y usuario del juez de quienes habéis hecho esta solución:
 * Estudiante 1: Jorge Medina Carretero TAIS63
 * Estudiante 2: 
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <limits>
#include <queue>
using namespace std;


/*@ <answer>
 
 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo (después de la marca)
//@ <answer>

struct cliente {
    long long espera;
    long long caja;
};

bool operator<(cliente const& a, cliente const& b) {
    return (a.espera > b.espera) || (a.espera == b.espera && a.caja > b.caja);
}

bool resuelveCaso() {
  
  // leemos la entrada
  long long N, C;
  cin >> N >> C;
  if (N == 0 && C == 0)
    return false;
  
  // leer el resto del caso y resolverlo
  priority_queue<cliente> cola;
  long long segundos, tiempo = 0, cajaDisponible = 1, cajas = N;

  for (int i = 0; i < C; i++) {
      cin >> segundos;

      if (cajas > 0) {
          cola.push({ segundos, cajaDisponible });
          cajaDisponible++; cajas--;
      }
      else {
          tiempo = cola.top().espera;
          cajaDisponible = cola.top().caja;
          cola.pop();
          cola.push({ segundos + tiempo,cajaDisponible });
      }
  }

  if (cajas > 0)
      cout << cajaDisponible << '\n';
  else
      cout << cola.top().caja << '\n';
    
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
