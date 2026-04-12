#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define F first 
#define S second 
const int MOD = 1e9+7, N = 3e5+5, MAXN = 1e6;

int n, m;
pair<int, int> ans[200005];
signed main(){
  cin >> n >> m >> ans[0].F >> ans[0].S;

  for(int i=1; i<=n; i++){
    int a, b; cin >> a >> b;
    ans[i].F = ans[i-1].F + a;
    ans[i].S = ans[i-1].S + b;
  }

  for(int i=1; i<=m; i++){
    int k; cin >> k;
    cout << ans[k].F << ' ' << ans[k].S << endl;
  }
}