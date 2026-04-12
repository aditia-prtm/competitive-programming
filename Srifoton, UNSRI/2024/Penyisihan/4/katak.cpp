#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define F first
#define S second 

int n, target;
map<int, bool>mp;
vector<int>v;

void f(int batu, int k){
    if(batu > target || !mp[batu]){
        return;
    }
    if(batu == target){
        cout << "true";
        exit(0);
    }
    // cout << batu << ' ' << k << endl;
    if(k > 1) f(batu+k-1, k-1);
    f(batu+k, k);
    f(batu+k+1, k+1);
}

signed main(){
    int x;
    while(cin >> x){
        v.pb(x);
        mp[x] = 1;
    }
    target = v.back();
    // if(v[1] != 1){
    //     cout << "false";
    //     return 0;
    // }
    f(1, 1);
    cout << "false";
}