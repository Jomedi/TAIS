
/*@ <answer>
 *
 * Nombre y Apellidos: Jorge Medina Carretero
 *
 *@ </answer> */

#include <iostream>
#include <fstream>

using namespace std;

#include "Matriz.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
 // ================================================================
 //@ <answer>

struct Cofre { int profundidad; int oro; };
double mochila_rec(vector<Cofre> const& obj, int i, int j, Matriz<double>& mochila) {
    if (mochila[i][j] != -1) // subproblema ya resuelto
        return mochila[i][j];
    if (i == 0 || j == 0) mochila[i][j] = 0;
    else if (obj[i - 1].profundidad > j)
        mochila[i][j] = mochila_rec(obj, i - 1, j, mochila);
    else
        mochila[i][j] = max(mochila_rec(obj, i - 1, j, mochila), mochila_rec(obj, i - 1, j - obj[i - 1].profundidad, mochila) + obj[i - 1].oro);
    return mochila[i][j];
}

double mochila(vector<Cofre> const& cofres, int M, vector<bool>& sol) {
    int n = cofres.size();
    Matriz<double> mochila(n + 1, M + 1, -1);
    double valor = mochila_rec(cofres, n, M, mochila);
    // c�lculo de los cofres
    int i = n, j = M;
    sol = vector<bool>(n, false);
    while (i > 0 && j > 0) {
        if (mochila[i][j] != mochila[i - 1][j]) {
            sol[i - 1] = true; j = j - cofres[i - 1].profundidad;
        }
        --i;
    }
    return valor;
}

bool resuelveCaso() {
    // leer los datos de la entrada
    int T;
    cin >> T;

    if (!std::cin)  // fin de la entrada
        return false;

    int N;
    cin >> N;
    int p, o;
    vector<Cofre> v(N);
    for (int i = 0; i < N; i++) {
        cin >> p >> o;
        v[i].profundidad = 3*p;
        v[i].oro = o;
    }
    // resolver el caso posiblemente llamando a otras funciones
    vector<bool> sol;
    double valor = mochila(v, T, sol);
    cout << valor << '\n';
    int cont = 0;
    for (int i = 0; i < sol.size(); i++) {
        if (sol[i])
            cont++;
    }
    cout << cont << '\n';
    for (int i = 0; i < sol.size(); i++) {
        if (sol[i]) 
            cout << v[i].profundidad / 3 << " " << v[i].oro << '\n';
    }
    // escribir la soluci�n
    cout << "---" << '\n';

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
