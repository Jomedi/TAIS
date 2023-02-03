/*@ <answer>
 *
 * Nombre y Apellidos: Jorge Medina Carretero
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <climits>
#include "EnterosInf.h"


using namespace std;

/*@ <answer>

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

struct tCuerda {
    int largo;
    int coste;
};

struct tSol {
    long int nFormas;
    long int minCoste;
    long int nCuerdas;
};


vector<int> devolver_cambio(vector<int> longitudes, vector<int> costes, int L, int &numCordeles) {
    int n = longitudes.size() - 1;
    vector<int> cometas(L + 1, INT_MAX - 1);
    cometas[0] = 0;

    // calcular la matriz sobre el propio vector
    int ant = cometas[L];
    int cont = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = longitudes[i]; j <= L; ++j) {
            cometas[j] = min(cometas[j], cometas[j - longitudes[i]] + 1);
            if (j == L) {
                if (ant == cometas[j]) { 
                    cont++;
                } 
                else {
                    ant = cometas[j];
                    cont = 1;
                }
            }     
        }
    }

    numCordeles = cometas[L];
    if (numCordeles >= longitudes.size()) {
        numCordeles = -1;
        return {};
    }
    vector<int> nformas(n + 1, 0);
    vector<int> sol(n+1, 0);
    int i = n, j = L;
    while (j > 0) { // no se ha pagado todo
        if (longitudes[i] <= j && cometas[j] == cometas[j - longitudes[i]] + 1) {
            // tomamos una moneda de tipo i
            sol[i]++;
            j = j - longitudes[i];
        }
        else // no tomamos más monedas de tipo i
            --i;
    }
    
    return sol;
}

bool resuelveCaso() {

    int N, L;
    cin >> N >> L;
    if (!cin)
        return false;

    vector<tCuerda> cuerdas;
    int l, c;
    tCuerda cuerda;
    for (int i = 0; i < N; i++) {
        cin >> l >> c;
        cuerda.largo = l;
        cuerda.coste = c;
        cuerdas.push_back(cuerda);
    }

    vector<tSol> sol = vector<tSol>(L + 1);
    for (int i = 1; i <= L; i++) {
        sol[i].nFormas = 0;
        sol[i].minCoste = 0;
        sol[i].nCuerdas = 0;
    }
    sol[0].nFormas = 1;
    sol[0].minCoste = 0;
    sol[0].nCuerdas = 0;

    for (int i = 0; i < N; i++) {
        for (int j = L; j >= cuerdas[i].largo; j--) {

            if (j - cuerdas[i].largo >= 0) { //La cuerda i-esima no es demasiado grande
                sol[j].nFormas += sol[j - cuerdas[i].largo].nFormas;

                if (sol[j - cuerdas[i].largo].nFormas != 0) { //Si sol[j-cuerdas[i].largo] se puede construir

                    if (sol[j - cuerdas[i].largo].nFormas == sol[j].nFormas) {
                        //Si sol[j].nFormas era 0, no podiamos construirlo, ahora si, actualizamos valors
                        sol[j].minCoste = sol[j - cuerdas[i].largo].minCoste + cuerdas[i].coste;
                        sol[j].nCuerdas = sol[j - cuerdas[i].largo].nCuerdas + 1;
                    }
                    else {
                        sol[j].minCoste = min(sol[j].minCoste, sol[j - cuerdas[i].largo].minCoste + cuerdas[i].coste);
                        sol[j].nCuerdas = min(sol[j].nCuerdas, sol[j - cuerdas[i].largo].nCuerdas + 1);
                    }
                }

            }
        }
    }


    if (sol[L].nFormas == 0) cout << "NO" << endl;
    else  cout << "SI " << sol[L].nFormas
        << " " << sol[L].nCuerdas
        << " " << sol[L].minCoste << endl;
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