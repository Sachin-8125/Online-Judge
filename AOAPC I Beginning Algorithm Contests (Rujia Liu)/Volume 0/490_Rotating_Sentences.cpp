#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<string> lines;
    string line;

    // Read all input lines
    while (getline(cin, line))
        lines.push_back(line);

    int rows = lines.size();
    int cols = 0;
    for (const string& l : lines)
        cols = max(cols, (int)l.size());

    // Print characters column-wise from right to left
    for (int col = 0; col < cols; ++col) {
        for (int row = rows - 1; row >= 0; --row) {
            if (col < (int)lines[row].size())
                cout << lines[row][col];
            else
                cout << ' ';
        }
        cout << '\n';
    }

    return 0;
}
