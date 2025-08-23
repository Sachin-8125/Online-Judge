#include<iostream>
using namespace std;
bool isSubsequence(string s1,string s2){
    int i=0,j=0;
    while(i<s1.length() && j<s2.length()){
        if(s1[i]==s2[j]) i++;
        j++;
    }
    return i==s1.length();
}
int main(){
    string s,t;
    while(cin>>s>>t){
        if(isSubsequence(s,t)) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;

    }
}