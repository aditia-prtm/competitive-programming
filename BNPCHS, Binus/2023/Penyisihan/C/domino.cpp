#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back

int n, q, pref[100005] = {0}, a[100005];
vector<int>k;
int left[100005], right[100005];
int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> a[i]; pref[i] = pref[i - 1];
        if(a[i] == -1) k.pb(i);
        else pref[i] += a[i];
    }
    
    while(q--){
        int l, r; cin >> l >> r;
        int lx = l, ly, rx, ry = r;
        ly = lower_bound(k.begin(), k.end(), l) - k.begin(); ly = k[ly];
        rx = (lower_bound(k.begin(), k.end(), r + 1) - k.begin())-1; rx = k[rx];
        if(rx <= ly) cout << pref[r] - pref[l - 1] << endl;
        else cout << pref[r] - pref[rx] + pref[ly] - pref[l - 1] << endl;
    }
    
}