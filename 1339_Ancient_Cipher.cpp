#include <bits/stdc++.h>
using namespace std;

#define MAX 110

void countFreq(const string &str, vector<int> &cnt) {
    for (char c : str) {
        cnt[c - 'A']++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string str1, str2;
    while (cin >> str1 >> str2) {
        vector<int> cnt1(26, 0), cnt2(26, 0);

        countFreq(str1, cnt1);
        countFreq(str2, cnt2);

        sort(cnt1.begin(), cnt1.end());
        sort(cnt2.begin(), cnt2.end());

        if (cnt1 == cnt2)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}