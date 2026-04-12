#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define F first 
#define S second 
const int MOD = 1e9+7, N = 3e5+5, MAXN = 1e6;

int n, sd, sm, p[N], k[N], l[N], ans;
priority_queue<int>pq;

signed main(){
    string dummy; cin >> dummy;
    cin >> n >> sd >> sm;
    p[n] = sm;
    for(int i=1; i<=n; i++){
        // cout << i << ": " << sd << " " << ans << endl;
        if(i<n) cin >> p[i] >> k[i] >> l[i];    


        while(!pq.empty() && sd < p[i]){
            sd++;
            ans -= pq.top();
            pq.pop();
        }
        if(sd < p[i]){
            cout << -1;
            return 0;
        }
        if(i==n){
            cout << ans;
            return 0;
        }
        if(l[i] <= k[i]){
            sd++;
            ans += l[i];
        }else{
            pq.push(k[i] - l[i]);
            ans += k[i];
        }
    }
}