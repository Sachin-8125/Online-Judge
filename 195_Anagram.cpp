#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
void generatePermutations() {
    string word;
    cin >> word;
    sort(word.begin(), word.end());
    do {
        cout << word << endl;
    } while (next_permutation(word.begin(), word.end()));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int num_words;
    cin >> num_words;
    for (int i = 0; i < num_words; ++i) {
        generatePermutations();
    }
    return 0;
}
