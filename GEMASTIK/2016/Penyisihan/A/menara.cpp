#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define F first 
#define S second 
const int MOD = 1e9+7, N = 3e5+5, MAXN = 1e6;

signed main(){
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        int x = 0, y = 0;
        while(n--){
            int a, b, c; cin >> a >> b >> c;
            int mn = min(a, min(b, c)), mx = max(a, max(b, c));
            x += mn; y += mx;
        }
        cout << x << ' ' << y << endl;
    }
    
}