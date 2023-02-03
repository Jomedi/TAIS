
/*@ <answer>
 *
 * Nombre y Apellidos: Jorge Medina Carretero
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
#include <unordered_map>
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

struct registro {
    long long id;
    int periodo;
    int momento;
};

bool operator<(registro const& a, registro const& b) {
    return b.momento < a.momento ||
        (a.momento == b.momento && b.id < a.id);
}

bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;

    if (n == 0)
        return false;

   
    priority_queue<registro> cola;

    for (int i = 0; i < n; i++) {
        long long id;
        int periodo;
        cin >> id >> periodo;
        cola.push({ id, periodo, periodo });
    }

    
    // resolver el caso posiblemente llamando a otras funciones

    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        auto e = cola.top();
        cola.pop();
        cout << e.id << '\n';
        e.momento += e.periodo;
        cola.push(e);
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
