
/*@ <answer>
 *
 * Nombre y Apellidos: Jorge Medina Carretero
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
    int N, M;
    cin >> N >> M;
    if (!std::cin)  // fin de la entrada
        return false;

    vector<int> tallaChico(N), tallaEquipacion(M);
    for (int i = 0; i < N; i++) {
        cin >> tallaChico[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> tallaEquipacion[i];
    }

    sort(tallaChico.begin(), tallaChico.end());
    sort(tallaEquipacion.begin(), tallaEquipacion.end());

    // resolver el caso posiblemente llamando a otras funciones

    int index = 0, i = 0;
    int compras = N;
    while (index < N && i < M) {
        if (tallaChico[index] == tallaEquipacion[i] || tallaChico[index] == tallaEquipacion[i] - 1) {
            compras--;
            index++;
            i++;
        }
        else if (tallaEquipacion[i] - 1 > tallaChico[index])
            index++;
        else
            i++;
    }

    // escribir la soluci�n
    cout << compras << '\n';

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
