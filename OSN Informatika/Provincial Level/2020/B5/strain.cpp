#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define F first
#define S second 

int n, s, p, a[1000005];
pair<string, int>v [15];
ll ans = 0;
string ss = "";
vector<int>adj[1000005];
bool vis[1000005];

void dfs(int x, ll k, string jenis){
//    cout << x << " -> " << k + a[x] << endl;
    vis[x] = true;
    bool gd = 1;
    for(auto i : adj[x]){
        if(!vis[i]){
            gd = 0;
            dfs(i, k + a[x], jenis);
        }
    }
    if(gd && k + a[x] > ans){
        ans = a[x] + k;
        ss = jenis;
    }
}

int main(){
    cin >> n >> s >> p;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= p; i++) cin >> v[i].F >> v[i].S;
    for(int i = 1; i <= n - p; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b); adj[b].push_back(a);
    }
    for(int i = 1; i <= p; i++) dfs(v[i].S, 0, v[i].F);
    cout << ss << endl << ans;
}
/*
8 2 4
1
3
5
1
4
1
3
4
A 1
A 2
B 3
B 4
1 5
3 6
4 7
4 8

*/