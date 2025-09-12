#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        int N, K;
        cin >> N >> K;
        
        vector<vector<int>> equipment(N, vector<int>(5));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < 5; j++) {
                cin >> equipment[i][j];
            }
        }
        
        int maxScore = 0;
        
        function<void(int, int, vector<int>&)> solve = [&](int idx, int selected, vector<int>& maxScores) {
            if (selected == K) {
                int score = 0;
                for (int j = 0; j < 5; j++) {
                    score += maxScores[j];
                }
                maxScore = max(maxScore, score);
                return;
            }
            
            if (idx == N || selected + (N - idx) < K) {
                return;
            }
            
            // Include current equipment
            vector<int> newMaxScores = maxScores;
            for (int j = 0; j < 5; j++) {
                newMaxScores[j] = max(newMaxScores[j], equipment[idx][j]);
            }
            solve(idx + 1, selected + 1, newMaxScores);
            
            // Skip current equipment
            solve(idx + 1, selected, maxScores);
        };
        
        vector<int> initialMaxScores(5, 0);
        solve(0, 0, initialMaxScores);
        
        cout << maxScore << "\n";
    }
    
    return 0;
}