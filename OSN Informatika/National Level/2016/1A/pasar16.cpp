#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
int n, m, g[50][50];
vector<int>tmp;
bool vis[50][50];
int X[4] = {0, 0, 1, -1};
int Y[4] = {1, -1, 0, 0};

void dfs(int x, int y, int val){
    vis[x][y] = true;
    if(x == n && y == m) tmp.pb(val);
    else{
        for(int i = 0; i < 4; i++){
            if(!vis[x + X[i]][y + Y[i]]) dfs(x + X[i], y + Y[i], val + g[x + X[i]][y + Y[i]]);
        }
    }
    vis[x][y] = false;
}
int32_t main(){
    ios_base :: sync_with_stdio (0); cin.tie (0); cout.tie (0);
    memset(vis, true, sizeof(vis));
    string s; cin >> s;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> g[i][j]; vis[i][j] = false;
        }
    }
    dfs(1, 1, g[1][1]); sort(all(tmp));
    int k; cin >> k;
    while(k--){
        int p, q; cin >> p >> q;
        int res1 = lb(all(tmp), q + 1) - tmp.begin();
        int res2 = lb(all(tmp), p) - tmp.begin();
        cout << res1 - res2 << endl;
    }
    
}
/*
2 3
1 2 3
4 5 6 


*/