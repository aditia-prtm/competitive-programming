#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long
#define all(x) x.begin(), x.end()
#define lb lower_bound

int n;
vector<int>A;
signed main() {
    cin >> n;
    for(int i=1; i<=n; i++){
        int x; cin >> x;
        A.pb(x);
    }

    vector<int> basis;

    for (int x : A) {
        for (int b : basis) {
            x = min(x, x ^ b);
        }
        if (x > 0) basis.pb(x);
    }

    int rank = (int)basis.size();
    int ans = 1LL << rank;
    cout << ans;

    return 0;
}
