#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int f;
        cin >> f;
        long long total = 0;
        for (int i = 0; i < f; ++i) {
            long long size, animals, env;
            cin >> size >> animals >> env;
            // Premium for this farmer: (size / animals) * env * animals = size * env
            total += size * env;
        }
        cout << total << endl;
    }
    return 0;
}