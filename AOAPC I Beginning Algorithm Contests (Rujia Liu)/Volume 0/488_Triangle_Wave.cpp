#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
 
const string a[] = {"", "1", "22", "333", "4444", "55555", "666666", "7777777", "88888888", "999999999"};
 
int main(){
    register unsigned n, i, j, k;
    string output, total = "";
    scanf("%u", &n);
 
    while(n--){
        unsigned amp, times;
        scanf("%u%u", &amp, &times);
        output = "";
 
        while(times--){
            for(i = 1; i < amp; ++i)
                output += a[i] + "\n";
            for(k = i; k; --k)
                output += a[k] + "\n";
            if(times || n)
                output += "\n";
        }
        total += output;
    }
 
    cout << total;
    return 0;
}
