#include<bits/stdc++.h>
using namespace std; 
#define int long long 
#define pb push_back 

int32_t main(){
    int n; cin >> n; 
    vector<int>a; 
    for(int i = 1; i <= n; i++){
        int z; cin >> z; 
        a.pb(z);
    }
    sort(a.begin(), a.end()); 
    int mx = -1e18;
    for(int i = 1; i < n; i++) mx = max(mx, a[i]-a[i-1]);
    
    cout << mx << ' ' << a.back()-a[0];
}