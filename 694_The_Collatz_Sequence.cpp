#include <iostream>
using namespace std;

int main() {
    long long A, L, caseNum = 0;
    while (cin >> A >> L, A >= 0 && L >= 0) {
        long long terms = 1, x = A, limit = (L - 1) / 3;
        caseNum++;

        while (x != 1) {
            if ((x & 1) == 0) {  // even
                x >>= 1;
                terms++;
            } else {
                if (x <= limit) {
                    x = 3 * x + 1;
                    terms++;
                } else {
                    break;
                }
            }
        }
        cout << "Case " << caseNum << ": A = " << A << ", limit = " << L << ", number of terms = " << terms << '\n';
    }
    return 0;
}
