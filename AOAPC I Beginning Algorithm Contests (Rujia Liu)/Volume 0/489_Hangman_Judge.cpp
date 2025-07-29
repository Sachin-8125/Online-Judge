#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int roundNum;
    while ( (cin >> roundNum) && roundNum != -1 ) {
        string solution, guesses;
        cin >> solution >> guesses;

        // Track which letters in solution have been revealed
        vector<bool> revealed(26, false), present(26, false);
        for (char c : solution) {
            present[c - 'a'] = true;
        }

        int strokes = 0;
        int lettersLeft = 0;
        for (int i = 0; i < 26; ++i) {
            if (present[i]) lettersLeft++;
        }

        vector<bool> guessed(26, false);
        bool won = false, lost = false;

        for (char g : guesses) {
            int idx = g - 'a';
            if (guessed[idx]) {
                // already guessed this letter; skip
                continue;
            }
            guessed[idx] = true;

            if (present[idx]) {
                // reveal all occurrences
                revealed[idx] = true;
                lettersLeft--;
                if (lettersLeft == 0) {
                    won = true;
                    break;
                }
            } else {
                // wrong guess
                strokes++;
                if (strokes == 7) {
                    lost = true;
                    break;
                }
            }
        }

        cout << "Round " << roundNum << "\n";
        if (won) {
            cout << "You win.\n";
        } else if (lost) {
            cout << "You lose.\n";
        } else {
            cout << "You chickened out.\n";
        }
    }

    return 0;
}
