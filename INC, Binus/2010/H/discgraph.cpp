#include<bits/stdc++.h>
using namespace std; 
#define int long long 
#define pub push_back
#define mems(a) memset(a, 0, sizeof(a))

int n, e, q, r, edgeU[200069], edgeV[200069], cz;
vector<int> adj[50069], cc;
bool spec[200069], vis[50069], rem[200069];

void dfs(int node){
    vis[node] = 1;
    if(spec[node]){
    //    cout << "-> " << node << endl;
        cz++;
    }
    for(auto i : adj[node]){
        if(!vis[i]) dfs(i);
    }
}

signed main(){
    int t; 
    cin >> t;
    while(t--){
        cin >> n >> e >> q >> r;
        
        mems(vis); mems(rem); mems(spec); cc.clear();
        for(int i = 1; i <= n; i++) adj[i].clear();
        
        for(int i = 1; i <= e; i++){
            cin >> edgeU[i] >> edgeV[i];
        }
        while(q--){
            int special; 
            cin >> special;
            spec[special] = 1;
        }
        while(r--){
            int hps;
            cin >> hps;
            rem[hps] = 1;
        }
        for(int i = 1; i <= e; i++){
            int u = edgeU[i], v = edgeV[i];
            if(!rem[i]){
                adj[u].pub(v); 
                adj[v].pub(u);
            //    cout << u << ' ' << v << endl;
            }
        }
        
        for(int i = 1; i <= n; i++){
            if(!vis[i]){
                cz = 0;
                dfs(i); 
                if(cz > 0) cc.pub(cz);
            }
        }
        int ans = 0, sum = 0;
        for(auto i : cc){
            ans += (i*sum);
            sum += i;
        }
        cout << ans << endl;
    }
}