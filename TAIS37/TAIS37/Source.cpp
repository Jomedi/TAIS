
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

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
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
    // escribir la soluci�n
    cout << pilas << '\n';
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
