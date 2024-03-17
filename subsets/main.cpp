/**
 * ==========================================================================================================
 * Fie `n` - numar natural nenul
 * Sa se genereze toate submultimile multimii S = {1, 2, ..., n}
 *
 * ==========================================================================================================
 *
 * Exemplu:
 *
 * Pentru n = 3
 * S = {1, 2, 3}
 *
 * Submultimile sunt urmatoarele:
 *
 * Multimea vida
 * {1}
 * {2}
 * {3}
 * {1, 2}
 * {1, 3}
 * {2, 3}
 * {1, 2, 3}
 *
 * ==========================================================================================================
 * */

#include <iostream>
#include <fstream>

using namespace std;

const int SIZE = 20;

const char INPUT_FILE[100] = "subsets/input/main.txt";

int n;
int p;
int v[SIZE];

void backtrack(int k);

void citire();

void afisare(int k);

int solutie(int k);

int main() {

    citire();

    cout << "multimea vida" << endl;

    for (p = 1; p <= n; p++) {
        backtrack(1);
    }

    return 0;
}

void backtrack(int k) {
    for (int i = v[k - 1] + 1; i <= n; i++) {
        v[k] = i;

        if (solutie(k)) {
            afisare(k);
        } else {
            backtrack(k + 1);
        }
    }
}

int solutie(int k) {
    return k == p;
}

void afisare(int k) {
    cout << "{";
    for (int i = 1; i < k; i++) {
        cout << v[i] << ", ";
    }

    cout << v[k] << "}" << endl;
}

void citire() {
    ifstream fin(INPUT_FILE);

    if (!fin.is_open()) {
        cerr << "Could not open " << INPUT_FILE << endl;
    }

    fin >> n;

    cout << "n = " << n << endl;
}