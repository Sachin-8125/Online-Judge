#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n, caseNum = 1;
    while (cin >> n && n >= 0) {
        int steps = 0;
        if (n > 1) {
            double x = log10(n) / log10(2);
            steps = ceil(x);  
        }
        cout << "Case " << caseNum++ << ": " << steps << endl;
    }
    return 0;
}