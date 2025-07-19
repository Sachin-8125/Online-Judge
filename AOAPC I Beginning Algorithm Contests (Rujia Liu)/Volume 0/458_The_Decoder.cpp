#include <iostream>
#include <string>
using namespace std;

int main() {
    string line;
    const int shift = 7;

    while (getline(cin, line)) {
        for (char c : line) {
            cout << static_cast<char>(c - shift);
        }
        cout << '\n';  // Print each decoded message on a new line
    }

    return 0;
}
