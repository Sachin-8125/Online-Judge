#include<bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin>>N;
    vector<vector<int>> M(N, vector<int>(N));
    for (auto& row : M)
        for (auto& elem : row)
            cin >> elem;

    vector<vector<int>> sum(N, vector<int>(N + 1, 0));
    for (int i = 0; i < N; ++i)
        for (int j = 1; j <= N; ++j)
            sum[i][j] = sum[i][j - 1] + M[i][j - 1];

    int ans = numeric_limits<int>::min();

    for (int i = 0; i < N; ++i) {
        for (int j = i; j < N; ++j) {
            vector<int> dp(N + 1, 0);
            for (int k = 0; k < N; ++k) {
                int rowSum = sum[k][j + 1] - sum[k][i];
                dp[k + 1] = max(rowSum + dp[k], rowSum);
                ans = max(ans, dp[k + 1]);
            }
        }
    }
    cout << ans << '\n';
    return 0;
}