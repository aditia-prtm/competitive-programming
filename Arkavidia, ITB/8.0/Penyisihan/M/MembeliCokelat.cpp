#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, x;
int biaya[100010];
bool vis[100010] = {0};
vector<int>adj[100010];

void dfs(int x, int c){
    vis[x] = 1; biaya[x] = c;
    for(int i = 0; i < adj[x].size(); i++){
        if(!vis[adj[x][i]]){
            dfs(adj[x][i], min(biaya[adj[x][i]], c));
        }
    }
}

signed main(){
    cin >> n >> x;
    for(int i = 1; i <= n; i++) cin >> biaya[i];
    
    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    dfs(x, biaya[x]);
    for(int i = 1; i <= n; i++) cout << biaya[i] << ' ';
}