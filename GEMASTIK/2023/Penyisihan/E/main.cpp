#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

int n;
vector<int>v;
map<int, bool>ada;
signed main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        int x; cin >> x;
        if(!ada[x]) v.pb(x);
        ada[x] = 1;
    }
    sort(all(v));
    int start = v[0];
    for(int i=1; i<v.size(); i++){
        if(v[i] - v[i-1] > 1){
            if(v[i-1] == start) cout << start;
            else cout << start << "-" << v[i-1];
            cout << ",";
            start = v[i];
        }
    }
    if(v.back() == start) cout << start;
    else cout << start  << "-" << v.back();
}
/*
1 2 5 8 9 10
*/