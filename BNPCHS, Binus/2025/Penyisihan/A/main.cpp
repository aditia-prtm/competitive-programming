#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define lb lower_bound

int n, ans;
double mn = 1000000007;
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++){
        double d, v;
        cin >> v >> d;
        // cout << i << ": " << d/v << endl;
        if(d/v < mn){
            mn = d/v;
            ans = i;
        } 
    }
    cout << ans;
}