#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
const int N = 2e5+5;


signed main(){
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        cout << min(n, (int)log2(k) + 1) << endl;
    }
}
