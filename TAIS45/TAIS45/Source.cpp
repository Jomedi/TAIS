
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

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

// calcula la longitud del mayor palíndromo en patitos[i..j]
int patin_rec(string const& patitos, int i, int j, Matriz<int>& patin) {
    int& res = patin[i][j];
    if (res == -1) {
        if (i > j) res = 0;
        else if (i == j) res = 1;
        else if (patitos[i] == patitos[j])
            res = patin_rec(patitos, i + 1, j - 1, patin) + 2;
        else
            res = max(patin_rec(patitos, i + 1, j, patin),
                patin_rec(patitos, i, j - 1, patin));
    }
    return res;
}

// devuelve el palíndromo más largo en patitos[i..j]
string reconstruir(string const& patitos, Matriz<int> const& patin, int i, int j) {
    if (i > j) return {};
    if (i == j) return { patitos[i] };
    if (patitos[i] == patitos[j])
        return patitos[i] + reconstruir(patitos, patin, i + 1, j - 1) + patitos[j];
    else if (patin[i][j] == patin[i + 1][j])
        return reconstruir(patitos, patin, i + 1, j);
    else
        return reconstruir(patitos, patin, i, j - 1);
}

// añade al final de sol el palíndromo más largo en patitos[i..j]
void reconstruir(string const& patitos, Matriz<int> const& patin, int i, int j, string& sol) {
    if (i > j) return;
    if (i == j) sol.push_back(patitos[i]);
    else if (patitos[i] == patitos[j]) {
        sol.push_back(patitos[i]);
        reconstruir(patitos, patin, i + 1, j - 1, sol);
        sol.push_back(patitos[j]);
    }
    else if (patin[i][j] == patin[i + 1][j])
        reconstruir(patitos, patin, i + 1, j, sol);
    else
        reconstruir(patitos, patin, i, j - 1, sol);
}

bool resuelveCaso() {
    // leer los datos de la entrada
    string palabra;
    cin >> palabra;
   
    if (!std::cin)  // fin de la entrada
        return false;

    // resolver el caso posiblemente llamando a otras funciones
    int n = palabra.length();
    vector<vector<int>> minParaPalindromo(n, vector<int>(n, 0));
    for (int d = 1; d < n; d++)
        for (int j = d; j < n; j++) {
            int i = j - d;
            if (palabra[i] == palabra[j])
                minParaPalindromo[i][j] = minParaPalindromo[i + 1][j - 1];
            else 
                minParaPalindromo[i][j] = 1 + min(minParaPalindromo[i][j - 1], minParaPalindromo[i + 1][j]);
        }

    // escribir la solución
    int letras = minParaPalindromo[0][n - 1];
    cout << letras << '\n';
    string aux = "";
    for (int i = 0; i < letras; i++) {
        aux += palabra
    }

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
