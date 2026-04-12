#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll 
#define pub push_back
#define vec vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define ipii pair<pii, int>
#define all(v) v.begin(), v.end() 
#define lb lower_bound
#define fi first 
#define se second 
#define io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int MOD = 1e9+7;
const int INF = 1e18;

const int maxn = 1e5+10; 
int n, m, co;
vec adj[maxn], cc;
bool vis[maxn] = {0};

void subsoal(int node){
    cc.pub(node); 
    vis[node] = 1;
    for(auto i : adj[node]){
        if(!vis[i]) subsoal(i);
    }
}

void dfs(int node, int l, int r){
    if(node < l || node > r) return;
    co++; vis[node] = 1;
    for(auto i : adj[node]){
        if(!vis[i] && i >= l && i <= r) dfs(i, l, r);
    }
}
signed main(){
    cin >> n >> m;
    while(m--){
        int u, v;
        cin >> u >> v;
        adj[u].pub(v);
        adj[v].pub(u);
    }
    if(n <= 300 && m <= 600){
        int ans = 0;
            for(int l = 1; l <= n; l++){
                for(int r = l; r <= n; r++){
                int tmp = 0;
                memset(vis, 0, sizeof(vis));
                for(int i = l; i <= r; i++){
                    if(!vis[i]){
                        co = 0; dfs(i, l, r);
                        if(co <= 2) tmp += co;
                    }
                }
                ans += tmp;
            }
        }
        cout << ans;
        return 0;
    }
    bool allsepi = 1;
    vec sub6;
    memset(vis, 0, sizeof(vis));
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            cc.clear();
            subsoal(i);
            if(cc.size() > 2) allsepi = 0;
            if(cc.size() == 3){
                for(auto j : cc) sub6.pub(j);
                sort(all(sub6));
            }
        }
    }
    int ans = 0;
    if(allsepi){
        for(int i = n; i >= 1; i--){
            ans += (i*(i+1))/2;
        }
    }else{
        for(int i = 1; i <= n; i++){
            int z = n-i+1, zz = n-sub6[2]+1;
            int temp = (z*(z+1))/2;
            if(sub6[0] >= i) temp -= 3*zz;
            ans += temp;
        //    cout << i << ": " << temp << endl;
        }
    }
    cout << ans;
}