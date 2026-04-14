#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define pii pair<int, int>
#define all(v) v.begin(), v.end() 
#define F first
#define S second 
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

const int MOD = 998244353, maxn = 1e5+5;
int n, m, a[maxn], c[maxn];
map<int, int>mp;
int binpow(int x, int y){
    if(y == 0) return 1; 
    int tmp = binpow(x, y/2);
    int z = (tmp*tmp)%MOD;
    if(y&1) z = (z*x)%MOD;
    return z;
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i]; 
    for(int i = 1; i <= n; i++){
        int b; cin >> b; mp[a[i]] = b; 
    } 
    cin >> m;
    for(int i = 1; i <= m; i++) cin >> c[i]; 
    for(int i = 1; i <= m; i++){
        int d; cin >> d; 
        if(mp[c[i]] == d) n--;
        else if(mp[c[i]] < d){
            cout << 0; return 0;
        }
    }
    cout << binpow(2, n);
}
