#include<bits/stdc++.h>
using namespace std;
#define int long long 

string s; 
map<char, bool>ada;
signed main(){
    cin >> s;
    // getline(cin, s);

    for(auto i : s){
        if(!ada[i]){
            ada[i] = 1;
            cout << i;  
        }
    }
    
}