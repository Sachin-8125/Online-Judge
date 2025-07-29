#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    cin >> T;
    const char symbol[] = {' ', '.', 'x', 'W'};

    while (T--) {
        int dna[10];
        for (int &x : dna) cin >> x;

        int population[40] = {};
        population[19] = 1;

        for (int day = 0; day < 50; ++day) {
            for (int i = 0; i < 40; ++i)
                cout << symbol[population[i]];
            cout << "\n";

            if (day < 49) {
                int backup[40];
                memcpy(backup, population, sizeof population);
                for (int i = 0; i < 40; ++i) {
                    int s = backup[i];
                    if (i > 0) s += backup[i - 1];
                    if (i < 39) s += backup[i + 1];
                    population[i] = dna[s];
                }
            }
        }
        if (T) cout << "\n";
    }
    return 0;
}