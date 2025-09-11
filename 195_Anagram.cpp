#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Custom comparator to make 'A' < 'a'
bool cmp(char a, char b) {
    if (tolower(a) == tolower(b))
        return a < b;
    return tolower(a) < tolower(b);
}

int main() {
    int n;
    cin >> n;
    string word;
    while (n--) {
        cin >> word;
        sort(word.begin(), word.end(), cmp);
        do {
            cout << word << endl;
        } while (next_permutation(word.begin(), word.end(), customCompare));
    }
    return 0;
}