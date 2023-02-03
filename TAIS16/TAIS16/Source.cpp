
/*@ <answer>
 *
 * Nombre y Apellidos: Jorge Medina Carretero
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

/*@ <answer>

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo



class ConjuntosDisjuntos {
protected:
    mutable std::vector<int> p; // enlace al padre
    std::vector<int> tam; // tama�o de los �rboles
    int V;
public:
    // partici�n unitaria de N elementos
    ConjuntosDisjuntos(int N, vector<int> costes) : p(N) {
        V = N;
        tam = costes;
        for (int i = 0; i < N; ++i)
            p[i] = i;
    }
    void unir(int a, int b) {
        int i = buscar(a);
        int j = buscar(b);
        if (tam[i] >= tam[j]) { // i es la ra�z del �rbol m�s grande
            p[i] = j;
        }
        else {
            p[j] = i;
        }
    }
    int buscar(int a) const {
        if (p.at(a) == a) // es una ra�z
            return a;
        else
            return p[a] = buscar(p[a]);
    }
    int coste() {
        int c = 0;
        for (int i = 0; i < V; i++) {
            if (p[i] == i)
                c += tam[i];
        }
        return c;
    }
};

bool resuelveCaso() {

    // leer los datos de la entrada
    int N, M;
    cin >> N;

    if (!std::cin)  // fin de la entrada
        return false;

    cin >> M;

    vector<int> costes(N);
    int ci;
    for (int i = 0; i < N; i++) {
        cin >> ci;
        costes[i] = ci;
    }

    ConjuntosDisjuntos cd(N, costes);
    int n1, n2;
    for (int i = 0; i < M; i++) {
        cin >> n1 >> n2;
        cd.unir(n1-1, n2-1);
    }

    // resolver el caso posiblemente llamando a otras funciones
    cout << cd.coste() << '\n';

    // escribir la soluci�n

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
