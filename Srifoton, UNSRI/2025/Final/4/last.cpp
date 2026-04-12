#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long
#define all(x) x.begin(), x.end()
#define lb lower_bound

const int INF = (1LL<<62);

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, A, B;
    if(!(cin >> n >> A >> B)) return 0;
    vector<vector<int>> g(n+1);
    for(int i=0;i<n-1;i++){
        int u,v; cin >> u >> v;
        g[u].pb(v); g[v].pb(u);
    }

    vector<int> parent(n+1, -1), order; order.reserve(n);
    stack<int> st;
    st.push(1); parent[1] = 0;
    while(!st.empty()){
        int u = st.top(); st.pop();
        order.pb(u);
        for(int v: g[u]) if(v != parent[u]){
            parent[v] = u;
            st.push(v);
        }
    }

    vector<int> dp0(n+1, 0), dp1(n+1, 0);
    for(int i = (int)order.size()-1; i>=0; --i){
        int u = order[i];
        int sumF = 0;
        int bestG = INF;
        for(int v: g[u]) if(v != parent[u]){
            int f = min(dp0[v] + 2LL*A, A + dp1[v] + B);
            sumF += f;
            int gval = -f + (A + dp1[v]);
            if(gval < bestG) bestG = gval;
        }
        dp0[u] = sumF;
        if(bestG == INF) dp1[u] = dp0[u];
        else dp1[u] = dp0[u] + min(0LL, bestG);
    }


    int ans = (1LL<<62);

    struct Item{
        int u,p; 
        int dp0up, dp1up;
    };
    
    vector<Item> stack2;
    stack2.reserve(n);
    stack2.push_back({1, 0, 0, 0}); 

    while(!stack2.empty()){
        Item it = stack2.back(); stack2.pop_back();
        int u = it.u, p = it.p;
        int dp0up = it.dp0up, dp1up = it.dp1up;

        int deg = (int)g[u].size();
        vector<int> fvals; fvals.resize(deg);
        vector<int> gvals; gvals.resize(deg);
        int sumF = 0;
        for(int idx=0; idx<deg; ++idx){
            int v = g[u][idx];
            if(v == p){
      
                int f = min(dp0up + 2LL*A, A + dp1up + B);
                int gav = -f + (A + dp1up);
                fvals[idx] = f; gvals[idx] = gav; sumF += f;
            } else {
                int f = min(dp0[v] + 2LL*A, A + dp1[v] + B);
                int gav = -f + (A + dp1[v]);
                fvals[idx] = f; gvals[idx] = gav; sumF += f;
            }
        }


        int min1 = INF, min2 = INF; int min1_idx = -1;
        for(int idx=0; idx<deg; ++idx){
            if(gvals[idx] < min1){ min2 = min1; min1 = gvals[idx]; min1_idx = idx; }
            else if(gvals[idx] < min2) { min2 = gvals[idx]; }
        }

        int dp0_total = sumF;
        int bestGAll = (min1==INF? INF : min1);
        int dp1_total = dp0_total + (bestGAll==INF? 0LL : min(0LL, bestGAll));
        ans = min(ans, dp1_total);

 
        for(int idx=0; idx<deg; ++idx){
            int v = g[u][idx];
            if(v == p) continue;
            int f_v = fvals[idx];
            int dp0_up_child = sumF - f_v;
            // min_g excluding idx
            int min_excl = INF;
            if(min1_idx == -1) min_excl = INF;
            else{
                if(min1_idx != idx) min_excl = min1;
                else min_excl = min2;
            }
            int dp1_up_child = dp0_up_child + (min_excl==INF? 0LL : min(0LL, min_excl));
            stack2.push_back({v, u, dp0_up_child, dp1_up_child});
        }
    }

    cout << ans;
}
