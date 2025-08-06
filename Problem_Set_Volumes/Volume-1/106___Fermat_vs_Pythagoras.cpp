//  106 - Fermat vs. Pythagoras

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
using INT = long long;

void solve(INT n) {
    vector<bool> marked(n + 1, false);
    INT tri = 0, total = 0;
    INT m = static_cast<INT>(sqrt(n)) + 1;

    for (INT r = 1; r <= m; ++r) {
        INT up = min(n - r * r, r - 1);
        for (INT s = 1; s <= up; ++s) {
            INT x = r * r - s * s;
            INT y = 2 * r * s;
            INT z = r * r + s * s;
            if (x * x + y * y == z * z && z <= n && __gcd(x, y) == 1) {
                ++tri;
                for (INT k = 1; k * z <= n; ++k) {
                    marked[k * x] = marked[k * y] = marked[k * z] = true;
                }
            }
        }
    }
    for (INT k = 1; k <= n; ++k)
        if (!marked[k]) ++total;
    cout << tri << " " << total << "\n";
}

int main() {
    INT n;
    while (cin >> n)
        solve(n);
    return 0;
}

