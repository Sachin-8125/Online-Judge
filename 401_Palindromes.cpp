#include <iostream>
#include <string>
#include <map>

using namespace std;

// Define the mirrored characters
char mirror(char c) {
    string from = "AEHIJLMOSTUVWXYZ12358";
    string to   = "A3HILJMO2TUVWXY51SEZ8";
    for (size_t i = 0; i < from.size(); ++i)
        if (c == from[i])
            return to[i];
    return 0;
}

int main() {
    string s;
    while (cin >> s) {
        bool is_palindrome = true, is_mirrored = true;
        int len = s.size();

        for (int i = 0; i < (len+1)/2; ++i) {
            // Palindrome: check symmetrical characters
            if (s[i] != s[len-1-i])
                is_palindrome = false;
            // Mirrored: check mirrored letter correspondence
            if (mirror(s[i]) != s[len-1-i])
                is_mirrored = false;
        }

        cout << s << " -- ";
        if (is_palindrome && is_mirrored)
            cout << "is a mirrored palindrome." << endl;
        else if (is_palindrome)
            cout << "is a regular palindrome." << endl;
        else if (is_mirrored)
            cout << "is a mirrored string." << endl;
        else
            cout << "is not a palindrome." << endl;
        cout << endl;
    }
    return 0;
}
