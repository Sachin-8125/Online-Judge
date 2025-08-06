#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int n;

void backtrack(int idx, const string& str)
{
    if (idx == n) {
        cout << string(idx * 2, ' ') << "writeln(";
        for (int i = 0; i < idx-1; ++i)
            cout << str[i] << ',';
        cout << str[idx-1] << ")\n";
        return;
    }

    string tmpStr;

    for (int i = idx-1; i >= 0; --i) {
        cout << string(idx * 2, ' ');
        if (i != idx-1) cout << "else ";
        cout << "if " << str[i] << " < " << char('a' + idx) << " then\n";

        tmpStr = str;
        if (i+1 > idx-1)
            tmpStr.push_back(char('a' + idx));
        else
            tmpStr.insert(i+1, 1, char('a' + idx));

        backtrack(idx + 1, tmpStr);
    }

    cout << string(idx * 2, ' ') << "else\n";
    backtrack(idx+1, char('a'+idx) + str);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n;

        cout << "program sort(input,output);\nvar\n";

        for (int i = 0; i < n-1; ++i)
            cout << static_cast<char>('a'+i) << ',';
        cout << static_cast<char>('a'+n-1) << " : integer;\nbegin\n  readln(";

        for (int i = 0; i < n-1; ++i)
            cout << static_cast<char>('a'+i) << ',';
        cout << static_cast<char>('a'+n-1) << ");\n";

        backtrack(1, "a");

        cout << "end.\n";

        if (tc)
            cout << '\n';
    }

    return 0;
}
