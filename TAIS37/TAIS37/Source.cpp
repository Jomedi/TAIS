
/*@ <answer>
 *
 * Nombre y Apellidos: Jorge Medina Carretero
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

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

void resuelveCaso() {

    // leer los datos de la entrada
    int N, V;
    cin >> N >> V;

    int pila;
    vector<int> dec(N), cre(N);
    for (int i = 0; i < N; i++) {
        cin >> pila;
        dec[i] = pila;
        cre[i] = pila;
    }

    // resolver el caso posiblemente llamando a otras funciones
    sort(dec.begin(), dec.end(), greater<int>());
    sort(cre.begin(), cre.end());

    
    int pilas = 0;
    int contC = N - 1;
    int contD = 0;
    for (int i = 0; i < N && pilas < N/2 && contD < contC; i++) {
        int mayor = cre.back(); int menor = dec.back();
        if (mayor + menor < V) {
            dec.pop_back();
            contD++;
        }
        else {
            i++;
            dec.pop_back();
            contD++;
            cre.pop_back();
            contC--;
            pilas++;
        }
    }
    // escribir la solución
    cout << pilas << '\n';
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

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
