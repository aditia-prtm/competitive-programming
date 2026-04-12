#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define F first 
#define S second 
const int MOD = 1e9+7, N = 3e5+5, MAXN = 1e6;

map<string, string>mp;
signed main(){
    mp["AA"] = "BB";
    mp["AB"] = "BD";
    mp["AC"] = "DD";
    mp["AD"] = "CA";
    mp["BA"] = "CD";
    mp["BB"] = "AA";
    mp["BC"] = "AC";
    mp["BD"] = "BC";
    mp["CA"] = "AB";
    mp["CB"] = "CC";
    mp["CC"] = "DB";
    mp["CD"] = "CB";
    mp["DA"] = "BA";
    mp["DB"] = "DC";
    mp["DC"] = "AD";
    mp["DD"] = "DA";

    string s; cin >> s;
    for(int i=0; i<s.length()-1; i+=2){
        string j = "";
        j += s[i];
        j += s[i+1];
        cout << mp[j];
    }
} 
