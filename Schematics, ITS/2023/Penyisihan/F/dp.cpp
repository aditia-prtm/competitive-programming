#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ambatukaam ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

ll dp[105][1000005] = {0};
int main(){
    ambatukaam
    ll n; cin >> n;
    ll ans = -1e18;
    string z;
    for(int i = 1; i <= n; i++){
        string s; cin >> s;
        ll m, tmp = 0; cin >> m;
        for(int j = 1; j <= m; j++){
            ll x; cin >> x;
            dp[i][j] = max(x, dp[i][j - 1] + x);
            tmp = max(tmp, dp[i][j]);
           // cout << dp[i][j] << ' ';
        } //cout << endl;
        if(tmp > ans){
            ans = tmp;
            z = s;
        }
    }
    cout << z;
}
/*
3
Ayam 5 -2 4 1 -1 3
Bebek 4 2 -3 2 1
Cicak 5 -3 6 -6 -1 2

-2 4 1 -1 3 
-2 4 5  4 7   a[i] atau max bef?
----------(cari max)


*/
