#include<bits/stdc++.h>
using namespace std;

// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")

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

const int maxn = 1e5+5;
int n, m, tree[4*maxn], iddd;
vec L, R; map<int, int>id, maxR;
pii p[maxn];

void build(int v, int l, int r){
    if(l>r || l>iddd || r<1) return;
    if(l==r) tree[v] = maxR[l];
    else{
        int mid = (l+r)/2;
        build(2*v, l, mid); build(2*v+1, mid+1, r);
        tree[v] = max(tree[2*v], tree[2*v+1]);
    }
}

int que(int v, int l, int r, int L, int R){
    if(l>r || l>R || r<L) return 0;
    if(L<=l && r<=R) return tree[v];
    int mid = (l+r)/2; 
    return max(que(2*v, l, mid, L, R), que(2*v+1, mid+1, r, L, R));
}

void solve(){
    read(n);
    for(int i = 1; i <= n; i++){ read(p[i].F); read(p[i].S); }
    sort(p+1, p+n+1);
    for(int i = 1; i <= n; i++){
        L.pb(p[i].F); R.pb(p[i].S);
        if(!id[p[i].F]) id[p[i].F] = ++iddd;
        maxR[id[p[i].F]] = max(maxR[id[p[i].F]], p[i].S);
    }
    build(1, 1, n);
    read(m);
    int mx = 0, mn = 0, a, ans = 0;
    for(int _ = 1; _ <= m; _++){
        read(a);
        if(_==1) mn = mx = a;
        mx = max(mx, a); mn = min(mn, a);
        bool lanjut = 0;
        int it = lb(all(L), mn+1)-L.bg();
        int s = id[L[0]], e = id[L[it-1]];
        int tmp = que(1, 1, n, s, e); 
        if(tmp >= mx){
            lanjut = 1;
        }
        
        if(!lanjut){
            it = lb(all(L), a+1)-L.bg();
            e = id[L[it-1]];
            tmp = que(1, 1, n, s, e);
            if(tmp >= a) lanjut = 1;
            if(lanjut){
                mx = mn = a; ans++;
            }else{
                printf("-1"); exit(0);
            }
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

