#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    unsigned n;
    cin >> n;
    
    while (n--) {
        unsigned a, b;
        cin >> a >> b;
        
        // Create vector of strings
        vector<string> s(a);
        for (unsigned i = 0; i < a; ++i) {
            cin >> s[i];
        }
        
        // Consensus string
        string conseq;
        conseq.reserve(b);
        
        unsigned error = 0;
        
        for (unsigned i = 0; i < b; ++i) {
            // Count array for A, C, G, T
            vector<unsigned> seq(4, 0);
            
            for (unsigned j = 0; j < a; ++j) {
                switch (s[j][i]) {
                    case 'A':
                        ++seq[0];
                        break;
                    case 'C':
                        ++seq[1];
                        break;
                    case 'G':
                        ++seq[2];
                        break;
                    case 'T':
                        ++seq[3];
                        break;
                }
            }
            
            // Find the nucleotide with maximum count
            unsigned maxIndex = max_element(seq.begin(), seq.end()) - seq.begin();
            
            // Add to consensus string
            char nucleotides[] = {'A', 'C', 'G', 'T'};
            conseq += nucleotides[maxIndex];
            
            // Calculate errors for this position
            for (unsigned j = 0; j < a; ++j) {
                if (s[j][i] != nucleotides[maxIndex]) {
                    ++error;
                }
            }
        }
        
        cout << conseq << '\n' << error << '\n';
    }
    
    return 0;
}


