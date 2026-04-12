#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long
#define all(x) x.begin(), x.end()
#define lb lower_bound

int a, b, ans;
signed main(){
    cin >> a >> b;
    for(int i=a; i<=b; i++){
        if(i%2 == 1) ans += i;
    }
    cout << ans;
}