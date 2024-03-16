#include <iostream>
#include <fstream>

using namespace std;

const int SIZE = 20;

const char INPUT_FILE[100] = "../cartesian-product/input.txt";

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
    return k == n-1;
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