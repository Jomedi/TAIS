
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

bool resuelveCaso() {

    // leer los datos de la entrada
    int pesoMax, usuarios;
    cin >> pesoMax >> usuarios;

    if (!std::cin)  // fin de la entrada
        return false;

    int peso;
    vector<int> cre(usuarios), dec(usuarios);
    for (int i = 0; i < usuarios; i++) {
        cin >> cre[i];
        dec[i] = cre[i];
    }

    // resolver el caso posiblemente llamando a otras funciones
    sort(cre.begin(), cre.end());
    sort(dec.begin(), dec.end(), greater<int>());
    
    int personas = 0, viajes = 0;
    while (personas < usuarios) {
        int mayor = cre.back(), menor = dec.back();
        if (mayor + menor <= pesoMax) {
            personas += 2;
            cre.pop_back();
            dec.pop_back();
        }
        else {
            cre.pop_back();
            personas++;
        }
        viajes++;
    }

    // escribir la soluci�n
    cout << viajes << '\n';

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
