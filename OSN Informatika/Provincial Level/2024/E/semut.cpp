#include<bits/stdc++.h>
using namespace std;
/*
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
*/
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define int ll
#define ull unsigned long long
#define db double
#define ld long double
#define pii pair<int,int>    
#define pll pair<ll, ll>
#define ppii pair<pii, int>
#define pipi pair<int, pii>
#define ppipi pair<pii, pii>
#define vec vector<int>
#define vecpii vector<pii>
#define vecpsi vector<pair<string, int>>
#define mkp make_pair
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define ins insert 
#define F first
#define S second
#define sz size
#define len length
#define ub upper_bound
#define lb lower_bound
#define bg begin
#define all(x) x.begin(),x.end()
#define pq priority_queue<int>
#define pqr priority_queue<int,vector<int>,greater<int>>
#define endl '\n'
#define debug cerr << "-> "
#define debl cerr << "===================================\n"
#define debc(i,j) cerr << i << ": " << j << endl
#define debpii(i,j,k) cerr << i << ": " << j << ' ' << k << endl
#define deblr(i,j,k) cerr << i << ',' << j << ": " << k << endl
#define debvec(v) for(int i = 0; i < v.sz(); i++) cout << i << ": " << v[i] << endl
#define debarr(a,n) for(int i = 1; i <= n; i++) cout << i << ": " << a[i] << endl

const ll MODD = 998244353;
const ll MOD = 1e9+7;
const ll INF = 1e18;
const ld PI = acos(-1.0);

int dx[8] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[8] = {0, 0, 1, -1, 1, 1, -1, -1};

void read(int &num){
    bool neg = 0; register int c; num = 0; c = getchar();
    if(c=='-'){ neg = 1; c = getchar();}
    for(;(c>47 && c<58); c = getchar()) num = num*10+c-48;
    if(neg) num *= -1;
}
void print(int x) {
    if (x < 0) putchar('-'),x-=x;
    if(x<10) putchar(x + 48);
    else print(x/10),putchar(x%10+48);
}
void print(int x, char t) {
    print(x); putchar(t);
}

/* -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
const int maxn = 1e5+5;
int n, m, k, b[maxn], ccsz, ans;
vector<int>adj[maxn], cc[maxn], g;
bool vis[maxn];

void dfs(int x){
    vis[x] = 1; cc[ccsz].pb(b[x]);
    for(auto i : adj[x]){
        if(!vis[i]) dfs(i);
    }
}

int hit(int x){
    int medL = (lb(all(g), x+1)-g.begin())-1;
    int medR = (lb(all(g), x)-g.begin());
    int L = 0, R = 0, ans = 1e18;
    if(medL != -1){
        for(auto i : cc[ccsz]) L += abs(i-g[medL]);
        ans = min(ans, L);
    }
    if(medR != m){
        for(auto i : cc[ccsz]) R += abs(i-g[medR]);
        ans = min(ans, R);
    }
    return ans;
}

void solve(){
    read(n); read(m); read(k);
    for(int i = 1; i <= n; i++) read(b[i]);
    for(int i = 1; i <= m; i++){
        int x; read(x); g.pb(x);
    }
    sort(all(g));
    while(k--){
        int u, v; read(u); read(v);
        adj[u].pb(v); adj[v].pb(u);
    }
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            ccsz++; dfs(i);
            sort(all(cc[ccsz]));
            int z = cc[ccsz].size(), minimum = 1e18;
            if(ccsz&1){
                int med = cc[ccsz][z/2];
                int p = hit(med); 
                minimum = min(minimum, p);
            }else{
                int med1 = cc[ccsz][z/2-1], med2 = cc[ccsz][z/2];
                int p = hit(med1), q = hit(med2);
                minimum = min(minimum, min(p, q));
            }
            ans += minimum;
        }
    }
    print(ans);
}

int32_t main(){
    IO
    int t = 1; 
//    t = read();
    while(t--) solve();
}

/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/* 




*/