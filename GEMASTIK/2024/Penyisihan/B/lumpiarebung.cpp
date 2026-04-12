#include <bits/stdc++.h> 
using namespace std;
#define int long long
#define pb push_back 

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n,l; cin >> n >> l;
    vector<int>v;
    v.pb(l);
    while(n--){
        int b; cin >> b; b--;
        v[b] /= 2;
        v.insert(v.begin()+b+1, v[b]);
    }

    for(auto i : v){
        if(i>0) cout << i << ' ';
    }
}