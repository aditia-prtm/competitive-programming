#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

int n, a[100005], b[100005], ccsz, ans[100005], sum;
vector<int>adj[100005], cc[100005];
bool vis[100005];

void dfs(int node){
    vis[node] = 1;
    sum += b[node];
    cc[ccsz].pb(node);
    for(auto i:adj[node]){
        if(!vis[i]) dfs(i);
    }
}

int pkt(int p, int q){
    if(q==0) return 1;
    if(q==1) return p;
    int x = pkt(p,q/2);
    int y = x;
    if(q%2 == 1) y*=p;
    return x*y;
}
signed main(){
    cin >> n;
    bool same = 1, dpkt = 1;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        if(i > 1 && a[i] != a[i-1]) same = 0;
        int x = log2(a[i]);
        if(pkt(2, x) != a[i]) dpkt = 0;
    }
    for(int i=1; i<=n; i++) cin >> b[i];

    // cout << "=======" << endl;
    if(same){
        for(int i=1; i<=n; i++) cout << b[i] << endl;
        return 0;
    }

    if(dpkt){
        int jml = 0;
        for(int i=1; i<=n; i++) jml += b[i];
        for(int i=1; i<=n; i++) cout << jml << endl;
        return 0;
    }
    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            if((a[i]^a[j]) > max(a[i], a[j])){
                // bisa pindah i,j
                adj[i].pb(j);
                adj[j].pb(i);
            }
        }
    }
    for(int i=1; i<=n; i++){
        if(vis[i]) continue;
        ccsz++; sum = 0;
        dfs(i);
        for(auto j:cc[ccsz]) ans[j] = sum;
    }
    for(int i=1; i<=n; i++) cout << ans[i] << endl;
}