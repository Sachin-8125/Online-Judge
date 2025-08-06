//  105 - The Skyline Problem

#include<bits/stdc++.h>
using namespace std;

int main(){
    int height[10001] = {0};
    int left, right, buildingHeight;

    // read our buildings
    while (cin >> left >> buildingHeight >> right){
        for (int i = left; i < right; ++i){
            if (buildingHeight > height[i])
                height[i] = buildingHeight;
        }
    }

    bool notFirst = false; // only show a preceeding space on the non-first entries
    int currentHeight = 0;
    for (int i = 0; i != 10000; ++i){
        if (height[i] != currentHeight){
            if (notFirst) cout << ' ';
            else notFirst = true;
            cout << i << ' ' << height[i];
            currentHeight = height[i];
        }
    }
    cout << endl;
    return 0;

}
