#include <iostream>
#include <cmath>
#include <map>
#include<climits>
using namespace std;

// Factorize b into primes and their exponents
void factorize(int b, map<int, int>& factors) {
    for (int i = 2; i*i <= b; ++i) {
        while (b % i == 0) {
            ++factors[i];
            b /= i;
        }
    }
    if (b > 1) ++factors[b];
}

// Count occurrences of p in n!
int count_p_in_n_factorial(int n, int p) {
    int count = 0;
    while (n) {
        n /= p;
        count += n;
    }
    return count;
}

int main() {
    int n, b;
    while (cin >> n >> b) {
        // Trailing zeros calculation
        map<int, int> factors;
        factorize(b, factors);

        int min_zeros = INT_MAX;
        for (auto f : factors) {
            int total = count_p_in_n_factorial(n, f.first) / f.second;
            min_zeros = min(min_zeros, total);
        }

        // Digits calculation
        double sum_log = 0.0;
        for (int i = 1; i <= n; ++i)
            sum_log += log10(i);

        int digits = int(sum_log / log10(b)) + 1;

        cout << min_zeros << " " << digits << endl;
    }
    return 0;
}
