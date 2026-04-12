#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long
#define all(x) x.begin(), x.end()
#define lb lower_bound

struct Edge{
    int to, cost;
};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    int sx, sy, tx, ty; cin >> sx >> sy >> tx >> ty;
    sx--, sy--, tx--, ty--;

    int total = n * n;
    auto id = [&](int x, int y){ return x * n + y; };

    vector<vector<Edge>> g(total);

    int dx[8] = {1,2,2,1,-1,-2,-2,-1};
    int dy[8] = {2,1,-1,-2,-2,-1,1,2};
    for(int i=0;i<n;i++) for(int j=0;j<n;j++){
        int u = id(i,j);
        for(int k=0;k<8;k++){
            int ni=i+dx[k], nj=j+dy[k];
            if(ni>=0 && nj>=0 && ni<n && nj<n){
                g[u].push_back({id(ni,nj),1});
            }
        }
    }

    for(int i=0;i<m;i++){
        int px,py,qx,qy,c; cin >> px >> py >> qx >> qy >> c;
        px--,py--,qx--,qy--;
        g[id(px, py)].push_back({id(qx, qy), c});
    }

    vector<int> dist(total, 1e18);
    dist[id(sx,sy)] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push(make_pair(0,id(sx,sy)));

    while(!pq.empty()){
        pair<int,int> cur = pq.top(); pq.pop();
        int d = cur.first, u = cur.second;
        if(d != dist[u]) continue;
        for(size_t i=0;i<g[u].size();i++){
            int v = g[u][i].to;
            int w = g[u][i].cost;
            if(dist[v] > d + w){
                dist[v] = d + w;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    int ans = dist[id(tx,ty)];
    if(ans >= 1e18) cout << -1;
    else cout << ans;
}
    