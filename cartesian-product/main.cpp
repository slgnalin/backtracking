/**
 * ==========================================================================================================
 *
 * Se dau n multimi, ca cele de mai jos
 *
 * S(1) = {1, 2, ... ,w(1)}
 * S(2) = {1, 2, ... ,w(2)}
 *
 * ...
 *
 * S(n) = {1, 2, ... ,w(n)}
 *
 * Sa se genereze produsul lor cartezian
 *
 * ==========================================================================================================
 *
 * Date de intrare
 *
 * Fisierul input.txt contine pe primul rand valoare numarului `n`, reprezentand numarul de multimi
 * Pe urmatoarele `n` randuri ale fisierului sunt definite valorile w(x), reprezentand numarul de elemente din fiecare multime
 *
 * ==========================================================================================================
 *
 * Exemplu:
 *
 * Pentru urmatoarele date de intrare
 * n = 3,
 * w(1) = 2
 * w(2) = 3
 * w(3) = 2
 *
 * Fisierul input.txt este definit ca
 * ````````````````````````
 * 3
 * 2
 * 3
 * 2
 * ````````````````````````
 *
 * n = 3
 * w[0] = 2
 * w[1] = 3
 * w[2] = 2
 *
 * (1, 1, 1)
 * (1, 1, 2)
 * (1, 2, 1)
 * (1, 2, 2)
 * (1, 3, 1)
 * (1, 3, 2)
 * (2, 1, 1)
 * (2, 1, 2)
 * (2, 2, 1)
 * (2, 2, 2)
 * (2, 3, 1)
 * (2, 3, 2)
 *
 *
 * ==========================================================================================================
 * */

#include <iostream>
#include <fstream>

using namespace std;

const int SIZE = 20;

const char INPUT_FILE[100] = "../cartesian-product/input/input.txt";

int n;
int v[SIZE];
int w[SIZE];

void backtrack(int k);

void citire();

void afisare(int k);

int solutie(int k);

int main() {
    citire();

    backtrack(0);

    return 0;
}


void backtrack(int k) {
    for (int i = 1; i <= w[k]; i++) {
        v[k] = i;

        if (solutie(k)) {
            afisare(k);
        } else {
            backtrack(k + 1);
        }
    }
}

int solutie(int k) {
    return k == n - 1;
}

void afisare(int k) {
    for (int i = 0; i <= k; i++) {
        cout << v[i] << " ";
    }

    cout << endl;
}

void citire() {
    ifstream fin(INPUT_FILE);

    if (!fin.is_open()) {
        cerr << "Could not open " << INPUT_FILE << endl;
    }

    fin >> n;

    cout << "n = " << n << endl;

    for (int i = 0; i < n; ++i) {
        fin >> w[i];
        cout << "w[" << i << "] = " << w[i] << endl;
    }

}