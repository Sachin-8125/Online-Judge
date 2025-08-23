#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Song {
    int id;
    int length;
    double freq;
};

bool compare(const Song& a, const Song& b) {
    // Sort by freq/length in descending order (highest first)
    double ra = a.freq / a.length;
    double rb = b.freq / b.length;
    
    return ra > rb;
}

int main() {
    int N;
    while (cin >> N) {
        vector<Song> songs(N);
        for (int i = 0; i < N; ++i) {
            cin >> songs[i].id >> songs[i].length >> songs[i].freq;
        }
        int S;
        cin >> S;

        sort(songs.begin(), songs.end(), compare);

        // Output the identifier of the S-th song (1-based)
        cout << songs[S-1].id << endl;
    }
    return 0;
}
