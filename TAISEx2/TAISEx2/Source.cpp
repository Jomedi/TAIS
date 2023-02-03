/*
 * MUY IMPORTANTE: Solo se corregir�n los comentarios y el c�digo
 * contenidos entre las etiquetas <answer> y </answer>.
 * Toda modificaci�n fuera de esas etiquetas no ser� corregida.
 */

 /*@ <answer>
  *
  * Indicad el nombre completo y usuario del juez de quienes hab�is hecho esta soluci�n:
  * Estudiante 1: Jorge Medina Carretero
  * Estudiante 2: Alexey Modorov 
  *
  *@ </answer> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <limits>
#include <queue>
using namespace std;


/*@ <answer>

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 Coste : O(nlogn)
 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo (despu�s de la marca)
 //@ <answer>

class ComparaInstrumento {
public:
    bool operator()(pair<int, int> const& a, pair<int, int> const& b) {
        return (a.first / a.second < b.first / b.second) || (a.first / a.second == b.first / b.second) && a.first % a.second < b.first % b.second;
    }
};


bool resuelveCaso() { //O(nlogn)

    // leemos la entrada
    int P, N;
    cin >> P >> N;

    if (!cin)
        return false;

    priority_queue<pair<int,int>, vector<pair<int,int>>, ComparaInstrumento> cola;

    pair<int, int> p;
    int partiturasRestantes = P - N;

    p.second = 1;

    // leer el resto del caso y resolverlo
    for (int i = 0; i < N; i++) { //O(nlogn)
        cin >> p.first;
        cola.push(p);
    }

    for (int i = 0; i < partiturasRestantes; i++) { //O(nlogn)
        auto partituras = cola.top();
        cola.pop();
        partituras.second++;
        cola.push(partituras);
    }

    int resto = cola.top().first % cola.top().second;
    if(resto == 0)
        cout << (cola.top().first / cola.top().second) << '\n';
    else
        cout << (cola.top().first / cola.top().second) + 1 << '\n';

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

    // Resolvemos
    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
