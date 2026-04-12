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

const int maxn = 2e5+5;
int n, m, s, dp[maxn], a[maxn], b[maxn], p[maxn], tree[4*maxn]; 
vector<int>e[maxn]; 
bool stop;
void upd(int v, int l, int r, int i, int x){
    if(i < l || r < i) return; 
    if(l == r && r == i){
        stop = 1;
        tree[v] = x;
        return;
    }
    if(!stop){
        int mid = (l+r)>>1; 
        upd(2*v, l, mid, i, x);
        upd(2*v+1, mid+1, r, i, x);
        tree[v] = min(tree[2*v], tree[2*v+1]);
    }
}

int que(int v, int l, int r, int L, int R){
    if(l > R || r < L) return LLONG_MAX;
    if(L <= l && r <= R) return tree[v];
    int mid = (l+r)>>1;
    return min(que(2*v, l, mid, L, R), que(2*v+1, mid+1, r, L, R));
}

void solve(){
    read(n); read(m); read(s);
    for(int i = 1; i <= m; i++){
        read(a[i]); read(b[i]); read(p[i]);
        e[b[i]].pb(i);
    }
    
    for(int i = 1; i <= n; i++){
        dp[i] = dp[i-1] + s;
        for(auto j : e[i]){
            int z = que(1, 0, n, a[j]-1, i-1);
            dp[i] = min(dp[i], z+p[j]);
        } 
        stop = 0;
        upd(1, 0, n, i, dp[i]);
    }
    print(dp[n]);
}

int32_t main(){
    IO
    int t = 1; 
//    t = read();
    while(t--) solve();
}