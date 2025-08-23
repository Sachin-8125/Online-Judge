//  104 - Arbitrage

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        vector<vector<vector<double>>> dist(n, vector<vector<double>>(n, vector<double>(n, 0)));
        vector<vector<vector<int>>> parent(n, vector<vector<int>>(n, vector<int>(n, 0)));

        // Read input and initialize dist and parent matrices
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(i != j) {
                    cin >> dist[i][j][0];
                } else {
                    dist[i][j][0] = 1.0;
                }
                parent[i][j][0] = i;
            }
        }

        // Floyd-Warshall for arbitrage detection
        for(int s = 1; s < n; ++s) {
            for(int k = 0; k < n; ++k) {
                for(int u = 0; u < n; ++u) {
                    for(int v = 0; v < n; ++v) {
                        double d = dist[u][k][s-1] * dist[k][v][0];
                        if(dist[u][v][s] < d) {
                            dist[u][v][s] = d;
                            parent[u][v][s] = k;
                        }
                    }
                }
            }
        }

        bool isProfit = false;
        for(int s = 1; s < n && !isProfit; ++s) {
            for(int u = 0; u < n; ++u) {
                if(dist[u][u][s] > 1.01) {
                    isProfit = true;
                    vector<int> profit(s+1);
                    profit[s] = parent[u][u][s];
                    for(int j = s-1; j >= 0; --j)
                        profit[j] = parent[u][profit[j+1]][j];
                    for(int j = 0; j <= s; ++j)
                        cout << (profit[j] + 1) << " ";
                    cout << (profit[0] + 1) << endl;
                    break;
                }
            }
        }
        if(!isProfit)
            cout << "no arbitrage sequence exists" << endl;
    }
    return 0;
}

