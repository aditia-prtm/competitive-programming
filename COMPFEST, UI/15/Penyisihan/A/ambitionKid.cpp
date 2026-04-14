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

int32_t main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    int n, ans = 1e18; cin >> n;
    for(int i = 1; i <= n; i++){
        int a; cin >> a; ans = min(ans, abs(a));
    }
    cout << ans;
}
