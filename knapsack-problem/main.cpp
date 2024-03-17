/**
 * ==========================================================================================================
 *
 * Knapsack problem
 *
 * ==========================================================================================================
 *
 *
 *
 * ==========================================================================================================
 * */


#include <iostream>
#include <fstream>

using namespace std;

const char INPUT_FILE[100] = "knapsack-problem/input/main.txt";

const int SIZE = 20;

int n;
int v[SIZE];
int sol_max[SIZE];
int g[SIZE];
int c[SIZE];
int s_max;
int G;
int nr_sol;

char nume[SIZE][SIZE];

void backtrack(int k);

int valid(int k);

void optim();

void citire();

void afisare();

int main() {

    citire();

    backtrack(1);

    afisare();
}

void backtrack(int k) {
    for (int i = 0; i <= 1; i++) {
        v[k] = i;

        if (valid(k)) {
            if (k == n) {
                optim();
            } else {
                backtrack(k + 1);
            }
        }
    }
}

int valid(int k) {
    int gr = 0;

    for (int j = 1; j <= k; j++) {
        gr = gr + v[j] * g[j];
    }

    return gr <= G;
}

void optim() {
    int s = 0;

    nr_sol++;

    for (int j = 1; j <= n; j++) {
        s = s + v[j] * c[j];
    }

    if (s > s_max) {
        s_max = s;

        for (int j = 1; j <= n; j++) {
            sol_max[j] = v[j];
        }

    }
}

void citire() {
    ifstream fin(INPUT_FILE);

    if (!fin.is_open()) {
        cerr << "Could not open " << INPUT_FILE << endl;
    }

    fin >> n >> G;


    for (int i = 1; i <= n; i++) {
        fin >> nume[i] >> g[i] >> c[i];
    }

    fin.close();
}

void afisare() {
    cout << "Castigul maxim: " << s_max << endl << endl;

    for (int i = 1; i <= n; i++) {
        if (sol_max[i]) {
            cout << nume[i] << " " << g[i] << " " << c[i] << endl;
        }
    }
    cout << endl;
}