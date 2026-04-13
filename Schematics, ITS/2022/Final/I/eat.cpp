#include<bits/stdc++.h>
using namespace std;
#define F first 
#define S second 

int n, e, d, dis[1005] = {0}, ans = 1e9+7;
pair<int, string>p[1005];
vector<pair<int, int>>adj[1005];
string s;

void dfs(int x){
    if(p[x].F < ans && x != 0){
        ans = p[x].F; s = p[x].S;
        //cout << ans << ' ' << s << endl;
    }
    for(auto i : adj[x]){
        if(dis[x] + i.S < dis[i.F] && dis[x] + i.S <= d){
            dis[i.F] = dis[x] + i.S;
            dfs(i.F);
        }
    }
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> p[i].S >> p[i].F;
        dis[i] = 1e9+7;
    }
    cin >> e;
    while(e--){
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    cin >> d;
    dfs(0);
    cout << "hari ini makan di " << s;
}