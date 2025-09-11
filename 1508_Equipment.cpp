#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<vector<int>> eq(N, vector<int>(5));
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < 5; ++j)
                cin >> eq[i][j];

        int best = 0;
        // There are 2^5 = 32 possible category "masks"
        // For each mask, try to maximize categories individually using greedy for K
        for (int mask = 0; mask < (1 << 5); ++mask) {
            // For each item, compute score given this mask
            vector<int> scores;
            for (int i = 0; i < N; ++i) {
                int score = 0;
                for (int j = 0; j < 5; ++j)
                    if (mask & (1 << j))
                        score += eq[i][j];
                scores.push_back(score);
            }
            sort(scores.rbegin(), scores.rend());
            vector<int> maxScore(5, 0);
            for (int sel = 0; sel < K && sel < N; ++sel) {
                for (int j = 0; j < 5; ++j) {
                    if (mask & (1 << j)) {
                        maxScore[j] = max(maxScore[j], eq[sel][j]);
                    }
                }
            }
            // Compute total max for this selection
            int total = 0;
            for (int j = 0; j < 5; ++j) total += maxScore[j];
            best = max(best, total);
        }

        // In reality, you just need to pick the top K in each column,
        // so for each column, get the K largest, take the largest in each column.
        int brute = 0;
        for (int j = 0; j < 5; ++j) {
            vector<int> values;
            for (int i = 0; i < N; ++i)
                values.push_back(eq[i][j]);
            sort(values.rbegin(), values.rend());
            brute += values[0];
            for (int i = 1; i < K && i < N; ++i)
                brute = max(brute, brute + values[i] - values[0]);
        }
        // Just take the best found (should suffice for constraints)
        cout << max(brute, best) << "\n";
    }
    return 0;
}