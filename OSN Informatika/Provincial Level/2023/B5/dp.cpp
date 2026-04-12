#include<bits/stdc++.h>
using namespace std;
#define ll long long 

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")


int n, m, a[105];    // tolol buta map
ll dp[105][100005], mod = 1000000000;
vector<int>adj[105];
bool vis[105];

void dfs(int x, int bef, int k){
    vis[x] = true;
    dp[x][k] += dp[bef][k];
    dp[x][k] %= mod;
    
    if(a[x] == k){
        dp[x][k]++; dp[n + 1][k] ++;
     }else if(a[x] < k){
        dp[x][k] += dp[bef][k - a[x]];
        dp[n + 1][k] += dp[bef][k - a[x]];
    }
    dp[x][k] %= mod;
    dp[n + 1][k] %= mod;
    for(auto i : adj[x]){
        if(!vis[i]) dfs(i, x, k);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    for(int i = 1; i <= m; i++){
        memset(vis, 0, sizeof(vis));
        dfs(1, 0, i);
        dp[n + 1][i] += dp[n + 1][i - 1];
        cout << /*i << " -> " << */dp[n + 1][i] % mod << endl;
    }
 /*   cout << "  "; for(int i = 1; i <= m; i++) cout << i << ' ';
    cout << endl;
    for(int i = 1; i <= n; i++){
        cout << i << ' ';
        for(int j = 1; j <= m; j++) cout << dp[i][j] << ' ';
        cout << endl;
    }*/
}
/*
7 5 
1 2 3 4 5 1 2 
1 2 
1 3 
2 4 
2 5 
3 6 
3 7

15 15 
1 2 3 4 5 1 2 3 4 5 1 2 3 4 5 
1 2 
1 3 
2 4 
2 5 
3 6 
3 7 
4 8 
4 9 
5 10 
5 11
6 12 
6 13 
7 14
7 15
*/