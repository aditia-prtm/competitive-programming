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
#define knalpotresing ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
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
#define pq priority_queue<int>
#define pqr priority_queue<int,vector<int>,greater<int>>
#define debug cerr << "-> ";
#define all(x) x.begin(),x.end()
#define endl '\n'
const ll MOD = 998244353;
const ll MAX = 1e9+7;
const ll INF = 1e18;
const ld PI = acos(-1.0);

const int maxn = 5e5+10;

int n, st[4*maxn], ans[maxn];
vector<int>buang[maxn], adj[maxn];
map<pii, vector<int>>mp;
map<int, vector<int>>query;

void build(int v, int l, int r){
    if(l == r) st[v] = adj[l].size();
    else{
        int m = (l+r)/2;
        build(2*v, l, m); build(2*v+1, m+1, r);
        st[v] = st[2*v] + st[2*v+1];
    //    cout << l << '-' << r << ": " << st[v] << endl;
    }
}

void upd(int v, int l, int r, int i){
    if(l > i || r < i) return;
    if(l == r && r == i) st[v] --;
    else{
        int m = (l+r)/2;
        upd(2*v, l, m, i); upd(2*v+1, m+1, r, i);
        st[v] = st[2*v] + st[2*v+1];
    }
}

int que(int v, int l, int r, int L, int R){
    if(l > R || r < L) return 0;
    if(l >= L && r <= R) return st[v];
    int m = (l+r)/2;
    return que(2*v, l, m, L, R) + que(2*v+1, m+1, r, L, R);
}

void solve(){
    cin >> n;
    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        if(v > u) swap(u, v);
        buang[v+1].pb(u);
        adj[u].pb(v);
    }
    build(1, 1, n);
    int q; cin >> q;
    for(int i = 1; i <= q; i++){
        int l, r; cin >> l >> r;
        mp[{l, r}].pb(i);
        query[l].pb(r);
    }
    
    for(int i = 1; i <= n; i++){
        if(buang[i].size() > 0){
            for(auto j : buang[i]){
                upd(1, 1, n, j);
            }
        }
        
        if(query[i].size() > 0){
            for(auto j : query[i]){
                int l = i, r = j;
                int sum = que(1, 1, n, l, r);
                for(auto k : mp[{l, r}]){
                    ans[k] = (r-l+1) - sum;
                }
            }
        }
    }
    for(int i = 1; i <= q; i++) cout << ans[i] << endl;
}


int32_t main(){
    knalpotresing
    int t = 1;
//    cin >> t;
    while(t--) solve();
    return 0;
}
