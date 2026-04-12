#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, m, k, a[100005];
int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    int ans = 0; m += k;
    for(int i = 1; i <= n; i++){
        if(a[i] <= m) continue;
        else{
          //  cout << a[i] << ' ' << m << ' ' << ans+1 << endl;
            ans++; m = a[i] + k;
        }
    }
    cout << ans;
}
/*
N  M  K
10 37 11
41 61 72 78 83 98 107 140 152 183
52 72 -  89 - 109  -  151 163 194 

*/