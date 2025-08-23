//  103 - Stacking Boxes

#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

struct Box {
    vector<int> dims;
    int idx;
    Box(vector<int> d, int i) : dims(d), idx(i) {}
};

bool canNest(const Box& a, const Box& b) {
    // a can nest in b if for all i, a.dims[i] < b.dims[i]
    for (int i = 0; i < a.dims.size(); ++i) {
        if (a.dims[i] >= b.dims[i])
            return false;
    }
    return true;
}

int main() {
    string line;
    while (getline(cin, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        int k, n;
        ss >> k >> n;
        vector<Box> boxes;
        for (int i = 0; i < k; ++i) {
            vector<int> dims(n);
            for (int j = 0; j < n; ++j) cin >> dims[j];
            sort(dims.begin(), dims.end());
            boxes.push_back(Box(dims, i + 1));
        }
        // Sort boxes lexicographically by dimensions for easier DP
        sort(boxes.begin(), boxes.end(), [](const Box& a, const Box& b) {
            return a.dims < b.dims;
        });

        // DP: dp[i] = length of longest nesting ending at box i
        vector<int> dp(k, 1), prev(k, -1);
        int maxlen = 1, maxidx = 0;
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < i; ++j) {
                if (canNest(boxes[j], boxes[i])) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        prev[i] = j;
                    }
                }
            }
            if (dp[i] > maxlen) {
                maxlen = dp[i];
                maxidx = i;
            }
        }

        // Reconstruct path
        vector<int> path;
        for (int idx = maxidx; idx != -1; idx = prev[idx]) {
            path.push_back(boxes[idx].idx);
        }
        reverse(path.begin(), path.end());

        // Output
        cout << maxlen << endl;
        for (int i = 0; i < path.size(); ++i) {
            cout << path[i];
            if (i + 1 < path.size()) cout << " ";
        }
        cout << endl;

        // To handle interleaved input (cin/cout)
        cin.ignore();
    }
    return 0;
}

