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
using namespace std;


/*@ <answer>
 
 Explicación: Se ordenan los dos arrays de resultados de los partidos y se recorre de menor a mayor el resultado de los equipos rivales y de mayor a menor el resultado del equipo de los broncos para obtener la 
 resta máxima y solo cuando es una resta con valor positivo, se suma al total.

 @ </answer> */

// ================================================================
// Escribe el código completo de tu solución aquí debajo (después de la marca)
//@ <answer>



bool resuelveCaso() { //O(NlogN) siendo N el número de partidos
  
  int N;
  cin >> N;  // número de partidos
    
  if (N == 0) 
    return false;

  // leer el resto del caso y resolverlo
  vector<int> r(N), b(N);
  for (int i = 0; i < N; i++) {
      cin >> r[i];
  }
  for (int i = 0; i < N; i++) {
      cin >> b[i];
  }

  sort(r.begin(), r.end()); //O(NlogN)
  sort(b.begin(), b.end()); //O(NlogN)
  int resultado = 0;
  for (int i = 0; i < N; i++) { //O(N)
      if(b[N - i - 1] > r[i])
         resultado += b[N - i - 1] - r[i];
  }
  
  cout << resultado << '\n';
  
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
