/**
 * ==========================================================================================================
 *
 * - Fie `n` si `m` doua numere naturale nenule
 * - Consideram multimea A = {1, 2, ... n}
 * - Consideram multimea B = {1, 2, ... m}
 * - Sa se genereze elementele produsului cartezian A x B
 *
 * ==========================================================================================================
 *
 * Date de intrare:
 *
 * - Fisierul input.txt contine pe prima linie numerele `n` si `m` separate printr-un spatiu ` `
 *
 * ==========================================================================================================
 *
 * Exemplu:
 *
 * Pentru n = 2 si m = 3,
 *
 * multimea A = {1, 2}
 * multimea B = {1, 2, 3}
 *
 * produsul cartezian A x B = {
 * (1, 1), (1, 2), (1, 3), (1, 4), (1, 5),
 * (2, 1), (2, 2), (2, 3), (2, 4), (2, 5),
 * (3, 1), (3, 2), (3, 3), (3, 4), (3, 5),
 * }
 *
 * ==========================================================================================================
 * */


#include <iostream>
#include <fstream>

using namespace std;

const int SIZE = 20;

const char INPUT_FILE[100] = "cartesian-product/input/two-sets-no-backtracking.txt";

int n;
int m;

void citire();

int main() {
    citire();

    cout << "Produsul cartezian A x B este: \n";

    for (int a = 1; a <= n; ++a) {
        for (int b = 1; b <= m; ++b) {
            cout << "(" << a << ", " << b << ") ";
        }
        cout << endl;
    }

    return 0;
}

void citire() {
    ifstream fin(INPUT_FILE);

    if (!fin.is_open()) {
        cerr << "Could not open " << INPUT_FILE << endl;
    }

    fin >> n >> m;

    cout << "n = " << n << endl;
    cout << "m = " << m << endl;
}