#include <iostream>
#include <string>
using namespace std;

int main() {
    string line;

    while (getline(cin, line)) {
        if (line.empty()) {
            cout << '\n';
            continue;
        }

        int rep = 0;

        for (char ch : line) {
            if (isdigit(ch)) {
                rep += ch - '0';
            } 
            else if (ch == 'b') {
                cout << string(rep, ' ');
                rep = 0;
            } 
            else if (ch == '*') {
                cout << string(rep, '*');
                rep = 0;
            } 
            else if (ch == '!') {
                cout << '\n';
            } 
            else if (isupper(ch)) {
                cout << string(rep, ch);
                rep = 0;
            }
        }

        cout << '\n';
    }

    return 0;
}
