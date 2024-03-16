#include <iostream>
#include <fstream>

using namespace std;

const int SIZE = 20;

char fileName[100] = "input.txt";

int n, v[SIZE], w[SIZE];

void bk(int k);

void citire();

void afisare(int k);

int solutie(int k);

int main() {
    ifstream fin("input.txt");

    if (!fin.is_open()) {
        cerr << "Could not open " << fileName << endl;
        return 1;
    }

    fin >> n;

    cout << "n = " << n << endl;

    for (int i = 0; i < n; ++i) {
        fin >> w[i];
        cout << "w[" << i << "] = " << w[i] << endl;
    }

    bk(0);

    return 0;
}

// 1
// 1 2

void bk(int k) {
    for (int i = 1; i <= w[k]; i++) {
        v[k] = i;

        if (solutie(k)) {
            afisare(k);
        } else {
            bk(k + 1);
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
