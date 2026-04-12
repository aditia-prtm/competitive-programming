#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define F first
#define S second 

string s; 
map<string, bool>mp;

string kecil(string tmp){
    string ans = "";
    for(auto i : tmp){
        if(i  > 90){
            i -= 32;
        }
        ans += i;
    }
    // cout << ans << ' ';
    return ans;
}

signed main(){
    getline(cin, s);
    string tmp = "";
    for(auto i : s){
        if(i==' '){
            string z = kecil(tmp);
            if(!mp[z]) cout << tmp << ' ';
            mp[z] = 1;
            tmp = "";
        }else tmp += i;
    }
    string z = kecil(tmp);
    if(!mp[z]) cout << tmp << ' ';
}