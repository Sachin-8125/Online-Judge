#include <iostream>
#include<algorithm>
#include <string>
using namespace std;

int main() {
    int N;
    while (cin >> N && N != 0) {
        cin.ignore();
        int total = 0, minSpace = 25; // Line width is at most 25

        int spaces[N]; // fixed-size for simplicity
        for (int i = 0; i < N; ++i) {
            string line;
            getline(cin, line);
            spaces[i] = count(line.begin(), line.end(), ' ');
            minSpace = min(minSpace, spaces[i]);
        }

        for (int i = 0; i < N; ++i)
            total += spaces[i] - minSpace;

        cout << total << '\n';
    }
    return 0;
}