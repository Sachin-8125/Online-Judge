#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<int> S(n);
        for (int i = 0; i < n; ++i) cin >> S[i];
        sort(S.begin(), S.end());
        bool found = false;
        for (int i = n - 1; i >= 0 && !found; --i) {
            int d = S[i];
            for (int j = 0; j < n && !found; ++j) {
                if (i == j) continue;
                for (int k = 0; k < n && !found; ++k) {
                    if (i == k || j == k) continue;
                    int c = d - S[j] - S[k];
                    // Find c in S, c != d, c != S[j], c != S[k]
                    if (c == d || c == S[j] || c == S[k]) continue;
                    if (binary_search(S.begin(), S.end(), c)) {
                        cout << d << endl;
                        found = true;
                        break;
                    }
                }
            }
        }
        if (!found) cout << "no solution" << endl;
    }
    return 0;
}
