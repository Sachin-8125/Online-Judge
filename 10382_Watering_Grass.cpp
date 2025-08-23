#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct Sprinkler {
    double left, right;
    Sprinkler(double p = 0, double r = 0, double w = 0) {
        // If the radius is less than half the width, it cannot cover any part of the strip
        if (r <= w / 2.0) {
            left = right = 0; // Covered as dummy (ignore in logic)
        } else {
            double dx = sqrt(r * r - (w / 2.0) * (w / 2.0));
            left = p - dx;
            right = p + dx;
        }
    }
};

bool cmp(const Sprinkler &a, const Sprinkler &b) {
    return a.left < b.left;
}

int main() {
    int n, l, w;
    while (cin >> n >> l >> w) {
        vector<Sprinkler> s;
        for (int i = 0; i < n; i++) {
            double p, r;
            cin >> p >> r;
            if (r > w / 2.0)
                s.emplace_back(p, r, w);
        }
        sort(s.begin(), s.end(), cmp);

        double cover = 0;
        int count = 0, i = 0;
        while (cover < l) {
            double farthest = cover;
            while (i < s.size() && s[i].left <= cover) {
                farthest = max(farthest, s[i].right);
                i++;
            }
            if (farthest == cover) break; // No coverage
            cover = farthest;
            count++;
        }
        if (cover < l)
            cout << -1 << endl;
        else
            cout << count << endl;
    }
    return 0;
}

