#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        double total = 0.0;
        vector<double> expenses(n);
        
        for (int i = 0; i < n; i++) {
            cin >> expenses[i];
        }
        
        // Calculate total and average
        for (int i = 0; i < n; i++) {
            total += expenses[i];
        }
        
        double average = total / n;
        
        // Calculate total money to be exchanged
        double exchange = 0.0;
        for (int i = 0; i < n; i++) {
            if (expenses[i] > average) {
                exchange += expenses[i] - average;
            }
        }
        
        // Output with proper formatting
        cout << fixed << setprecision(2) << "$" << exchange << endl;
    }
    
    return 0;
}
