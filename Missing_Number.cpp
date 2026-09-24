#include<bits/stdc++.h>
using namespace std;

bool canPartition(int idx, const string& s, unordered_set<int>& required, int max_len) {
    if (idx == s.length()) {
        return required.empty();
    }
    
    // Numbers from 1 to N don't have leading zeros
    if (s[idx] == '0') return false; 

    int num = 0;
    // Try extracting numbers of different lengths (1 digit, 2 digits, etc.)
    for (int i = idx; i < s.length() && (i - idx + 1) <= max_len; ++i) {
        num = num * 10 + (s[i] - '0');
        
        if (required.count(num)) {
            required.erase(num); // "Use" this number
            
            if (canPartition(i + 1, s, required, max_len)) {
                return true;
            }
            
            required.insert(num); // Backtrack
        }
    }
    return false;
}
int findMissingNumber(int n, string s) {
    // Count expected vs. actual digit frequencies
    vector<int> counts(10, 0);
    
    // Count what we SHOULD have
    for (int i = 1; i <= n; ++i) {
        int temp = i;
        while (temp > 0) {
            counts[temp % 10]++;
            temp /= 10;
        }
    }

    // Subtract what we ACTUALLY have
    for (char c : s) {
        counts[c - '0']--;
    }

    // Collect the exact missing digits
    vector<int> missing_digits;
    for (int i = 0; i < 10; ++i) {
        while (counts[i] > 0) {
            missing_digits.push_back(i);
            counts[i]--;
        }
    }

    // Generate all valid permutations of the missing digits
    vector<int> candidates;
    sort(missing_digits.begin(), missing_digits.end());
    
    do {
        if (missing_digits[0] == 0) continue; // No leading zeros
        
        int num = 0;
        for (int d : missing_digits) {
            num = num * 10 + d;
        }
        // Candidate must be within the valid range
        if (num > 0 && num <= n) {
            candidates.push_back(num);
        }
    } while (next_permutation(missing_digits.begin(), missing_digits.end()));

    // Remove duplicates
    candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());

    // Optimization, Bypasses DFS for single candidates
    if (candidates.size() == 1) {
        return candidates[0]; 
    }

    // If multiple candidates exist, verify with DFS
    int max_len = to_string(n).length();
    for (int cand : candidates) {
        unordered_set<int> required;
        for (int i = 1; i <= n; ++i) {
            if (i != cand) required.insert(i);
        }

        // If the string cleanly parses using this candidate as the missing one, we found it
        if (canPartition(0, s, required, max_len)) {
            return cand;
        }
    }

    return -1; 
}

int main() { 
    int n;
    string s;
    cin>>n>>s;
    cout << findMissingNumber(n, s) << "\n";
    return 0;
}