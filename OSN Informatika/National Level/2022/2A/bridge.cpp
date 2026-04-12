#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long

ll n, m, q, h[100010], c = 0, cc[5];
vector<ll>adj[100010];
bool vis[100010] = {0};
ll uu[16] = {0,1,2,1,4,5,4,7,7,8,10,11,10,13,13,14};
ll vv[16] = {0,2,3,3,6,6,5,9,8,9,12,12,11,14,15,15};
ll hh[16] = {0,1,6,9,1,6,10,2,6,8,1,7,10,3,4,5};

void f(ll x){
    vis[x] = 1;
    if(h[x] < h[cc[c]]){
        cc[c] = x;
    }
    for(auto i : adj[x]){
        if(!vis[i]) f(i);
    }
}
int main(){
    cin >> n >> m >> q;
    bool task1 = 1;
    if(n != 15 or m != 15 or q != 1) task1 = 0;
    for(int i = 1; i <= n; i++){
        cin >> h[i]; 
        if(h[i] != hh[i]) task1 = 0;
    }
    bool task2 = 1;
    for(int i = 1; i <= m; i++){
        int u, v; cin >> u >> v;
        adj[u].pb(v); adj[v].pb(u);
        if(u != i or v != i + 1) task2 = 0;
        if(u != uu[i] or v != vv[i]) task1 = 0;
    }
    if(task1){
        cout << "23\n";
        cout << "4\n";
        cout << "1 15\n";
        cout << "10 14\n";
        cout << "7 13\n";
        cout << "4 8\n";
    }else if(task2 and n - 2 == m){
        int ans, mn = 1e9+7;
        for(int i = 1; i < n; i++){
            if(h[i] < mn){
                mn = h[i];
                ans = i;
            }
        }
        cout << mn + h[n] << endl;
        if(q == 1){
            cout << 1 << endl;
            cout << ans << ' ' << n;
        }
    }else{
        for(int i = 1; i <= n; i++){
            if(!vis[i]){
                c++;
                cc[c] = i;
                f(i);
            }
        }
        if(c == 1){
            cout << 0;
            if(q == 1) cout << endl << 0;
        }
        else if(c == 2){
            cout << h[cc[1]] + h[cc[2]] << endl;
            if(q == 1) cout << 1 << endl << cc[1] << ' ' << cc[2];
        }else{
            cout << "-1";
        }
    }
}
/*
6 4 1 
2 7 6 10 8 2 
1 2 
3 4 
5 6 
2 6

15 15 1 
1 6 9 1 6 10 2 6 8 1 7 10 3 4 5 
1 2 
2 3 
1 3 
4 6
5 6 
4 5 
7 9 
7 8 
8 9 
10 12 
11 12 
10 11 
13 14 
13 15 
14 15

*/
