
/*@ <answer>
 *
 * Nombre y Apellidos: Jorge Medina Carretero
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

#include "Grafo.h"  // propios o los de las estructuras de datos de clase

/*@ <answer>

 Escribe aqu� un comentario general sobre la soluci�n, explicando c�mo
 se resuelve el problema y cu�l es el coste de la soluci�n, en funci�n
 del tama�o del problema.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
 // ================================================================
 //@ <answer>

class CaminoMasCorto {
public:
    CaminoMasCorto(Grafo const& g, int s) : visit(g.V(), false),
        ant(g.V()), dist(g.V()), s(s) {
        bfs(g);
    }
    // �hay camino del origen a v?
    bool hayCamino(int v) const {
        return visit[v];
    }
    // n�mero de aristas entre s y v
    int distancia(int v) const {
        return dist[v];
    }
private:
    std::vector<bool> visit; // visit[v] = �hay camino de s a v?
    std::vector<int> ant; // ant[v] = �ltimo v�rtice antes de llegar a v
    std::vector<int> dist; // dist[v] = aristas en el camino s-v m�s corto
    int s;
    void bfs(Grafo const& g) {
        std::queue<int> q;
        dist[s] = 0; visit[s] = true;
        q.push(s);
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (int w : g.ady(v)) {
                if (!visit[w]) {
                    ant[w] = v; dist[w] = dist[v] + 1; visit[w] = true;
                    q.push(w);
                }
            }
        }
    }
};
bool resuelveCaso() {

    // leer los datos de la entrada
    int N;
    cin >> N;
    if (!std::cin)  // fin de la entrada
        return false;

    Grafo g(N);
    int C;
    cin >> C;
    

    int R1, R2;
    for (int i = 0; i < C; i++) {
        cin >> R1 >> R2;
        g.ponArista(R1-1, R2-1);
    }

    int K;
    cin >> K;
    int val;
    for (int i = 0; i < K; i++) {
        int nodos = 1;
        cin >> R1 >> val;
        CaminoMasCorto cmc(g, R1 - 1);
        for (int j = 0; j < N; j++) {
            //cout << "distancia desde " << j << ": " << cmc.distancia(j) << endl;
            if (cmc.distancia(j) > 0 && cmc.distancia(j) <= val)
                nodos++;
        }
        cout << N - nodos << '\n';
    }
    // resolver el caso posiblemente llamando a otras funciones
    
    cout << "---" << '\n';

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
