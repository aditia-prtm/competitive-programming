#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, m, k, a[100005], b[100005], cc = 0, minimum;
vector<int>adj[100005], p;
bool vis[100005] = {0};

void dfs(int x){
    vis[x] = 1;
  //  cout << x << ' ';
    minimum = min(minimum, a[x]);
    for(auto i : adj[x]){
        if(!vis[i]) dfs(i);
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= m; i++) cin >> b[i];
    while(k--){
        int u, v; cin >> u >> v;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            minimum = a[i]; dfs(i);
            p.push_back(minimum);
           // cout << " -> " << minimum << ' ' << endl;
        }
    }
    sort(p.begin(), p.end());
    sort(b + 1, b + m + 1);
    if(m < p.size()) cout << -1;
    else{
        long long ans = 0;
        int idx = p.size();
        for(auto i : p){
            ans += (i * b[idx]); 
          //  cout << i << ' ' << b[idx] << endl;
            idx--;
        }
        cout << ans;
    }
}
