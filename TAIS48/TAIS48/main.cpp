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
#include <string>
using namespace std;

#include "Matriz.h"

/*@ <answer>

 Se calcula el número de letras iguales entre las dos palabras con el primer doble for, lo que hace es detectar la cadena máxima de letras que existe en una palabra y en otra cuando detecta que el índice i y el
 índice j contienen la misma letra, le añade a la matriz el marcador.

 Después el bucle comprueba desde el final de las palabras si las letras coinciden, si no iremos decrementando el índice para comprobar la letra anterior de cada palabra. Si coinciden incrementamos el contador
 el cual nunca va a superar la cadena máxima que habíamos calculado con los primeros fors.
  
 @ </answer> */

// ================================================================
// Escribe el código completo de tu solución aquí debajo (después de la marca)
//@ <answer>

bool resuelveCaso() {
  
  // leemos la entrada
  string X, Y;
  cin >> X >> Y;

  if (!cin)
    return false;

  int N = X.size();
  int T = Y.size();

  Matriz<int> m(X.size() + 1, Y.size() + 1, 0);

  for (int i = 1; i <= N; ++i){
      for (int j = 1; j <= T; ++j){
          if (X[i - 1] == Y[j - 1])
              m[i][j] = m[i - 1][j - 1] + 1;
          else
              m[i][j] = max(m[i - 1][j], m[i][j - 1]);
      }
  }

  int letras = m[N][T];
  int recY = Y.size(), recX = X.size(), cont = 0;
  string subconjunto(letras, ' ');

  while (cont < letras){
      if (X[recX - 1] == Y[recY - 1]){
          subconjunto[letras - cont - 1] = X[recX - 1];
          recX--;
          recY--;
          cont++;
      }
      else{
          if (m[recX][recY] == m[recX - 1][recY])
              recX--;
          else if (m[recX][recY] == m[recX][recY - 1])
              recY--;
      }
  }

  cout << subconjunto << '\n';
  // resolver el caso
  
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
