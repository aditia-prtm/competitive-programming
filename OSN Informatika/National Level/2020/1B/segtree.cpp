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
const int maxn = 2e5+5;
ll n, q, idx = 1, lg = 0, a[maxn], ans[maxn];
pll que[maxn], segtree[4*maxn];

void build(ll v, ll l, ll r){
    if(l == r)segtree[v] = {a[l], l};
    else{
        ll m = (l + r) / 2;
        build(2*v, l, m); build(2*v+1, m+1, r);
        segtree[v] = min(segtree[2*v], segtree[2*v+1]);
    }
}

pii getmin(ll v, ll l, ll r, ll x, ll y){
    if(l > y || r < x) return {1e9+7, 1e9+7};
    if(l >= x && r <= y) return segtree[v];
    ll m = (l + r) / 2;
    return min(getmin(2*v, l, m, x, y), getmin(2*v+1, m+1, r, x, y));
}

void pecah(ll l, ll r, ll k){
    if(l > r) return;
    pii p = getmin(1, 1, n, l, r);
    int mn = p.F, idm = p.S;
    while(idx <= q && que[idx].F <= lg + (mn - k) * (r - l + 1)){
        ll tmp = (que[idx].F - lg) % (r - l + 1);
        if(tmp == 0) tmp = r-l+1;
        ans[que[idx].S] = l + tmp - 1; idx++;
    }
    lg += (mn - k) * (r - l + 1);
    pecah(l, idm-1, mn); pecah(idm+1, r, mn);
}

void solve(){
    read(n);
    for(int i = 1; i <= n; i++) read(a[i]);
    build(1, 1, n);
    read(q);
    for(int i = 1; i <= q; i++){
        read(que[i].F); que[i].S = i;
    }
    sort(que + 1, que + q + 1);
    pecah(1, n, 0);
    for(int i = 1; i <= q; i++) print(ans[i], '\n');
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
