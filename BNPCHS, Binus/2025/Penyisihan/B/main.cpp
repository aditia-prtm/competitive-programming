#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long
#define all(x) x.begin(), x.end()
#define lb lower_bound

int n, l[100005], r[100005], m, a[100005], b[100005], k;
map<int, int>mp;
signed main(){
    cin >> n;
    for(int i=1; i<=n; i++) cin >> l[i];
    for(int i=1; i<=n; i++) cin >> r[i];
    cin >> m;
    for(int i=1; i<=m; i++) cin >> a[i];
    for(int i=1; i<=m; i++){
        cin >> b[i];
        mp[r[b[i]]]++;
    }
    cin >> k;

    int ans = 0;
    for(int i=1; i<=m; i++){
        int target = k-l[a[i]];
        ans += mp[target];
    }
    cout << ans;
}