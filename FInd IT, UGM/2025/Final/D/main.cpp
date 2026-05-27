#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 1e3+5;

int n, m, c[MAXN], h[MAXN], k[MAXN];
signed main(){
    cin >> n >> m;

    int ans = 0;
    for(int i = 1; i <= m; i++){
        cin >> c[i] >> h[i] >> k[i];
        k[i] *= n;

        int buy = k[i] / c[i];
        if(k[i] % c[i] != 0) buy++;
        ans += (buy * h[i]);
    }

    cout << ans;
}