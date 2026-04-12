#include<bits/stdc++.h>
using namespace std;
#define int long long 

vector<int>v;
int n, u;
signed main(){
    cin >> n >> u;

    int x;
    while(cin >> x){
        v.push_back(x);
    }

    if(v.size() != n){
        cout << "Jumlah harga buah (" << v.size() << ") tidak sesuai dengan jumlah jenis buah ("<< n << ").";
        return 0;
    }

    sort(v.begin(), v.end());

    int ans = 0;
    for(int i = 0; i < n; i++){
        if(u - v[i] >= 0){
            ans++;
            u -= v[i];
        }else break;
    }
    cout << ans;
}