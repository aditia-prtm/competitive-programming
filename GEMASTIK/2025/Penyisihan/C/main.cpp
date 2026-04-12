#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define F first 
#define S second 
const int MOD = 1e9+7, N = 3e5+5, MAXN = 1e5+5;

int n, t, ans[MAXN];
string s;
signed main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    
    cin >> n >> t >> s;

    for(int i=1; i <= n; i++){
        if(s[i-1] == 'L' && i-t > 0) ans[i-t]++;
        else if(s[i-1] == 'R' && i+t <= n) ans[i+t]++;
    }

    for(int i=1; i<=n; i++){
        if(ans[i] == 0) cout << '.';
        else cout << 'X';
    }
}