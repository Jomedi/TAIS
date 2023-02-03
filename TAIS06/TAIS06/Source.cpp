
/*@ <answer>
 *
 * Nombre y Apellidos: Jorge Medina Carretero
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
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

struct periodo {
    int ini;
    int fin;
    int periodo;
};

bool operator<(periodo const& a, periodo const& b) {
    return a.ini > b.ini || (a.ini == b.ini && a.fin < b.fin);
}

bool resuelveCaso() {

    // leer los datos de la entrada
    int n;
    cin >> n;

    if (!std::cin)  // fin de la entrada
        return false;

    priority_queue<periodo> cola;
    int m, t;
    cin >> m >> t;

    int ini, fin, per;
    for (int i = 0; i < n; i++) {
        cin >> ini >> fin;
        cola.push({ ini,fin,0 });
    }
    for (int i = 0; i < m; i++) {
        cin >> ini >> fin >> per;
        cola.push({ ini,fin,per });
    }
    
    // resolver el caso posiblemente llamando a otras funciones
    bool conflicto = false;
    int ocupado = 0;
    while (!conflicto && !cola.empty() && cola.top().ini < t) {
        auto [ini, fin, inter] = cola.top(); cola.pop();
        conflicto = ini < ocupado;
        ocupado = fin;
        if (inter > 0)
            cola.push({ ini + inter, fin + inter, inter });
    }
    // escribir la solución
    if (conflicto)
        cout << "SI\n";
    else
        cout << "NO\n";

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

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
