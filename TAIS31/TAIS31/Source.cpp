
/*@ <answer>
 *
 * Nombre y Apellidos: Jorge Medina Carrtero
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

#include <vector>

/*@ <answer>

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
 // ================================================================
 //@ <answer>

bool resuelveCaso() {

    // leer los datos de la entrada
    int N;
    cin >> N;
    if (!std::cin)  // fin de la entrada
        return false;

    vector<int> at(N), def(N);
    // resolver el caso posiblemente llamando a otras funciones

    for (int i = 0; i < N; i++) {
        cin >> at[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> def[i];
    }

    sort(at.begin(), at.end());
    sort(def.begin(), def.end());

    int index = 0;
    int ciudades = 0;
    for (int i = 0; i < N; i++) {
        if (at[index] <= def[i]) {
            ciudades++;
            index++;
        }   
    }

    // escribir la soluci�n
    cout << ciudades << '\n';

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
