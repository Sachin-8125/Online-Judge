#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCases;
    cin >> testCases;

    const int SIZE = 1025;

    while (testCases--) {
        int d, n;
        cin >> d;
        cin >> n;

        vector<vector<int>> grid(SIZE, vector<int>(SIZE, 0));

        for (int i = 0; i < n; i++) {
            int x, y, rats;
            cin >> x >> y >> rats;

            grid[x][y] = rats;
        }

        vector<vector<int>> prefix(SIZE + 1, vector<int>(SIZE + 1, 0));

        for (int x = 1; x <= SIZE; x++) {
            for (int y = 1; y <= SIZE; y++) {
                prefix[x][y] =
                    grid[x - 1][y - 1]
                    + prefix[x - 1][y]
                    + prefix[x][y - 1]
                    - prefix[x - 1][y - 1];
            }
        }

        int bestX = 0;
        int bestY = 0;
        int bestSum = -1;

        for (int x = 0; x < SIZE; x++) {
            for (int y = 0; y < SIZE; y++) {
                int x1 = max(0, x - d);
                int x2 = min(1024, x + d);

                int y1 = max(0, y - d);
                int y2 = min(1024, y + d);

                int currentSum =
                    prefix[x2 + 1][y2 + 1]
                    - prefix[x1][y2 + 1]
                    - prefix[x2 + 1][y1]
                    + prefix[x1][y1];

                if (currentSum > bestSum) {
                    bestSum = currentSum;
                    bestX = x;
                    bestY = y;
                }
            }
        }

        cout << bestX << ' ' << bestY << ' ' << bestSum << '\n';
    }

    return 0;
}