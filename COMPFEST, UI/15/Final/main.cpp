#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll 
#define pb push_back
#define pii pair<int, int>
#define all(v) v.begin(), v.end() 
#define lb lower_bound
#define F first
#define S second 

const int maxn = 1e5+10, MOD = 998244353;
int n, a[maxn], b[maxn] = {0};

int32_t main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++){
        b[i] = a[i];
        for (int j = 2 * i; j <= n; j += i) b[i] = max(b[i], a[j]);
    }
    sort(b + 1, b + n + 1);
    int ans = 0, k = 1;
    for(int i = 1; i <= n; i++){
        ans = (ans + k*b[i]%MOD)%MOD;
        k = (2*k)%MOD;
    }
    cout << ans;
}