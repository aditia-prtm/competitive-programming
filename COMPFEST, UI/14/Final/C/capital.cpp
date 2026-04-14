#include<bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#define ll long long
#define int ll
#define fpb __gcd
#define db double
#define ull unsigned long long
#define ld long double
#define skill_issue_kill_me ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
#define str string
#define pii pair<int,int>    
#define pll pair<ll, ll>
#define ipii pair<int, pii>
#define ipll pair<int, pii> 
#define ppii pair<pii, pii>
#define veci vector<int>
#define mkp make_pair
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define ins insert 
#define F first
#define S second
#define ub upper_bound
#define lb lower_bound
#define pq priority_queue
#define pqr priority_queue<int,vector<int>,greater<int>>
#define debug cerr << "-> ";
#define all(x) x.begin(),x.end()
#define endl '\n'
const ll MOD = 998244353;
const ll MAX = 1e9+7;
const ll INF = 1e18;
const ld PI = acos(-1.0);

// ----------------------------------------------------------------------------------------------------

int n, s, a, cc[2005][2005] = {0}, ans = 1e18;
veci adj[2005];
void solve(){
    cin >> n >> s >> a;
    bool sub3 = 1;
    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        if(!(u == i && v == i+1)) sub3 = 0;
        if(v < u) swap(u, v);
        adj[v].pb(u);
    }
    if(sub3){
        for(int i = 1; i <= n; i++) ans = min(ans, max(s*i, a*(n-i+1)));
        cout << ans;
        exit(0);
    }
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            if(i == 1) sort(all(adj[j]));
            int tmp = adj[j].size() - (lb(all(adj[j]), i)-adj[j].begin());
            cc[i][j] = cc[i][j-1] - tmp + 1;
            int bandara = n - j + cc[i][j] + i - 1, gedung = j-i+1;
        //    cout << i << ',' << j << ": " << gedung << ' ' << bandara << endl;
            ans = min(ans, max(bandara*a, gedung*s));
        }
    }
    cout << ans << endl;
    
}

int32_t main(){
    skill_issue_kill_me
    int t = 1;
//    cin >> t;
    while(t--) solve();
    return 0;
}

// ----------------------------------------------------------------------------------------------------

/*
5 2 4 
1 2 
2 3 
3 4 
4 5
*/
