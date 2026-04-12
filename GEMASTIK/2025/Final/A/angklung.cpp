#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define F first 
#define S second 
const int MOD = 1e9+7, N = 3e5+5, MAXN = 1e6;

int n, t, k;
signed main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);

    cin >> n >> t >> k;
    if(t <= k){
        cout << n;
        return 0;
    }

    int ans = 0;
    for(int i=1; i<=n; i++){
        int f = 0;
        for(int j=1; j*j <= i; j++){ 
            if(i%j == 0){
                if(j <= t) f++;
                int jj = i/j;
                if(j!=jj && jj <= t) f++;
            }
        }
        int sf = max((int)0, t/i - 1);
        if(f+sf <= k) ans++;
    }
    cout << ans;
}