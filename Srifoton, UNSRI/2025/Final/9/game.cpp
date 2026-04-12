#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long
#define all(x) x.begin(), x.end()
#define lb lower_bound

char combine(char a, char b){
    if(a == b) return a;
    if((a == 'K' && b == 'V') || (a == 'V' && b == 'K')) return 'Z';
    if((a == 'V' && b == 'Z') || (a == 'Z' && b == 'V')) return 'K';
    return 'V';
}

signed main(){
    string s; cin >> s;
    while(s.size() > 1){
        string t;
        for(int i=0;i+1<s.size();i++) t += combine(s[i], s[i+1]);
        s = t;
    }
    cout << s[0];
}
