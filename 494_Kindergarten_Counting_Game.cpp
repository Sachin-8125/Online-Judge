#include <iostream>
#include <string>
#include <regex>
using namespace std;

int main() {
    string line;
    regex word("[A-Za-z]+"); // Match sequences of letters

    while (getline(cin, line)) {
        int count = 0;
        auto words_begin = sregex_iterator(line.begin(), line.end(), word);
        auto words_end = sregex_iterator();

        count = distance(words_begin, words_end);
        cout << count << '\n';
    }

    return 0;
}
