#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9+7;

int main(){
    int t; cin >> t;
    while(t--){
        ll n, x, y; cin >> n >> x >> y;
        ll a = x + y, ans = x + y;
        while(n > 1){
            ans *= a; ans %= mod; n--;
        }
        cout << ans << endl;
    }
}