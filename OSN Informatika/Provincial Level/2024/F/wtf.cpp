#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, m, ans = 0;
int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    if(n < m) swap(n, m);
    for(int i = 1; i <= n; i++) ans += i;
    int z = n;
    for(int i = 1; i < m; i++){
        z += 2; ans += z;
    }
    cout << ans;
    // :")
}