#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll 
#define pb push_back
#define pii pair<int, int>
#define all(v) v.begin(), v.end() 
#define lb lower_bound
#define F first
#define S second 

const int maxn = 3e4+5;
vector<pii>adj[maxn];
int n, m, dis[maxn];
bool vis[maxn] = {0};

void dfs(int x){
    if(x == n){
        cout << abs(dis[n]); exit(0);
    }
    for(int i = 0; i < adj[x].size(); i++){
        if(!vis[adj[x][i].F]){
            dis[adj[x][i].F] = dis[x] + adj[x][i].S;
            vis[adj[x][i].F] = 1;
            dfs(adj[x][i].F);
        }
    }
}

int32_t main(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v, z; cin >> u >> v >> z;
        adj[u].pb({v, z}); adj[v].pb({u, -z});
    }
    vis[1] = 1;
    dfs(1);
    cout << -1;
}