#include<bits/stdc++.h>
using namespace std;
#define int short

int n, a[15], ans;
signed main(){
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=n; i++){
        int b; cin >> b;
        ans += min(b, a[i]);
    }
    cout << ans;
}