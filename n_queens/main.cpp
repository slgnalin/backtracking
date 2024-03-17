#include <iostream>
#include <fstream>

using namespace std;

const int SIZE = 20;

const char INPUT_FILE[100] = "n_queens/input/main.txt";

int n;
int v[SIZE];

int sol;

int valid(int k);

int solutie(int k);

void citire();

void afisare();

void backtrack(int k);

int main() {

    citire();

    backtrack(1);
}

void backtrack(int k) {
    for (int i = 1; i <= n; i++) {
        v[k] = i;

        if (valid(k)) {
            if (solutie(k)) {
                afisare();
            } else {
                backtrack(k + 1);
            }
        }

    }

}

int valid(int k) {
    for (int i = 1; i <= k - 1; i++) {
        if ((v[i] == v[k])
            || (abs(v[k] - v[i]) == (k - i))) {
            return 0;
        }
    }

    return 1;
}

int solutie(int k) {
    return k == n;
}

void afisare() {
    int i, j, x;

    sol++;

    cout << "\nSolutia: " << sol << endl;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (v[i] == j) {
                cout << "D ";
            } else {
                cout << "x ";
            }
        }
        cout << endl;
    }
}

void citire() {
    ifstream fin(INPUT_FILE);

    if (!fin.is_open()) {
        cerr << "Could not open " << INPUT_FILE << endl;
    }

    fin >> n;

    cout << "n = " << n << endl;
}