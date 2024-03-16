#include <iostream>
#include <fstream>

using namespace std;

const int SIZE = 20;

const char INPUT_FILE[100] = "cartesian-product/input/one-set.txt";

int n;
int m;
int v[SIZE];

void backtrack(int k);

void citire();

void afisare();

int solutie(int k);

int main() {
    citire();

    backtrack(0);

    return 0;
}


void backtrack(int k) {
    if (k == m) {
        afisare();
        return;
    } else {
        v[k] = 0;

        while (v[k] < n) {
            v[k]++;
            backtrack(k + 1);
        }
    }

}

int solutie(int k) {
    return k == n - 1;
}

void afisare() {
    for (int i = 0; i < m; i++)
        cout << v[i] << " ";
    cout << endl;
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