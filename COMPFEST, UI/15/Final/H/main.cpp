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
    cout.tie(0); cout.tie(0);
    int t = 1; 
    cin >> t; 
    while(t--){
        int n, P; cin >> n >> P;
        pii p[n+5]; 
        for(int i = 1; i <= n; i++) cin >> p[i].S; 
        for(int i = 1; i <= n; i++) cin >> p[i].F; 
        sort(p+1, p+1+n); 
        int idx = 1, ans = P;
        for(int i = 2; i <= n; i++){
            if(p[idx].S == 0) idx++; 
            if(p[idx].F < P){
                ans += p[idx].F; p[idx].S --;
            }else ans += P;
        }
        cout << ans << endl;
    }
}