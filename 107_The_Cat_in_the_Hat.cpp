#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, n;
    while (cin >> h >> n && (h || n)) {
        if (h == 1) {
            cout << "0 " << n << '\n';
            continue;
        }

        double temp = log(n) / log(h);
        int N = 1;

        // Find N such that log(N)/log(N+1) is close to temp
        while (fabs(log(N) / log(N + 1) - temp) > 1e-9)
            ++N;
        int step;
        if (N > 1) {
            step = static_cast<int>(round(log(n) / log(N) + 1));
        } else {
            temp = static_cast<double>(h) / (N + 1);
            for (step = 1; round(temp) != 1; ++step)
                temp = temp / (N + 1);
            ++step;
        }

        int notWorking;
        if (n > 1) {
            notWorking = 1 + static_cast<int>(round(N * (pow(static_cast<double>(N), step - 2) - 1) / (N - 1)));
        } else {
            notWorking = step - 1;
        }

        temp = 1.0 * N / (N + 1);
        int height = static_cast<int>(round(
            h + h * (temp * (pow(temp, step - 2) - 1) / (temp - 1)) + n
        ));

        cout << notWorking << " " << height << '\n';
    }
    return 0;
}
