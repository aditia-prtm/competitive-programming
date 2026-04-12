#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define F first
#define S second 

int n, a[100005] = {0}, ans = 0, mod = 1000000007;
int32_t main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        ans += ((i * (i + 1))/ 2) * (n - i + 1) * x;
        ans %= mod;
    }
    cout << ans;
}